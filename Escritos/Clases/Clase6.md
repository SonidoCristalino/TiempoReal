
# Microcontroladores
	Los microcontroladores, a diferencia de los microprocesadores, es que son de propósito específico, y los segundos de
	propósito general. Es por esto que los primeros apuntan más a la parte de control, comunicaciones, sensado. Empresas de
	microcontroladores pueden ser: Atmel y Microchip.

	Un microcontrolador es un microprocesador especializado en el control de dispositivos o equipos electrónicos.

	El microcontrolador tiene un alto nivel de especialización, a diferencia del microprocesador que tiene un nivel mayor
	nivel de generalización, por lo que se tiene integrado todo en un chip.

	Como el objetivo del microcontrolador, es la especialización, esto lleva a que se integren muchos periféricos para
	soportar este tipo de nivel de especialidades: comunicaciones, control, etc.
	Los microcontroladores son de bajo costo, PERO lo que tiene es que a diferencia de los microprocesadores, estos últimos
	son más rápidos.

	Eficiencia energética, es decir, el consumo de energía es tendiendo de bajo a moderado en los MicroC.

	En los MicroC tenemos una cantidad de instrucciones mucho menores que en los MicroP.

	Tiempo de ejecución de las ejecuciones constantes, lo que permite justamente poder planificar de otra manera.

	Los MicroC se utilizan para controlar dispositivos electrónicos, en cambio los MicroP se utilizan para procesar
	información.

	Los MicroC necesitan poco componentes externos, a diferencia de los MicroP que requieren de muchos componentes más.


# Aplicaciones

	Los MicroC están más orientados a lo que es:
		- Control de motores
		- Biometría
		- Telefonía
		- Aparatos electrónicos
		- Mediciones en general
		- Procesamiento de señales
		- Automotriz
		- Juguetes y robótica.

# Arquitectura:

	Arquitectura Hardvard (no es la típica de Von Newman), la cual se destaca por el uso de memoria general, ya que se
	tiene una separada para datos y otra para programación; el código estará en un sector, mientras todo lo que es
	prexistencia, está almacenada en otro lugar.
	Esto hace que sea más rápido acceder a los datos (ya sea de código o de datos); si bien hace no tanto tiempo no había
	tanto espacio para almacenar datos, progresivamente ya fueron existiendo discos para este tipo de arquitecturas.

	Tiene un conjunto reducido de instrucciones (a diferencia de los MicroP)

	El salto de una arquitectura a otra, es que en la de Hardvard se tiene mayor control de los dispositivos electrónicos, en
	los MicroP se apunta maś al procesamiento de datos, en cambio en el MicroC está orientado al control.

	En la práctica ya no es tan palpable la diferencia entre arquitectura Von Newman y la Hardvard, dado que ya dispositivos
	que soportan ambas.

	CPU y GPU está orientado a procesamiento de datos, en cambio MicroC a control.

# Microcontroladores : Dispositivos
	- Con los microC se apunta generalmente a entradas y salidas que interactuan con el mundo exterior.
	- Se hace mucho hincapié en los protocolos de comunicaciones (necesarios para poder comunicarse con otros dispositivos del
	  mundo exterior). Esta comunicación en general es en serie (SATA3)
	- Adquisición y conversión analógica y digital.
	- Control por PWM (modulación de ancho de pulso), con lo que podemos controlar un motor,el sentido de giro de una rueda.

# Comunicación
	En la vida real, lo que se hace en vez de comprar todo un integrado que contenga un conversor mejor (que aumenta el costo
	del producto), lo que se hace es comprar el conversor por otro lado y sumarlo a la arquitectura y esto REQUIERE de tener
	una comunicación entre el dispositivo y el nuevo conversor.

	El transporte de comunicación se hace mediante un camino que tiene 4 hilos:
		Uno para entrada de datos, otro para la salida de datos, uno para la sincronización y otro para elegir qué
		dispositivo comunicar.

	Características generales de estos protocolos de comunicación:
		- Comunicación sincrónica full-duplex, es decir que puede enviar y recibir
		- Lo anterior hace que la transmisión y recepción de datos sea más pequeña (el payload, la carga útil es más
		  pequeña), de 1 a 2 bits. Pero que está bien porque los dispositivos del mundo exterior no son tan veloces por lo
		  que alcanza con esta tasa de transferencia.

	[Esquema de conexión en la filmina]

	## I²C
		- Se utiliza usualmente para conectar dispositivos que sirvan como memoria. Popular porque se requería poco para
		  comunicar dispositivos, básicamente 2 cables: uno de transmisión y recepción y el otro de sincronización. El
		  problema de tener tan pocos recursos es que no se tiene una comunicación full duplex, sino que o se puede
		  transmitir o recibir (half duplex).

		- Se tiene igualmente la mismas características que los otros protocolos, por lo que los modos Escalvo y Maestro
		  siguen teniendo detección de colisión.

		- Se tiene poca velocidad de transferencia, se pasa de los megas a los kilohertz.

		- En la filmina se puede apreciar que sólo se tiene 1 bit reservado para la carga útil, y todo lo demás, está
		  destinado a los metadatos necesarios para poder establecer la comunicación y que el dato llegue a destino.

	## CAN
		- Protocolo de comunicación orientado al mensaje. El mensaje pasa por toda la red y cada dispositivo conectado
		  filtra lo que le pertenece.
		- Diseñado para entornos ruidosos.
		- Velocidades de transferencia de megas.

		- El dispositivo debe de tener no sólo el Controlador CAN sino también el "Transreceiver" (transmission y
		  reception) para conectarse a la linea.

# Temporizadores:
	Dispositivos que son utilizados para poder contar, tanto sea eventos como tiempo.
	Para poder contar tiempos largos, se combinan con:
		- Otros contadores
		- Con divisores de frecuencias:
		  	* Prescaler: cuando está como entrada del contador.
			* PostScaler: cuando estácomo salida del contador.

	Vienen con una pastilla de cuarzo como para poder generar su propio sincronismo.

## Comparadores

	Permite obtener datos del exterior y comparar valores analógicos a través de 2 pines de entrada.
	Puede generar una acción sobre el pin de salida:
		- Cambiar de estado
		- Generar un pulso
		- Generar un tren de pulsos

	Importante: TIENE la capacidad de INTERRUMPIR

## Capturadores de Entrada:
	- Permite detectar un cambio en el pin de entrada.
	- Cuando registra el evento almacena el valor de un temporizador en un registro.
	- Útil para medir frecuencias.
	- Tiene capacidad de interrumpir.

## Conversor Analógico Digital
	- Permiten convertir un valor analógico en uno digital.
	- Tienen la capacidad de interrumpir cuando finalizan la conversión.
	- Tiene la posibilidad de tener muchos canales y por lo tanto un multiplexor que permite saber para qué canal está
	  muestreando.

## Codificadores de Cuadratura
	Utilizan la característica de la interferencia, utilizado en espectrometría, sensando patrones de luz, conocer la posición
	de un cuerpo.

	Se utilizaban en las ruedas del mouse para saber cuándo cambiar la orientación de la rueda, dependiendo de cómo cambiaba
	la fase, era que la rueda se estaba moviendo para un lado o para el otro.


# Microcontrolador Microchip PIC
	Populares por tener muchas herramientas para desarrollo, y porque se consiguen a bajo costo y con facilidad.

	Arquitectura Hardvard
	Nucleo RISC
	35 instrucciones

	Se utiliza paginado de memoria, que acá se llama bancos. Estos bancos son de proposito general o especial.
		*ESPECIAL*:
			- Asociados al estado y control de dispositivos.
			- Reciben nombres según su función
			- En general se ubican en las posiciones iniciales.
		*GENERAL*
			- RAM normal, se ubican después de los de propósito especial.

	Memoria EEPROM:
		- Memoria de tipo Flash, usada hasta 256 bytes.
		- No es accesible directamente, se utilizan registros de funciones especiales.
		  	* Dirección posición que se quiere acceder.
			* Datos: registro donde se lee/escribe el valor
	Genera interrupción al finalizar la operación

	Todos los pines son de entrada, excepto el 0 que es de salida
		TRISB
		TRISA
