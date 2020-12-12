
# Clase nº 4

Planificación:
Existen 3 tipos de tareas según sus características temporales:
	- Tareas periódicas: se ejecutan periódicamente en un período constante. Se tiene una frecuencia fija de aparición de la
	  tarea.
	- Tareas esporádicas: tienen un tiempo de finalización estricto, pero se ejecutan esporádicamente. Se tratan como tareas
	  periódicas suponiendo que existe un tiempo mínimo entre dos tareas consecutivas. El periódo de frecuencia no es
	  palpable, se sale de la politica, por lo que se intenta de forzarlo a esa periodicidad.
	  Por ejemplo: luego de medirla se hace una estimación de que en el plazo de una hora, esta tarea va a aparecer, pero no
	  se sabe cuándo.
	- Tareas aperiódicas: No tienen plazo de finalización estricto, y si lo tiene, no es obligatorio que lo cumpla.

En tiempo real hay que tener en cuenta que se agregan mayores márgenes para asegurar que no falle.
Tener métricas es importante en PTR : tardanza, utilidad, Ci, Ri, Pi (de las filminas).
	ti = Ri - Di (debería dar negativo, cuando se torna positivo, hay que tenerlo en cuenta, ya que si es de un sistema duro,
	se debe descartar).
	- N: Número de tareas del sistema
	- Pi: Período de activación
	- Ci: Tiempo máximo de ejecución.
	- Di: Plazo máximo de terminación
	- Ri: Tiempo de respuesta máximo. Es el timpoe desde que la tarea se activa hasta que termina realmente de ejecutarse.
	- Pri: Prioridad de la tarea (puede tener según la política, mayor o menor prioridad)
	- Si: Desface respecto al momento inicial.

# Tiempo real Crítico y opcional
Tardanza de una tarea: diferencia entre el tiempo de respuesta y el plazo de ejecución de una tarea.
	T = Ri - Di  (si el resultado de T es negativo, entonces hay que preocuparse, a menos que la tarea sea crítica, entonces
	se debe descartar).

# Restricciones:
Están relacionados con un factor deterministico.
	- Restricciones Deterministicas: poner una cota mínima, más de eso no puede pasar, es crítico la cota dada. Por ejemplo el
	  resultado de una tarea que se debe obtener siempre antes de los 50 milisengundos. Son totalmente crítico.
	- Restricciones Probabilísticas: se pone una cota, pero puede abordarse de alguna otra forma, sin ser crítico. Por
	  ejemplo, la probabilidad que el tiempo de respuesta exceda los 50 milisegundos, debe ser inferior a 0,2. Es más flexible
	  que la determinística.
	- Restricciones en términos de una función de Utilidad: poner una cota máxima. Por ejemplo, la utilidad de los resultados
	  que proporciona una tarea debe ser superior a 0.8 o superior. Es más flexible que la determinística.

Los sistemas tratan de que sean deterministicos y por lo tanto previsibles, pero se sabe que en realidad no ocurre eso,sino todo
lo contrario, probabilísticos y estocásticos.

# Tiempos de Ejecución
Contar cuánto tiempo llevará ejecutarse en el procesador. No es tan lineal, por lo que no es posible tener métricas exactas de un
código. Cuando se tienen tiempos críticos, las tareas deben tener un valor bien conocido (para planificar). Hay algoritmos para
estas tareas, para lo que sería una planificación dinámica.

Sería mejor que todas las tareas sean periódicas (es decir,que se sepa cuánto tiempo tardará en ejecutarse y cuándo), por eso se
fuerza a que sean todas las tareas de este tipo, periódicas. Cuando las tareas no son tan así, entonces se trata de forzar, que
sean periódicas de alguna manera.

La tarea más lenta es la que marca el tiempo, como suele suceder cuando se junta un pelotón de personas a correr, el cual el
tiempo está dado por el tiempo del corredor más lento.

# Factor de utilización:
	Tiempo ejecución de cada una de las tareas / su período =
		* Si la suma da 0 o menor a 1, entonces podría llegar a ser planificable (esto es para mono core). Condición
		  necesaria pero NO suficiente.

	Se buscan patrones, ¿Cada cuánto aparecen estas tareas? El patrón se denomina hiperperiodo, es una tarea que engloba a
	todas las demás.
	¿Qué tan fácil sería hacer esto si se tuvieran pocas tareas? Esto depende de Ci y del período. Hay grandes chances que las
	tareas no puedan volverse periódicas.

# Hiperperíodo:
	Es el mínimo común múltiplo de los períodos de todas las tareas.

	A partir de este valor el sistema se repite, si se determina que un sistema es planificable en la duración de un
	hiperperíodo, lo será también durante toda la vida del sistema.

# Dependencia entre tareas.
	Atentan contra la planificación. Puede haber dependencia entre tareas, entre datos, temporal relativa (en la filmina).
	Precedencia: una tarea depende de que otra se active de manera explícita.

	Relación de cauce: Si se tiene un overhead (cluster de varios cores) se puede llegar a tener un problema grande de
	planificación. Es muy importante tener un Middleware (para la distribución de tareas entre distintos nodos).

	También una tarea puede depender de la sincronización de tareas. Como puede ser en un video de streaming,que la
	sincronización entre el audio y los labios NO se de, pero sin embargo es tolerable hasta cierto umbral. Esto depende de
	cómo sea el sistema, en caso de ser estricto, NO se podrá tolerar.


# Parámetros funcionales:
	Apropiación del procesador : es importante siempre que se tengan prioridades. Relacionado con tareas enmascaradas (que sea
	interrumpible o no), para que sean interrupmidas, hay que tenerlo en cuenta en la planificación. Qué tipo de apropiación
	hace, en qué tiempo (todo esto lo hace el SO de forma estándar).

# Planificación
	Cumplir los límites temporales, si se tienen muchas tareas, se tienen muchas restricciones. Es importante arrancar con
	pocas tareas y ver cómo funciona el procesador.
	Distribuir las tareas según su tiempo de ejecución y su prioridad.

# Planificación en TP
	Planificación puede ser estática(cíclico) o dinámica (prioridades)

# Planificación
	Condiciones:
		* Mientras cumpla con las cotas, va a estar bien.
		* El rendimiento de un algoritmo de panificación tien que ver más con encontrar la planificación; se deben
		  considerar todos los requirimientos.
		* Procesos opcionales: hay agregar a los requirimientos, que algunas tareas puedan finalizar fuera de plazo del
		  tiempo
		* Hay un grupo de tareas que también pueda finalizar fuera de plazo, Se puede pensar ¿cuánto tiempo puede esperar?
		  hay que tener cuidado porque se está centrando más en que no se ejecute esta tarea para que el sistema pueda
		  seguir funcionando.

Tiempo real con sensores: no tienen tantas tareas (es un bucle infinito, que se ejecuta constantemente).En este caso las tareas se
tienen que ejecutar en el orden adecuado. Ese Al de planificación va a tener en cuenta que el tiempo lo va a dar la tarea más
lenta

# Planificación Estática

	En la estática es la que se puede determinar el órden de ejecución de las tareas ANTES de la ejecución, se va a poder
	visualizar esto fácilmente. Se puede armar las planificación bastante bien. El problema que tiene es que es poco abierto
	para nuevas tareas. Se vuelve menos flexible.
	Las priorirdades es más complicado de verlo, si se agregan las características apropiativas, el microprocesador ve las
	tareas más dinámicas.

	Se puede saber el orden de las tareas de forma manual, pero no es lo que se utiliza en realidad.

# Planificación Dinámica
	El orden de las tareas se decide durante la ejecución.
	El análisis de las tareas también se realiza durante la ejecución.

	Prioridades fijas y procesos totalmente interrumpibles.
		- La prioridad se asocia con la urgencia oa la importancia.
		- Siempre se ejecuta la tarea lista con mayor prioridad

# Caso ideal:
	Se piensan en un ambiente DEMASIADO IDEAL: Tareas se piensan con una frecuencia fija, completamente independiente y todos
	los tiempos de finalización son iguales, lo mismo que los de ejecución.
	Se hace una planificación de esto es bastante sencillo.

# Ejecutivos cíclicos
	A partir de la periodicidad, del tiempo de ejecución, se trata de planificar. El hiperperiodo (ejecutivo cíclico) es el
	que más tarda en aparecer, entre este tiempo que vuelve a aparecer, entran otras tareas.

	A partir de esa tarea que tarda mucho más en aparecer, podemos estipular que en el medio aparecen otros (con más
	frecuencia). Entonces, lo que se hace es poder encontrar múltiplos de ese período, entonces queda todo bien.
	A estos múltiplos, se los denomina Ciclos Secundarios, mientras que el principal, será este hiperperíodo (el período más
	grande).

	Minuto: 37.30 explica la tabla de distribución de tarea.
		- Tarea
		- Tiempo en el que aparece (T)
		- Tiempo que necesita para finalizar la tarea, es decir tiempo dentro del procesador(C) (en milisegundos).
	El hiperperíodo en este ejemplo sería 16.
	Ciclo Secundario de 4.

	Los ejecutivos cíclicos son la aproximación más tradicional a la construcción de sistemas de tiempo real.

# Desventajas de los Ejecutivos Cíclicos

Tiene dificultad para incorporar procesos esporádicos
Problemas con procesos con períodos grandes. La alternativa que se tiene a esto es directamente configurar un tiempo que sabemos
de antemano que ocurrirá el proceso (por ejemplo un tiempo de dos horas) y se setea a eso y listo.

Hay problemas a la hora de construir ejecutivos cíclicos, pero en caso de poder generarlo, no hará falta ningún test de
planificación más. El problema es que es difícil de implementar un ejecutivo cíclico coomo una estrategia de implementación
apropiada.

# Planificadores basados en prioridades
	Se ejecutan las tareas de más prioridad activa.

	Asignación de prioridades puede ser:
		- Estatica: Las prioridades que se asignan a cada proceso son constantes, es decir que se calculan antes de
		  comenzado el sistema, se ejecutan según sus requisitos de temporización y no en función de la integridad del
		  sistema.
		- Dinámica: Cuando se habla de procesadores "expulsivos" (o no apropiativos), al hacerse del control del
		  procesador, se habla de prioridades dinámicas. Cuando es apropiativo, (no expulsivo) no importa la prioridad
		  otorgada, el proceso se queda en el procesador hasta que finaliza o cede el espacio a otro proceso.

		  La problemática de esto es hablar de prioridades para los procesos, pero que el procesador sea apropiativo, es
		  decir, que si viene una tarea de mayor prioridad que otra, y al ser apropiativo, el proceso no termina de
		  ejecutar hasta que finalice (porque se apropia del recurso del procesador), entonces hay un problema y hay que
		  visualizarlo mucho antes, en la etapa del diseño.

# Rate monotonic:
	Prioridad la tiene siempre el más frecuente, el que tiene la frecuencia más pequeña. De acuerdo de a eso, toma las demás
	tareas, la prioridad más alta la tiene el que aparece de forma más frecuente.

	Funciona bien cuando las prioridades se otorgan de forma estática.

# Deadline monotonic:
	Prioridad a la tareas que se ejecutan muy rápido. Las que son más cortas, porque tienen código pequeño.
	Ejecuta al que tiene un peso de finalización más pequeño. Las prioridades se asignan según el proceso que se ejecute más
	rápidamente.

# POSIX 1003.1b
	Políticas que se implementan para las características en tiempo real en UNIX.
	La planificación (policy o política) que se pueden implementar (que sean apropiativa) pueden ser:
		* FIFO: para el segundo período, toma la de mayor mayor prioridad.
		* ROUND-ROBIN (maneja quantum)

	Quantum: cantidad de tiempo que le otorga el procesador para que se ejecute la tarea, pero depende de su prioridad.

	Describe cómo el planificador elige una tarea cuando tiene varias tienen el mismo nivel de prioridad.

# Test de Planificabilidad
	Se debe aplicar la sumatoria para saber si es posible planificar los procesos que se tienen de input. Cuando da igual o
	menor a 1, lo que indica es que ES POSIBLE llegar a una planificación, pero vale aclarar que es una condición necesaria
	PERO no suficiente.

# Planificadores con prioridades dinámicas Earliest Deadline First (EDF)

	La prioridad de una tarea se calcula en tiempo de ejecución.
	La prioridad de una tarea puede cambiar a lo largo de su ejecución y en diferentes activaciones.

	Independencia de tareas es cada vez más complicado. En los sistemas autónomos, es medio extraño que suceda.

# Least Laxity First (LLF):

Se asignan las prioridades dando preferencia a las tareas con menor holgura (plazo menos tiempo de procesamiento restante) de la
tarea.


# Practica nº 2:
	Ejercicio 1 y 2: Responder en una planilla de excel pensar que cada celda es una unidad de tiempo, por fila una tarea y se
	hacen los cáculculos.
		a) analizar si es planificable o no el sistema. Desplegar las tareas y encontrar un patron si se puede ejecutar el
		sistema.
