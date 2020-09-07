
# Clase nº 1
Todo la parte de organización está dentro del Campus.

- 3 o 4 prácticas
- 1 parcial (se tocan los 3 primeras prácitcas) con su recuperatorio (se toma las 4 prácticas).
- Se accede al parcial aprobarndo las 3 primeras prácticas.
- Se tiene que hacer un Trabajo Final integrador (está en la filmina).
	Sistemas Embebidos (es lo único que el profesor no puede dar mucha ayuda).

Bibliografía es poca.

Tiempo real: es un sistema que tiene que reaccionar a estímulos del ambiente dento de intervalos marcados por el ambiente. No sólo
está acotado a software, sino también puede ser neumático, mecánico, etc.
Se necesita un monitoreo, control, diferentes tipos de software.
Es importante el tiempo en todo este sistema.
Debe haber tolerancia a fallas.
Todos estos sistemas deben elaborarse teniendo en cuenta la concurrencia.

No es verdad que si es rápido, es de tiempo real. Si se tienen bien delimitados los requisitos temporales y los del entorno,
entonces se pueden abordar los sistemas de Tiempo Real.

Se utilizan otros protocolos que los de internet: sólo para TIEMPO REAL

Reqerumientos de TR:
	- Se necesita conocer el tiempo de procesamiento
	- Se necesita conocer los requerimientos de tiempo
	- QUé velocidad va a tardar en reaccionar el dispositivo.
	- ...

Clasificación de los sistemas de Tiempo Real: El tiempo en algunos es crítico, en otros no tantos, y otros algo mixto.
	- Se pueden clasificar como Soft (lo que pueden demorar, la videoconferencia que puede pixelarse la imagen, etc), Hard (el
	  tiempo es crítico, un avión por ejemplo, ahí las cosas no pueden fallar) y el híbrido.
	- Comunicaciones: protcoloso TCP/IP, pero hay más, se tienen sistemas de TR, comunicaciones para TR, y las que son
	  inalámbricas y no. Con diferentes tipos de arbitraje (puede haber pérdidas de mensajes, retrasmisción, etc). En TR, NO
	  SE PUEDEN perder mensjaes, porl o que los protocolos son distintos.
	- Correctitud: tiene que ver con lo anterior, se prefeiere que se cumplan los tiempos antes de perder este tiempo por
	  tener una lógica correcta. Lo primordial es el tiempo
	- Tolerancia a fallas: se implementan reduncancias para que al fallar uno de los componentes, no falle todo el sistema.
	  Por ejemplo se tienen dos o trs sensores y no uno, (con los discos de estado sólido, que son realmente de 3TB y no de
	  1, y esto es porque falla mucho).
	- Facilidades para SRT:
	  	* Sistemas operativos
		* Lenguajes
		* Metodologías

Un STR es un sistema informático que cumple
	- Interacciona repetidamente con el entorno físico: entrada y salida de información.
	- Las acciones se deben completar en determinado tiempo, no sólo es importante que sean correctas.
	- Que un sistema que sea rápido, no significa que sea de TR. Pero si deben ser suficiientemente rápidos para cumplir los
	  requerimientos.

Estos sistemas son
	- Grandes y complejos
	- Se manipulan magnitudes físicas
	- Extremandamente fiable
	- etc, (en la filmina)

Generalidades:
	- Mayor uso de E/S que controlan el proceso físico.
	- Se debe tener una planificación de cómo se irán a recibir estos mensjaes.
	- Se debe predecir determinados escenarios para aportar seguridad y confiabilidad para
	- Modelizar el sistma. Se utilizan simuladores para poder llegar a una simulación, en base a eso tener experiencia, para
	  luego implementarlo en el sistema y llevarlo al mundo real.

Estos sistemas en los que el tiempo entre una entrada y una salida son críticos, ya que determinado estímulo está relacionado con
otro evente.
El tiempo entre entrada y salida debe ser suficientemente pequeño para no superar el plazo máximo
Estos plazos pueden ser de microsegundos para un misil o segundos para un sistema de control de navegación de un barco.
Muy pocas lineas de códigos en estos sistemas.

(En la filmina):
	STR estrictos o Hard: La corrección temporal es crítica.
	El tiempo de respuesta es muy importante y no puede ser sacrificado por una mejora en otroos aspectos.
	En ciertos sistemas la corrección temporal es muy imoprtante.

STR No estrictos o soft:
	Se pueden perder información y no son tan críticas.

STR Firme:
	la probabilidad de que la respuesta se reciba antes de un tiempo estipulado no supera cierto nivel previamente acordado.
	- Se pueden perder plazos ocasionales
	- Una respuesta tardía no tiene valor
	- Ejemplo: transmisión de video


Loterancia a fallas
Sistemas con parada seguras: en caso de fallo colocan al sistema en un estado seguro (el ejemplo del brazo mecánico pesado)
Sistemas con degradación aceptable presentan una pérdida parcial de funcionalidad en caso de fallo pudiendo seguir funcionando a
pesar de dicha merma.
Sistemas críticos: NUNCA debe fallar, debe tenerse muchos planes por si ocurre algo inesperado.

Ejemplos de TR:
	- STR Pequeño: lo que se utilizan para ver cómo se moviliza la gente dentro de un gran recital, si es que van a ver una
	  banda u otra, o si van al bar,etc
	- STR grande: sector automotriz, aviónes, etc
	- Internet de las cosas: No es de tiempo real, porque en el medio está TCP/IP, una cosa es lo de los conciertos y otra
	  cosa es una operación.

Tenemos clases de procesos:
	- Periódicos - aperiódicos
	- Dinámicos - estáticos
	- Crítico
	- Esencial - No Esencial

Procesos: Denominados tareas en STR y se pueden clasificar según propidedades, sobre lo que hacen, cuándo  su seguridad.

El comportamiento temporal (en la filmina).

Atributos temporales (el gráfico de lf filmina): La activación, puede ocurrir con una cadencia regulara, o puede que no se sepa
cuándo, se implementa la probabilidad para entender cuándo se activará. La respuesta si es absoluta tiene un tiempo límite para
terminar y tiene un intervalo desde la activación.

Se debe mejorar cómo se debe utilizar los recursos, explotarlo al máximo. Lo mismo el tiempo de respuestas y las prioridades (más
si es duro o estricto, siempre deben haber prioridades).
	- Dispositivos externos (que no son solo impresoras o cosas así).
	- Mensajes a intervalos irregulares: tiene que haber interrupciones y cómo gestionarlos.
	- Modelar procesos concurrentes.

Diferencia entre los sistemas tradicionales:
	- Comunicaciones entre procesos (pipes, semáforos, etc)
	- Testing Se debe testear tanto software y hard
	- Construcción de simuladores
	- Ejecución, casi siempre estos sistemas son de tipo bucle, que se efectuan siempre en ese bucle y sale sólo para manejar
	  una interrupción.

Sistemas embebidos: Sistemas más amplios, los STR forma parta de un sistema más amplio (sistema empotrado).

Ejemplos de STR puede ser un caloventor (que si bien no tiene una computadora, si se puede implementar de forma electrónica).

Eventos STR:
	- Arquitectura controlada por enventos: se dispara una acción porque se dispara por un evento externo.
	- Arquitectura controlada por tiempo: por un reloj.

Soporte de TR: Se tiene que preveer, se plantean diferentes situaciones y especificar determinado tiempo según cómo se ejecutan en
tiempo y forma, siempre se utiliza tomar el PEOR CASO.

Las Entradas y Salidas han ido creciendo por lo que cada E/S va a tener un procesador (como sucede con las placas de video que han
ido aumentando las capacidades de procesamiento).

Toda la última parte se pasa muy por encima, es muy genérico y el profesor se la pasó hablando de ejemplos de su vida.
