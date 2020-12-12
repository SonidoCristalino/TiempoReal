
# Clase nº 1
Todo la parte de organización está dentro del Campus.

- 3 o 4 prácticas
- 1 parcial (se tocan los 3 primeras prácitcas) con su recuperatorio (se toma las 4 prácticas).
- Se accede al parcial aprobarndo las 3 primeras prácticas.
- Se tiene que hacer un Trabajo Final integrador (está en la filmina).
	Sistemas Embebidos (es lo único que el profesor no puede dar mucha ayuda).

Mail profesor: dencinas@unaj.edu.ar
Bibliografía es poca.

# Definición de lo que se puede denominar Sistemas de Tiempo Reales:

Tiempo real: es un sistema que tiene que reaccionar a estímulos del ambiente dento de intervalos marcados por el ambiente. No sólo
está acotado a software, sino también puede ser neumático, mecánico, etc. Se necesita un monitoreo, control, diferentes tipos de software.

	- Es importante el tiempo en todo este sistema.
	- Debe haber tolerancia a fallas.
	- Todos estos sistemas deben elaborarse teniendo en cuenta la concurrencia.

No es verdad que si es rápido, es de tiempo real. Si se tienen bien delimitados los requisitos temporales y los del entorno,
entonces se pueden abordar los sistemas de Tiempo Real.

Para la comunicación entre dispositivos de Tiempo Real se utilizan otros protocolos que los de internet: sólo para TIEMPO REAL

# Requerimientos de Tiempo Real:
	- Se necesita conocer el tiempo de procesamiento
	- Se necesita conocer los requerimientos de tiempo
	- Cúanto va a tardar en reaccionar el dispositivo: se necesita saber el rendimiento de todo el sistema.
	- Requerimientos de performance
	- Comunicación con el hardware dedicado.

# Clasificación de los sistemas de Tiempo Real:

El tiempo en algunos es crítico, en otros no tantos, y otros algo mixto.
	- Se pueden clasificar como Soft (lo que pueden demorar, la videoconferencia que puede pixelarse la imagen, etc), Hard (el
	  tiempo es crítico, un avión por ejemplo, ahí las cosas no pueden fallar) y el híbrido.
	  Hay sistemas tan críticos, que si no cumplen las funciones en un tiempo determinado, no sirve.
	- Comunicaciones: protocoles TCP/IP, pero hay más, se tienen sistemas de TR, comunicaciones para Tiempo Real, y las que son
	  inalámbricas y no. Con diferentes tipos de arbitraje (puede haber pérdidas de mensajes, retrasmisción, etc). En Tiempo
	  Real, NO SE PUEDEN perder mensajes, por lo que los protocolos son distintos.
	- Correctitud: tiene que ver con lo anterior, se prefiere que se cumplan los tiempos antes de perder este tiempo por
	  tener una lógica correcta. Lo primordial es el tiempo en este tipo de sistemas.
	- Tolerancia a fallas: se implementan redundancia para que al fallar uno de los componentes, no falle todo el sistema.
	  Por ejemplo se tienen dos o tres sensores y no uno, (con los discos de estado sólido, que son realmente de 3TB y no de 1,
	  y esto es porque falla mucho).

- Facilidades para SRT:
	* Sistemas operativos
	* Lenguajes
	* Metodologías

Un Sistema Tiempo Real es un sistema informático que cumple:
	- Interacciona repetidamente con el entorno físico: entrada y salida de información.
	- Las acciones se deben completar en determinado tiempo, no sólo es importante que sean correctas.
	- Que un sistema que sea rápido, no significa que sea de Tiempo Real. Pero si deben ser suficientemente rápidos para cumplir los
	  requerimientos.

Estos sistemas son:
	- Grandes y complejos
	- Se manipulan magnitudes físicas
	- Extremadamente fiable
	- etc, (en la filmina)

Generalidades:
	- Mayor uso de E/S que controlan el proceso físico.
	- Se debe tener una planificación de cómo y cuándo se irán a recibir estos mensajes, si el sistema será por ejemplo
	  aleatorio, o si por el contrarior serán completamente seguro y cierto.
	- Seguridad y confiabilidad: Se debe predecir determinados escenarios para aportar seguridad y confiabilidad al sistema.
	- Modelizar el sistema: Se utilizan simuladores para poder llegar a una simulación, en base a eso tener experiencia, hacer
	  experimentos para luego implementarlo en el sistema y llevarlo al mundo real.

# Otras definiciones:

	El hardware en estos sistemas casi siempre son especialmente diseñados para realizar una tarea determinada.

	Estos sistemas en los que el tiempo entre una entrada y una salida son críticos, ya que determinado estímulo en el mundo
	físico y la salida (que sería una acción) está relacionado con dicho evento.

	El tiempo entre entrada y salida debe ser suficientemente pequeño para no superar el plazo máximo.

	Estos plazos pueden ser de micro-segundos para un misil o segundos para un sistema de control de navegación de un barco.
	Se requieren muy pocas lineas de códigos en estos sistemas, ya que el tiempo de procesamiento también es crítico.

# Sistemas de Tiempo Real Estrictos y No Estrictos:

	## Sistemas de Tiempo Real estrictos o Hard:
		La corrección temporal es crítica. Como pueden ser los frenos en un auto, no importa que el sistema de aire
		acondicionado esté funcionando correctamente, sino que los frenos ante determinado estímulo del mundo real,
		funcionen correctamente.
		El tiempo de respuesta es muy importante y no puede ser sacrificado por una mejora en otros aspectos.
		En ciertos sistemas la corrección temporal es muy importante.

	## STiempo Real No estrictos o soft:
		Se pueden perder información y no son tan críticas. Tienen plazos temporales más laxos que los hard; las
		respuestas que se pueden obtener del sistema no pueden ser tan determinantes como en el hard, como por ejemplo
		cuando en un aire acondicionado se programa para poner la temperatura en 24º y el sistema lo pone en 25º o 23º; lo
		cual no es tan perjudicial. Por lo que se pueden perder plazos de vez en cuando.

	## STiempo Real Firme:
		La probabilidad de que la respuesta se reciba antes de un tiempo estipulado no supera cierto nivel previamente
		acordado. Lo ideal sería que el sistema reaccione en determinado plazo de tiempo, si no lo hace, se le permite
		seguir procesando.
			- Se pueden perder plazos ocasionalmente.
			- Una respuesta tardía no tiene valor.
			- Ejemplo: transmisión de video.

# Loterancia a fallas:

Sistemas con PARADA SEGURAS: en caso de fallo colocan al sistema en un estado seguro (el ejemplo del brazo mecánico pesado, que
pone en riesgo a operarios y al ambiente laboral, por lo que se tratan de implementar rutinas que en caso de fallo, pongan el
brazo en determinado lugar y no que ande girando como loco).

Sistemas con DEGRADACIÓN ACEPTABLE: presentan una pérdida parcial de funcionalidad en caso de fallo pudiendo seguir funcionando a
pesar de dicha merma. Como por ejemplo algún sensor en un avión, los cuales tienen que presentar un plazo determinado de tiempo
para que antes de dejar de funcionar, nos permita aterrizar el avión.

Sistemas CRÍTICOS: NUNCA debe fallar, debe tenerse muchos planes por si ocurre algo inesperado. Por ejemplo un avión, que tiene
una falla cada un millón de horas (se sabe que esto no ocurre), se debe planificar que sucede si llega a fallar. Hasta ahora la
solución es tener redundancia de sistemas, se dispara uno cuando el otro deja comienza a fallar.

Ejemplos de Tiempo Real:
	- Sistema de Tiempo Real Pequeño: lo que se utilizan para ver cómo se moviliza la gente dentro de un gran recital, los
	  cuales son chips dentro de una muñequera, permitiendo así saber si es que van a ver una banda u otra, o si van al bar,
	  etc.
	- Sistema de Tiempo Real grande: sector automotriz, aviónes, etc
	- Internet de las cosas: No es de tiempo real, porque en el medio está TCP/IP, una cosa es el análisis que se realizan con
	  lo de los conciertos y otra cosa es una cirugía que se deba aplicar a un paciente que está a miles de kilómetros de
	  distancia.

# Tenemos clases de procesos:
	- Periódicos - aperiódicos
	- Dinámicos - estáticos
	- Crítico
	- Esencial - No Esencial
	- Concurrente - Paralela

# Para tener en cuenta:
Procesos: Denominados tareas en Sistemas de Tiempo Real y se pueden clasificar según propiedades, sobre lo que hacen, en cuanto a
su seguridad, etc.

El comportamiento temporal (en la filmina).

Atributos temporales (el gráfico de la filmina): La activación, puede ocurrir con una cadencia regulara, o puede que no se sepa
cuándo, se implementa la probabilidad para entender cuándo se activará. La respuesta si es absoluta tiene un tiempo límite para
terminar y tiene un intervalo desde la activación.

Lo que se debe garantizar es que todas las veces que se ejecuta una tarea, que termine dentro de un plazo previamente determinado.

Se debe mejorar cómo se debe utilizar los recursos, explotarlo al máximo. Lo mismo el tiempo de respuestas y las prioridades (más
si es duro o estricto, siempre deben haber prioridades).
	- Dispositivos externos (que no son solo impresoras o cosas así).
	- Mensajes a intervalos irregulares (por lo que no son periódicos): tiene que haber interrupciones y cómo gestionarlos.
	- Modelar los procesos de forma concurrentes, es decir, se puede suponer que se tiene un core, y que atenderá varias
	  tareas y nosotros debemos verlas como que está atendiendo todas al mismo tiempo (cuando en realidad eso no ocurre).

# Diferencia entre los sistemas tradicionales:
	- Comunicaciones entre procesos (pipes, semáforos, tiene que ver con compartir los recursos, tener recursos compartidos).
	- Testing: Se debe testear tanto software y hardware
	- Construcción de simuladores
	- Ejecución, casi siempre estos sistemas son de tipo bucle, que se realizan siempre en ese bucle y sale sólo para manejar
	  una interrupción.

Sistemas embebidos: Sistemas más amplios, los Sistemas de Tiempo Real forma parta de un sistema más amplio (sistema empotrado).

Ejemplos de Sistemas Tiempo Real puede ser un caloventor bastante antiguo (que si bien no tiene una computadora, si se puede
implementar de forma electrónica).

# Eventos de Tiempo Real:
	- Arquitectura controlada por eventos: se dispara una acción porque se dispara por un evento externo.
	- Arquitectura controlada por tiempo: por un reloj.

# Entorno de un Sistema de Tiempo Real:
Se debería de contar con un sistema lo más robusto posible para que en caso de tener un entorno que no era el esperado ni el
normal, saber cómo reaccionar (para eso están los simuladores). Lo imprescindible es prever.

- Entorno Activo:
	Comprende los operadores que intervienen en el comportamiento del sistema modificando el modo de operación.

- Entorno Pasivo:
	Comprende a los usuarios que están sólo interesados en el servicio proporcionado y al ambiente exterior y que no tiene
	nada que ver con la existencia de un sistema.

Un Sistema embebido unicamente tiene un entorno pasivo y es un componente autónomo que forman parte de un sistema mayor. Por
ejemplo: Disco duro, lavarropas, automóvil, sonda espacial, equipo médico.

# Sistemas de Tiempo Real por Eventos y Tiempo:
Se diferencias en cuanto a cómo es que se disparan las acciones que lleva a cabo el sistema. Los más utilizados son los accionados
por Eventos.

	* Arquitectura controlada por eventos o interrupciones:
		- Establece la ejecución de un compoennte o tarea basándose en la aparición de una interrupción o señal generada
		  por un evento externo.
		- Constituyen un mecanismo mucho más eficaz para responder ante eventos externos no regulares.
	* Arquitectura controlada por tiempo:
	  	- Opera de acuerdo a los ciclos de reloj o relojes del sistema.
		- Este tipo de sistemas se utilizan cuando es preciso la ejecución de tareas periódicas o la ejecución de tareas
		  mediante temporizadores.
		- Son más sencillos y robustos.

# Concurrencia
Es la capacidad de un sistema de mantener varias tareas en estados intermedios de su ejecución:
	- Sistemas de tiempo compartido.
	- Sistemas multiprocesadores.
	- Sistemas distribuidos.

# Soporte de Tiempo Real:
Se tiene que prever nosotros, se plantean diferentes situaciones y especificar determinado tiempo según cómo se ejecutan en tiempo
y forma, siempre se utiliza tomar el PEOR CASO.

# Predictibiildad (determinismo):
Las tareas pueden aparecer de forma periódica o no, eso tiene que ver con el Determinismo. El tema es que casi siempre será
probabilístico, porque la naturaleza NO es determinista.
	- Cuando se activa una tarea, debe ser posible determinar con certeza cuando se ejecutará su ejecución.
	- Aún cuando el sistema esté sobrecargado.

Las Entradas y Salidas han ido creciendo por lo que cada E/S va a tener un procesador (como sucede con las placas de video que han
ido aumentando las capacidades de procesamiento).

# En suma:
	- Se requiere tener predicción del comportamiento del sistema
		- Tanto de tareas Críticas como periódicas
	- También se va a requerir supervisión del tiempo de ejecución de procesos
	- La sincronización y comunicación
	- Evitar los deadlok (es decir, los procesos que se bloquean mutuamente)
	- Tener por sobre todo, la seguridad

Toda la última parte se pasa muy por encima, es muy genérico y el profesor se la pasó hablando de ejemplos de su vida.
