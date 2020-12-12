#include <htc.h>
#define _XTAL_FREQ 1000000  //1MHz

void main() {
	//Configuracion del puerto B de 8 bits;habilita las salidas de los LED
	TRISB = 0b11001111;
	//Configuracion del puerto A de 5 bits;habilita como entradas los pulsadores
	TRISA = 0b00011;
	//enciende LED salida RB4 al comenzar el programa
	RB4 = 1;
	//enciende LED salida RB5 al comenzar el programa
	RB5 = 1;

	while (1) {

		//Se habilita el parpadeo de luces si se aprieta cualquier pulsador
		if (RA0==0 || RA1==0) {

			//Se ejecuta el parpadeo de LEDS

			//Prendo LED R3
			RB4=1;

			//Se mantiene encendido
			__delay_ms(250);

			//Se apaga LED R3
			RB4=0;
			//Se prende LED R4
			RB5=1;
			//Se mantiene R4 prendido
			__delay_ms(250);


			//Se apaga LED R4
			RB5=0;

		}
		else {
			//Se mantienen encendido los LED
			RB5=1;
			RB4=1;
		}
	}
}
