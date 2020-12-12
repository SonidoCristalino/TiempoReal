#include <stdio.h>
#include <htc.h>

void main() {

	//Configuracion del modulo

	//ADCS:00 -> 1 ciclo de reloj de conversion cada 2 reloj de sistema.
	ADCON0 = 0b01000001;

	//establezco ADFM:1 de conversion
	ADCON1 = 0b10001110;

	//establezco al bit 0 como entrada RA0/AN0
	TRISA = 0b00000001;

	// 0 = sin interrupciones
	ADIE = 0;

	//Configuracion de las salidas

	//Se establecen todos los bits de B como salida de los latch 74LS373
	TRISB = 0b00000000;

	//Se establecen los bits 7 y 6 de D como salida(asociados a los latch)
	TRISD = 0b00000000;

	//Inicio de la Conversion
	GO=1;

	while(1) {

		//si no no termina la conversion
		if(GO==0) {

			//obtengo el valor convertido
			unsigned short valor = ADRESH << 8 | ADRESL;

			//muestro el valor obtenido en la salida
			RD6=1;
			RD7=0;
			PORTB = (valor & 0xff);

			RD6=0;
			RD7=1;

			//Se resetea la variable para volver a empezar
			GO=1;
		}
	}

}
