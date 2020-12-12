#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

#define LOW_BYTE(n) (n & 0x00ff)
#define HIGH_BYTE(n) ((n>>8)&0x00ff)

/* Se la declara como unsigned log ya que solo
   podra tomar valores entre 0 y 65535 */
unsigned long int frecteclado = 0;

/* Se declaran variables que se utilizaran para realizar
   el conteo de interrupciones en 20 segundos*/
int x=0;
int cont=0;
int flag=0;
int y=0;

void interrupt (*restablecedor) (); //se retorna el vector
void SetFrecuencia(int TeclFrec, int *contViejo, int *contViejo2);

/*Se crea la funcion que se encarga de instalar el manejador
  de interrupciones y modificar la frecuencia del mismo*/
void SetFrecuencia(int TeclFrec,int *contViejo, int *contViejo2) {

    /* La frecuencia base del interruptor es 1.193 MHz*/
    long int frec=1193180;

    /* Modificar la frecuencia del temporizador */
    frec = frec / TeclFrec;

    /* Escribe el byte del control de palabras */
    outportb(0x43,0x36);

    /* Se guarda la parte baja del contador viejo */
    *contViejo = inportb(0x40);

    /* Se guarda la parte alta del contador viejo */
    *contViejo2 = inportb(0x40);

    /* Se escribe el nuevo contador bajo  */
    outportb(0x40,LOW_BYTE(frec));

    /* Se escribe el nuevo contador alto */
    outportb(0x40,HIGH_BYTE(frec));
    clrscr();

}

// Así es como se declara el manejador en C.
void interrupt mimanejador() {
    flag=1;
}

/* Funcion principal */
void main(void) {

    int contViejo, contViejo2;
    printf("Ingrese divisor de frecuencia deseada entre 19 y 65535: ");
    scanf("%d", &frecteclado);

    if (frecteclado >= 19 && frecteclado <= 65535){

	 SetFrecuencia(frecteclado,&contViejo, &contViejo2);

    } else {

	printf("Ingrese nuevamente la frecuencia entre 19 y 65535: ");
	scanf("%d", &frecteclado);

	if (frecteclado >= 19 && frecteclado <= 65535){

		 SetFrecuencia(frecteclado,&contViejo, &contViejo2);

	} else {

	 	printf("INCREIBLE, pero le erro dos veces \n");
	 	printf("Presione cualquier tecla para finalizar");
	 	getch();
	 	exit(0);
	}
    }

    /* Se salva el estado del manejador antes de la modificacion. Es para que sepa desde
    dónde retomar cuando acabe la interrupción */
    restablecedor=getvect(0x1C);

    /* Para instalar el manjeador en el lugar del vector 0x62 (en hexadecimal) */
    setvect(0x1C,mimanejador);

    /* La variable cont seran los segundos que se ejecute el programa */
    while ( cont<20 ) {

	/* Cada flag = 1 sera un segundo */
	if (flag==1) {
		y++;
		x++;
		flag=0;

		/* Se escribe la cantidad de interrupciones por segundo*/
		printf("Interrupcion: %d\n",y);

		/* Se cuenta la cantidad de segundos transcurridos
		   por cada bloque de iterrupciones*/
		if (y==frecteclado) {
			y=0;
			cont++;
			printf("Segundo: %d\n", cont);
		}
	 }

    }

    printf("\n");
    printf("Cantidad de segundos en total: %d\n",cont);
    printf("Cantidad de interrupciones totales: %d\n",x);

    /* Antes de terminar el programa, se restaurar
      el estado origina del manejador */
    setvect(0x1C,restablecedor);

    /* Se restauran los contadores*/
    outportb(0x40,contViejo);
    outportb(0x40,contViejo2);

    printf("Presione cualquier tecla para finalizar");
    getch();
}
