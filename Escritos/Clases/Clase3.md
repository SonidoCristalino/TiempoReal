# Clase nº 3

Repaso de Infomración y Comunicación y el tema que ya está subido al campus.

Cuandos se lea la hoja de configuración sólo hay que ver los Registros para confifurar el conversor

Conversión = Adquisición.

# Para la lectura de variables físicas:

Se utilizan trasductores, que son dispositivos que transforman una magnitud física tal como temperatura o presión en una magnitud
eléctrica.
Las variables físicas lo que hay que hacerles es convertir esos valores a señales eléctricas, tensión o corriente.
Esos trasductores pueden entregar o tensión o corriente (se utiliza la ley de Ohm). Todo está estandarizado, por lo que se hace
facil abordarlo.
Lo que se hace es conectarlos a un dispostivo que maneje señales digitales y analógicas y convertirlas a binario (placas
conversoras de A/D)

Trasductores (convierten una magnitud física a una magnitud eléctrica) -> se conecta a -> Placas A/D -> que transforman esa señal
eléctrica en datos binarios -> se conecta a -> una computadora

# Transductor
¿Qué es un transductor?
Un transductor define como un dispositivo fundamental en el sistema de control de medidores eléctricos. Actualmente, son muy
utilizados en los sistemas de automatización y control para registrar grandes magnitudes. Y no sólo nos estamos refiriendo a las
magnitudes más conocidas como son: temperatura y presión; también sirven para registrar caudales o concentración de gases.

¿Para qué sirve?
Este dispositivo transforma una magnitud física en una señal eléctrica. Así los medidores pueden detectar magnitudes físicas como:
presión, temperatura, humedad, entre otras. Y convertirlas en señales eléctricas cuya interpretación es importante para servicios
como pruebas no destructivas.

# Analógico y digital
Se requieren las transformadas (serie de fourier, naikyst, etc).
Señales compuestas: Fourier.
A traves de esa frecuencia, se tiene que saber cómo se tiene que muestrear para obtener una señal confiable. Es decir, pasar del
domino del tiempo al dominio de la frecuencia.

Analizar el tipo de señal eléctrica (que el trasductor hizo obteniendo para tener una señal proporcional a la señal física) y con
ello se puede tener una frecuencia que se represente esa señal que varía en el tiempo y a través de esta frecuencia se puede saber
cuántas veces se debe muestrear esa señal para emparentar esa señal física con una discreta (señal digital)

En el mundo real hay ruido, señales que complican las que estamos usando, por lo que la frecuencia de muestreo tiene que ser más
alta (y no solo el doble como dice Fourier). Con ese muestreo se consigue pasar de analógico a digital. Se encuentra una relación
de la señal analógica y traducirlos a las posibles combinaciones entre 1 y 0.

Conversor o Adquisidor (que es LO MISMO, asigna las muestras y las traduce a valores binarios)
En la transformación se pierde información.

Según el teorema de Nyquist, la frecuencia de muestreo (del convertidor) debe ser de más del doble que la banda que se pretende
utilizar.

# Adquisidor
Tiene que ver con la electrónica,toma la señal eléctrica, retiene la señal, mantenerla estable, y luego pasarla a binario.

Muestreador = conversor = adquisidor.

Cuanto mayor cantidad de bits tiene, mejor la calidad de sonido que se tiene.

	Falta parte de la clase (como 1h)

# Sensores y detector:
Un detector tiene 2 estados de salida.

Se alcanza un umbral físico que soporta el dispositivo que sensa, entonces al alcanzar ese valor, se pasa de falso a verdadero
mediante un contacto.

Un sensor(trasductor): lo que hace es dar en su salida una señal analógica eléctrica de la señal FISICA que recibió en su entrada, por eso se
trata de un trasductor.

Las salidas de los sensores están normalizadas a valores de corriente o de tensión que pueden ser: +/- 5V, -10V o 4-20 mA.

# ADQ12:
Es una placa conversora Analógica/digital de 12 bits.

Tiene entrada analógica y digital, y la salida es sólo digital.

En el minuto 33.40 explica los registros:
	- CTREG: Control Reg, es el registro de control
	- A/D: Conversor analógico a digital, el cual es un contador de 12 bits que iguala el valor de la muestra.
	- PGA: Amplificador de ganancia programable, de acuerdo al valor de CTREG.
	- S/H: (En la etapa de muestreo) permite memorizar un valor instantáneo para permitir la lectura de un valor constante.
	- OUTBR: Es un puerto de salida de 8 bits, tiene 7 salidas y habilita por ejemplo el AUTB0 la entrada de interrupción In0.
	- STINR: puerto de entrada y registro de estatus.
	- BUFFERS

El adquisidor ADQ12, se puede conectar al PIC 8253/8254 que sería la parte del segundo ejercicio.

# Velocidad de disparo:
	Es para Saber cuándo convertir. Es importante, porque tiene que ver con el resultado final de la señal.

Con el 8253/4 se puede variar la frecuencia de salida, las cuales serán más bajas que la original. Se pueden "post-escalar" esas
frecuencias.

# PACER:
Dentro de una máquina, se trabaja con varias frecuencias (es por eso que en un Mother se encuentran tantas conexiones de distintos
tamaños) y para encadenar tantas frecuencias se utiliza el PACEER.
Al tener muchas frecuencias, se necesitan diferentes tiempos, y para ello se requieren dispositivos que permitan cambiar esas
frecuencias de una manera relativamente flexibles. Esos dispositivos están integrados a la placa ADQ12.


El PACER tiene que ver con las demoras programables (en Arduino existe una función que se llama delay), que a bajo nivel el
encargado de hacer estas demoras sería el PACER.
	- Fracciona el tiempo del procesador entre diversas rutinas (multitask) y usa interrupciones.
	- Permite adquirir o generar datos mediante subrutinas que corren en background (mediante interrupciones)
	- Permite realizar mediciones de tiempo entre dos eventos.

El ADQ12 para las interrupciones permite dos alternativas:
	- Vía PACER
	- ENTRADA IN0, etc.

Minuto 44: EXPLICA EL código del ejercicio nº 2 de la práctica 1.

Minuto 1.00.00:
	Cristian le pregunta sobre el tema de la práctica nº 1:
	1) lo importante es que el código modifique la frecuencia.
	2) No es importante que se reciba un parametro, directamente es una variable incializada que se le modifica el valor.
	3) Tiene que imprimir la cantidad de veces que se invocó al manejador.

	La idea es ver Cuántas veces se ejecuta la sección de código que se programa en el manejador
		- El número más chiquito será 18 (hay unos cuantos bits que están reservados por un tema electrónico, por lo que
		  si o si hay que arrancar en 18).
		- El número más grande será 65535 (que son 16 bits)

	Al número 1193800 se divide por 10000 que da : 119,38, eso quiere decir que se va a estar interrumpiendo 119 veces por
	segundo.
	Si hacemos 1/119 = 0.008403... 0,0084 segundos o lo que significa que cada 8,4 milisegundos se estará interrumpiendo.

	O imprimimos cuando se interrumpe. Como sabemos que cada 119 veces se interrumpe, entonces cuando llega a 119, se imprime.

Ver de programar el Trabajo Final bajo:
	https://nodered.org/#features



