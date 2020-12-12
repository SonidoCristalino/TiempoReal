#include <htc.h>

#define _XTAL_FREQ 1000000 //1Mhz

void interrupt timer(void) {

	// Invierte bits, necesario para encender y apagar los LEDS
	PORTB = PORTB ^ 0b00110000;

	//El timer cuenta de 12 a 256
	TMR0 = 12;

	//Flag de estado de interrupción por desborde del Timer0
	T0IF = 0;
}

void main () {

	//Config las salidas de los LED
	TRISB = 0b11001111;

	//Config las entradas los pulsadores
	TRISA = 0b00011;

	//Enciende los LED al comenzar el programa
	RB5 = 1;
	RB4 = 1;

	PSA = 0; //bit del prescaler

	OPTION_REG = (OPTION_REG & 0b01111110) | 0b111;

	T0CS = 0; // bit de seleccion de clock

	//Registro de control de interrupciones
	INTCON = 0b10100000;

	//Desactivo las Interrupciones
	GIE = 0;

	while (1) {

		//si cualquiera de los pulsadores estan activos
		if (RA0==0 || RA1==0) {
			//se activa la interrupcion
			GIE = 1;
		} else {
			//dejo los LED encendidos
			RB5=1;
			RB4=1;
		}
	}
}
