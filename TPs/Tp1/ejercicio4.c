#include <dos.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>
#include <conio.h>

/*Defino para los contadores del temporizador*/
#define LOW_BYTE(n) (n & 0x00ff)
#define HIGH_BYTE(n) ((n>>8)&0x00ff)

/*Variables para dibujar*/
int xa,xn,ya,yn,k=0;
int flag=0,cont=0, y=0;
unsigned char A, B, C;
float VA;

/*Registros de la placa ADQ12*/
unsigned int DIRBAS, OUTBR, STINR, CTREG, ADHIG, ADLOW, VD;

/*Se crea un restablecedor para poner los valores como
  estaban en un principio del interruptor*/
void interrupt (*restablecedor) ();

void SetFrecuencia(int TeclFrec, int *contViejo, int *contViejo2);

/*Se crea la funcion que se encarga de instalar el manejador
  de interrupciones y modificar la frecuencia del mismo*/

void SetFrecuencia(int TeclFrec,int *contViejo, int *contViejo2)
{
    long int frec=1193180; /* La frecuencia base del interruptor es 1.193 MHz*/

    /* Modificar la frecuencia del temporizador */
    frec = frec / TeclFrec;

    /* Escribe el byte del control de palabras */
    outportb(0x43,0x36);

    /* Se guarda la parte baja del contador viejo */
    *contViejo = inportb(0x40);

    /* Se guarda la parte alta del contador viejo */
    *contViejo2 = inportb(0x40);

    /* Se escribe el nuevo contador bajo */
    outportb(0x40,LOW_BYTE(frec));

    /*Se escribe el nuevo contador alto */
    outportb(0x40,HIGH_BYTE(frec));
    clrscr();
}

/*Defino mi manejador para controlar las interrupciones*/
void interrupt mimanejador()
{
    flag=1;
}


/*Prototipos de las funciones*/
void calculartemp(void);
void grafico(void);

/*Calculamos la temperatura*/
void calculartemp(){

	/*Inicia la conversion en parte baja AD */
	C = inportb (ADLOW);

	/*Espera la senial del bit 5(EOC) en 1 del STINR
	que indica el fin de la conversion*/
	do {
		C = inportb (STINR);

		/* En la variable C carga el bit EOC */
		C = C && 0x20;

	}while (C == 0x0); /* Continua leyendo hasta que EOC = 1*/

	/* Una vez finalizada la conversion,
	retoma la lectura del valor convertido
	de 12 bits 4 en high y 8 en low*/
	A = inportb (ADHIG);
	B = inportb (ADLOW);
	/* Conforma un nro de 12 bits.*/
	VD = A * 256 + B;

	/*Pasamos VD a voltios.*/
	VA = (float) 5 / 4096 * VD;
	/*printf ("\n \n%1.3f Voltios \n \n \n", VA);*/
}


/*Funcion para graficar*/
void grafico(){

   char ey,ex;
   int i,j;
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "..\\BGI");

   setlinestyle(SOLID_LINE,0,2);

   line(100,460,100,60);
   line(100,460,600,460);
   line(90,70,100,60);
   line(110,70,100,60);
   line(590,450,600,460);
   line(590,470,600,460);

   outtextxy(85,35,"VOLTAJE/TEMPERATURA");
   outtextxy(613,452,"SEGUNDOS");

   setlinestyle(DOTTED_LINE,0,2);

   for(i=460,j=0;i>=60;i-=80,j++){
	line(100,i,600,i);
	itoa(j,&ey,10);
	outtextxy(85,i-5,&ey);
   }

   for(i=100;i<=600;i+=25){
	line(i,460,i,60);
	itoa(k,&ex,10);
	outtextxy(i,465,&ex);
	k++;
   }

   setcolor(RED);
   setlinestyle(CENTER_LINE,0,2);
}


void main(void){

	/* variables necesarias para los contadores del SetFrecuencia*/
	int contViejo, contViejo2;

	//Direccion base del ADQ12
	DIRBAS = 0x300;

	//Port de salida de 8 bits
	OUTBR = DIRBAS + 4;

	//Port de entrada 5 bits + reg status
	STINR = DIRBAS + 0;

	//Reg control funciones programables
	CTREG = DIRBAS + 0;

	//Conversor analogico-parte alta
	ADHIG = DIRBAS + 9;

	//Conversor analogico-parte baja
	ADLOW = DIRBAS + 8;

	/* Se setea la frecuencia para el temporizador*/
	SetFrecuencia(19,&contViejo, &contViejo2);

	/* Se salva el estado del manejador antes de la modificacion */
	restablecedor=getvect(0x1C);

	/* Se coloca el nuevo estado */
	setvect(0x1C,mimanejador);

	/* Selecciona: canal 1, FE: +5V*/
	outportb (CTREG,0);

	/*escribe el byte en el port CTREG el byte 0,
	seleccion de canal analogico bit 0 a 2 (diferencial)
	seleccion de canal analogico bit 0 a 3 (desbalanceado)*/

	calculartemp();
	grafico();

	/*inicio grafico*/
	xa=100;
	ya=(int)(-80*VA)+460;

	/*el programa se reproduce en 40 segundos, pasados los 40 segundos
	  se cierra, puede ser cualquier cantidad de segundos
	  que acepte el temporizador*/

	while ( cont<40 ){
	if(flag==1){/*Si cumplo un segundo*/

		y++; //incremento el tiempo en el que se reproduce la linea
		calculartemp();/*Calculo VA*/

		/*Se controla que la linea roja no pase la pantalla, una vez que pasa la pantalla se refrezca nuevamente el grafico*/
		if(xa==600){
			clearviewport();
			xa=100;
			grafico();
			}
	/*Se controla que cada cierto tiempo se dibuje la linea roja sobre el grafico*/
		if (y==19){
			y=0;
			cont++;
			xn=xa+25;
			yn=(int)(-80*VA)+460;
			line(xa,ya,xn,yn);
			xa=xn;
			ya=yn;
			}
		if(VA>3.54){//si la temperatura es mayor a 85 grados se prende la salida digital 0
			outportb(OUTBR, 0x08);
		}
		else{
			outportb(OUTBR, 0x00);
			//si no, se apaga
		}
		if(VA>2.71){//si la temperatura es mayor a 65 grados se prende la salida digital 1
			outportb(OUTBR, 0x09);
		}else{
			outportb(OUTBR, 0x01);
			//si no, apago el bit 1
		}
		flag=0;

		}
	}

	/*Restablezco Timer original*/
	setvect(0x1C,restablecedor);

	/*se restauran los contadores*/
	outportb(0x40,contViejo);
	outportb(0x40,contViejo2);

	closegraph();
	printf("presione una tecla para salir");
	getch();
	exit(0);

}
