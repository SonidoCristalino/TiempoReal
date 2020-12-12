# Nº de Clase: 2

Descargar lo que haya en el Campus

# Tema
	Interrupciones

Es una tarea, código que originalmente no estaba contemplado en el programa principal. Ejecutar ese código, hace que se tenga que
guardar el contexto de la tarea previa,atender la interrupción y volver con la tarea que se estaba ejecutando previamente,
restaurando el contexto.

Son señales enviadas al microprocesador que causan la suspensión temporaria de lo que están haciendo para realizar otras tareas
que requieren atención inmediata. Algunas interrupciones pueden ser tan simples como captura de teclas o apertura de archivos.

Permiten que nuestra máquina se comuniquen con el mundo exterior.

Cuando las interrupciones suceden, quieren ejecutarse (son acciones que no estaban contenidas en el programa principal). Hay que
atender ese código. Intel fue el que instauró el mecanismo:
	- Asincrónicas (las verdaderas interrupciones)
	- Sincrónicas (denominadas Excepciones)

Se debe Guardar el contexto cuando se atiende una interrupción. Como primera instancia se guarda una dirección de Retorno al
programa principal, y una vez que se sale del main, para volver al programa principal, se devuelve ese estado previo del flag. Son
denominadas como banderas, o flagas, se puede hacer de forma automática o no, dependiendo de la robustes.
	- Interrupción (guarda las banderas) NO es una subrutina (esta no guardan las banderas)
	- Si o si se tiene que guardar la dirección de retorno
	- Intel permite deshabilitar las interrupciones enmascarables.
	- Hay otras que no pueden ser deshabilitadas (la no enmascaradas).
	- Las banderas se guardan cuando es una interrupción, en caso de que sea una subrutina NO.

Kernel Control Path,es el mecanismo por el cual se salva todo el contexto cuando se realiza una interrupción, en una pila que se
denomina Kernel Mode Stack.

Las computadoras son sincrónicas, y ese sincronismo está determinado por una frecuencia que emite el clock de la computadora, sin
ello no se podrían desatar todos los mecanismos, en los que de forma colaborativa, ejecutan todos esos dispositivos: buses,
bloques de memoria, discos, registros, etc.

# ¿Qué ejemplos se pueden tener en estos?
Clock de la computadora, sin eso no podría llegar a desatar todos los dispositivos se puedan entender. El clock es un pulso, llega
a un oscilador para poder manejarse con esa frecuencia. Es por ello que apareció un chip, que permitió escalar la frecuencia y
utilizar el clcok dependiendo de la velocidad. Soportan diferentes frecuencias. Es por ello que las interrupciones son muy
vitales.

El clock no sólo es un piezo eléctrico, sino que también es un oscilador, que le permite a la computadora trabajar con esa
frecuencia, con ese reloj. Hace unos años apareció un hardware que permitía escalar esta frecuencia, es decir que permitía
modificarla para poder trabajar con estas señales modificadas, que están basadas en la velocidad, es decir, se sabe que una
impresora tiene una velocidad y que ejecutar un código tiene otra velocidad distinta, y ambas trabajan con el mismo clock.
Es por esto que trabajar con distintos flujos de bits o ancho de banda, hace que la arquitectura tenga que estar pensada para
trabajar con distintas frecuencias.
Es por eso que las interrupciones son tan necesarias, para poder interrumpir estas tareas y poder ejecutar lo que requiere el
usuario final.

Las Interrupciones pueden ser enmascarables o no
Mecanismo de manejo de interrupción se denomina kernel control path (salva el contexto en una pila).

PIC (Es un integrado) es un controlador de interrupciones que tiene una cantidad alta de registros para poder atender las
excepciones. PIC de acuerdo al dispositivo que tenga que atender va a comunicarse con la CPU que atiende a una interrupción por
vez, el PIC ORGANIZA las interrupciones; permite vectorizar (darle una dirección de memoria) las interrupciones, cuyo vector se
pone en la memoria. Luego la rutina de manejo de interrupciones puede dirigirse a la dirección de memoria para saber qué ejecutar
con las interrupciones.

En la filmina se pueden ver las interrupciones en el lado izquierdo del PIC, las cuales son programadas para que ante un estímulo
del mundo exterior (puede ser el movimiento de un mouse, el pulsado de una tecla, etc) produzca una irrupción en el CPU.
Estas interrupciones hace que el PIC se ponga en acción, dado que tiene registros que pueden ser configurados y que estos va a
comunicarse con la CPU, la cual va a poder atender a CADA UNO POR VEZ. Es por eso que se requiere el integrado PIC , para poder
organizar las interrupciones que provienen desde el mundo exterior.

Otro fin que tiene PIC, es vectorizar las rutinas o los códigos del manejo de interrupción, es decir basicamente darle una
dirección a cada código que atiende cada una de las interrupciones que se presentan ante PIC.
Esto se hace mediante una tabla de vectores, que está en memoria principal (ver que la comunicación entre PIC mediante el BUS de
datos siempre es fluida, ya que todo el tiempo se está amparando en la Memoria).
PIC lo que hace es que a la hora de recibir una interrupción, busca la dirección del tipo de interrupción que se le presenta, y
una vez obtenida,con ella podrá acceder a la parte de la memoria que tendrá la rutina que debe ejecutar.

# Lo que se requiere:
Lo que hace es guardar la dirección de retorno, las banderas y habrá que configurar el PIC ¿por qué? Porque lo que se necesita es
obtener el código del manejador de interrupciones, una función, una tarea (que algunas veces va a guardar las banderas y en otros
casos no).

Lo que se necesita es llegar al manejador de interrupciones, que es el que ejecuta una tarea, necesario para poder atender las
interrupciones. Se guarda por medio del hardware, pero se puede hablar de interrupciones a nivel de BIOS, a memoria principal, a
placa de video, etc. Nosotros nos interesa sólo de un integrado, que está implementada todavía hoy en día.

Tiene 3 registros :
	- Registro de Requerimiento: Indica la interrupción que quiere ser atendida.
	- Servicio: indicar qué interrupción es la que está siendo atendida o la que se está ejecutando.
	- Máscara de interrupción IMR: ver si está habilitado o enmascarada (habilitar o desabilitar) esa interripción. Indica qué
	  interrupción está habilitada para ser atendida y las que no están listas para usarse.

Los registros que podemos escribir, las tareas, son las de aquellas interrupciones que nos permiten habilitar o deshabilitar.

*NOTA*: Enmascarado es habilitar o desabilitar. Cuando está desenmascarada está habilitado y cuando está enmascarado entonces
deshabilitado

¿Cómo se puede enmascarar o desenmascarar? Poniendo en 0 o en 1 el bit que permite la interrupción.

Se configura en C el PIC. Se utilizan algunas instrucciones como outportb (para escribir, enviar la información a un registro) o
inportb (para leer la información de un registro)

# Interrupciones software
Hardware es más rápido pero no tan flexible como el software.

Hay cosas que se puede planificar y se utilizan esas interrupciones, pero es raro, porque se PLANIFICAN esas interrupciones,
cuando hay esa contradicción, se dice que son en software.

Dado una interrupción de cierto tipo, se guarda la dirección de retorno, pila, se va a la tabla de vectores, para enontrar el
vector determinado y de ahí se llega a la tabla del manejador de interrupciones. Así funciona tanto por software como por
hardware.

El manejador tiene que ser MUY chico.

El procedimiento es algo así:
	- Un estímulo externo causa una interrupción que debe ser tenida en cuenta previamente (por ejemplo la Int 21H)
	- Esto produce que se guarden todas las banderas y variables de entorno
	- Se va a una tabla de vectores para encontrar el vector asociado al INT 21H,
	- Al obtenerse la dirección asociada, se puede acceder a la tarea o código de la interrupción
	- Se ejecuta la interrupción.
	- Luego de haberse ejecutado la interrupción, se vuelven a restaurar las direcciones de retorno y las variables globales
	  desde la pila.
	- Se continúa con la ejecución del paso uno.

Minuto 28.55
# Tabla de Vectores

La descripción de los vectores es para saber qué prioridad tiene o hacia dónde apunte, la BIOS, etc

Se pueden definir 256 entradas.

Se tienen 3 tipos de descriptores:
	- Task gate
	- Interrupt gate (interrupciones)
	- Trap Gate (excepciones)

Se reservan memoria para determinados errores (cerca de las de softwarea). Se debe subir el nivel de abstracción y no centramos en
el nivel operativo.

Cuando la interrupción se presenta y se le informa al procesador, el procesador detiene la ejecución actual y ejecuta el código
correspondiente de atención de interrupciones. Esto genera un kernel control path. Los registros de ejecución son salvados en el
Kernel Mode Stack del proceso interrumpido (se desarrolla más arriba).

Las interrupciones tiene que satisfacer:
	- Deben ser atendidas de forma rápida
	- Toda tarea que no sea necesaria se debe diferir en otra tarea aparte para otro momento (diferenciar qué es lo crítico y
	  lo que se puede dejar para otro momento).
	- Deben ejecutar todo lo que sea posible, con las interrupciones habilitadas (por si llega a caer otra interrupción)
	- Interrupciones NO debe haber anidamiento (no es recomendable).

Organizar el manejador de interrupciones (Saber lo que es lo crítico y lo que se puede dejar para otro momento)

# Excepciones
No son interrupciones. Las excepciones son generadas por:
	- Errores en la programación (división por cero por ejemplo). Si son errores de programación, se le envía una señal al
	  proceso que la generó para que pueda capturar la señal. De lo contrario se ejecuta el manejador que le da fin a su
	  ejecución.

	- Por condiciones anómalas (algún fallo de página). En este caso el núcleo deberá reestablecer la condición para continuar
	  la ejecución.

Se produce en fallo de página por ejemplo cuando se tienen muchas aplicaciones y se tienen que solapar la memoria (hay una tabla
con todos los ejemplos de las excepciones). El manejador de excepciones es muy simiar al manejadro de interrupciones.

El código debe ser limitado, como el de las interrupciones. Hay un ejemplo de interrupción con lo que sucede con el teclado.

Las interrupciones hay que hablitarlas si o no. Cuando se habla de inhabilitar se refiere a no tener diponibles esas
interrupciones para poder  configurar mediante los vectores que se irán a implementar. Una vez que se tengan configurados entonces
se habilitan para que el procesador sepa a dónde tiene que ir a buscar una X interrupcion.

En el código hay que poner la deshabilitación de interrupciones, porque al generar una interrupción, lo más aconsejable es que no
se interrumpa el código mientras se está ejecutando la interrupción con otra interrupción entrante.

Es costoso deshabilitar las interrupcioens porque se entra en una región crítica. Las prioridades son escenciales para este tipo
de problemas.

# Bottom Halves
El grano de interrrupción permite hacerlo más chico, para que el procesador se pueda achicar.

En linux 3 formas de ejecutar el bottom half
	- Softirqs: son más dificil de programar, pero son altamente rápido y escalables. Exige modificar el kernel.
	- Tasklets: Tienen una escalabilidad limitada y se utilizan desde los módulos del kernel, no exige modificar el kernel.
	- Work queues: Se puede de forma sencilla de programar, pero el rendimiento en la velocidad es más bajo. Se ejecutan en el
	  contexto de un proceso.

# Softirqs
Interrupción de dispositivos, desde SO a drivers, reservado a la iniciailización de una máquina, inicia: disco, buses, red, reloj,
etc. Para que la máquina tenga señales de vida y se ponga en funcionamiento.
Ejecuta una a la vez el procesador.
No pueden bloquearse entre si, prioridad muy alta.
Planificación Estática, no puede cambiar, es casi de fábrica. Se puede cambiar, pero hay que ser muy CUIDADOSO.

# Tasklets
Son dinámicas, en tiempo de ejecución se puede cambiar.
Está apuntado a lugares menos críticas de la computadora. Como por ejemplo: escanner, impresora,etc
Se pueden crear o destruir a diferencia de las Softirqs.
Las plug and Play tiene que ver con esto.

# Work Queues
Es más parecido al manejo de threths, están apuntados a cosas muchísimo menos críticas, relacionado más al software que al
hardware.
Es la parte de las interrupciones menos críticas.

# Medir tiempo en una máquina
Se muestrea de la misma forma que en los años 70. Se miden con pulsos. Se necesita un sincronismo mediante un reloj, por ejemplo
en internet.
Esa sincronización está dado con uno de los relojes que está formado por un cristal de cuarzo, cuando se lo excita se le da
energía, genera una señal, con una frecuencia fija, eso depende del tamaño de la piedra, cómo es cortado, etc. Pero se puede hacer
algo preciso, por lo tanto hay cierta diferencia entre máquinas.

Como se debe utilizar esa frecuencia, se puede escalar, con el chip P8253 o P8254, que trabaja con esa frecuencia base y de
acuerdo con su programación la puede modificar.
Al variar la frecuencia entonces se pueden observar que se pueden ejecutar distintas cosas.

De 4 maneras:
	- Chip timer:
	- Reloj de tiempo real
	- Registro TSC
	- Hpet

Se tienen canales para asignar la entrada de la frecuencia, y se tienen salidas para poder tratarla. Soporta sólo 16 bits que
puede tener como mucho 65535 que es el número más grande que se puede tener para dividir los 1193800 pulsos por segundo. Por lo
tanto la frecuencia más baja es de 18.2. Se puede interrumpir CADA 18 INTERRUPCIONES POR SEGUNDO.

A medida que se modifica el divisor de frecuencia, permite que se tengan distintaas frecuencias (se puede dividir por algo más
chico o más grande) y ello cambia la cantidad de veces que se puede interrumpir por segundo al procesador.
El chip se debe modificar mediante registros, mediante los cuales se permite modificar la frecuencia.

Todo lo que antecede a la parte de *Registros TSC* en la filmina va TODO. Hay que saberla o estudiarla.

Lo que hace basicamente el integrado PIC, es contar. Al setearle la frecuencia, cuenta según la frecuencia que se le seteo y por
lo tanto, cada X cantidad de tiempo (dentro de un segundo, y recordar que no puede ser más que 18 veces por segundo) realiza una
interrupción.

# Práctica
	Para ver bien lo que se hace en el ejercicio nº 2 para PIC,ver el video nº 2 en 1.45:25
Al descomprimir se tiene:
	- 4 carpetas
	- 1 Word: Explica cómo fue desarrollado el emulador.

Se ejecuta el ejecutable BOCHE:
	 - Aparece la terminal de windows.

# Para ejecutar BorlandC:
	   Lo que hace es simular un sistema con los tiempos reales. El emulador respeta el tiempo del reloj, el simulador permite
	   modificarse.

	- Poner 6 para simulación (o Enter que es la opción por defecto).
	- Se puede trabajar también con el adquisidor (para la segunda parte de la práctica).
	- Se hace con un DIR y se tiene toda una lista de directorios.
	- Se debe labura con Borland. Se tiene que ir a BorlandC.
	- Se ejecuta el IDE de BorlandC, se entra a la carpeta BIN.
	- Se ejecuta el 'bc' -> Enter
		En resumen:
		BorlandC->Bin->bc

		* Se mueve con las teclas (sin mouse).
		* Con Tab también se mueve.
		* Con F10 se va al menú

	- File->Open->(con Tab se mueve hasta ..\) Enter ->Examples ->Hello.c ->F10->Run
		- Si se quiere que se quede lo que se imprime
			window->Ouput
			F10 se vuelve al menú

# EditDisck:
	Sirve para poder interactuar entre el IDE con la imagen de disco (el archivo C que en la misma carpeta del ejecutable de
	BOCHE).

	Aparece una carpeta en la imagen del disco del emulador.
		- Se va a Practica 1->C (que es la imagen de disco)
		- Aparece el formato del disco: VMWare Disc
		- Se accede a todos los datos del emulador
		- Vamos a Examples->Hello.c
			Una vez allí le hacemos doble click y podemos abrir el archivo con algún otro editor.

# Instaladores
Por si se tiene ganas de instalar BorlandC en la máquina.

# GUI
Es un emulador de un adquisidor (está explicado un archivo de ahí) Se explica en la Clase nº 3.
Sirve para poder modificar el dato que se está muestreando.

# Práctica:
Las prácticas no deben presentarse en informes. El profesor las va "visando", es decir, viendo a medida que van pasando las
clases. Todo una mentira, la idea es que vaya saliendo en un informe me parece mejor, así después queda todo presentado en un PDF.
Se puede atrasar en la práctica.

Ejercicio 1)
	Hay que buscar información sobre P8254 y el otro.
	Esto es sólo para el análisis del integrado. De esto NO se pregunta.

	Ver la página: http://galia.fc.uaslp.mx/~cantocar/ARQUI_COM_II/LIBRO%20IBM-PC/1203.htm

Ejercicio 2)
	Se entrega.
	Se debe hacer un recibir por parámetro (no lo hagan y poner una variable) y mostrar por pantalla la cantidad de veces que
	se invocó el manejador.
	Hay un ejemplo en: https://campus.unaj.edu.ar/pluginfile.php/287829/mod_resource/content/1/ejemplo.c

	A los 20 segundos se debe finalizar el proceso.

	Hay que buscar en la wikipedia los bits del datasheet, es por eso que se utiliza el INTR 0X1C.
		0X1C = es como se denomina de forma hexadecimal. Hay que buscar eso.

	¿Se puede debuguear?

