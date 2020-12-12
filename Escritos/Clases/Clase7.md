
# Simulación
	La idea es tratar de construir modelos como para poder en algún momento proyectar datos.
	Se puede definir como la imitación de las operaciones de un sistema del mundo real en el tiempo.

	Se utiliza como herramienta para la toma de decisiones.
	Por lo general son ejecutadas con máquinas que poseen la preparación para ello.

	Muchas veces se aplica a sistemas complejos que no alcanza con realizar modelos matemáticos (con sólo un análisis
	numérico).

## Sistemas
	Se define como sistema a una colección de entidades (humanos o computadoras) que actán e interactúan en conjunto para
	obtener un fin lógico. Ejemplo: fábricas, hospital, red de computadoras, supermercado, etc.

	Se trata de poner la información del mundo real de determinada manera para poder analizarlo.

	El modelo matemático tuvo un cuello de botella que fue el de establecer cuántas cuentas se podían realizar en determinado
	tiempo, cuestión que desenbocó en la simulación computacional.

# ¿Cómo saber qué pedazo de realidad representar?
	Depende de la persona encargada de modelar esa parte de la realidad; los sistemas son construcciones mentales,es decir que
	corresponden a la construcción mental de los objetos del mundo real, ya que cada sistema depende del punto de vista del
	observador.
	Hay que tener en claro que *nosotros representamos el sistema, no lo reproducimos*.
	Por lo tanto, a diferentes personas, diferentes ideas y diferentes sistemas.

# Proceso de simulación:
	1. Análisis del problema y planificación: Se analiza el problema y se decide qué objetivos abordar.
	2. Recolección de datos, paso necesario para estimar parámetros de entrada del modelo.
	3. Construcción del modelo, una vez completados 1 y 2, se procede a la construcción de un modelo y su implementación.
	4. Verificación del modelo, el propósito de esta etapa es asegurarse que el modelo esté bien construido.
	5. Validación del modelo. ¿Qué validamos? El modelo, y sólo puede lograrse si existe agún sistema real comparable
	6. Diseño y ejecución de experimentos de simulación. Una vez que se superó el paso anterior, entonces se diseñan
	   experimentos de simulación para estimar la performance del modelo.
	7. Análisis de datos de salida, los experimentos esan sujetos a la performance estimada y a un análisis estadístico.
	8. Documentación.


# Diferencia entre modelado y simulación:
	- Un modelo es una idealización, es como el plano de subtes de Buenos Aires y el sistema de subtes real. Es una
	  idealización pero con ciertos elementos de realidad.
	- La simulación se refiere al proceso de ejecutar las ecuaciones al modelo desarrollado.

# Transaction Level Modeling
	Esta es una metodología de descripción de sistemas que permite simulaciones rápidas y eficientes de gran número de ciclos
	en sistemas complejos, con la ventaja de no especificar si serán modelados en hardware o software.
	Es una descripción a muy alto nivel y permite describir mejor la modelización de módulos,porque se abstrae de la
	comunicación entre ellos,lo que permite cincurscribir mejor cada uno de las operaciones del módulo sin tener en cuenta la
	relación con los demás.

# Modelos de simulación:
	- Estáticos: donde el tiempo no juega un papel fundamental.
	- Dinámicos: representa un sistema que evoluciona en el tiempo.
	- Determinísticos: si el sistema no contiene ningún elemento aleatorio, se le denomina determinístico.
	- Estocásticos: estos modelos producen salidas aleatorias. Como casi siempre se quiere modelar la realidad, la realidad se
	  comporta de manera estocástica.
	- Continuo o Discreto:

# Simulación de eventos discretos:
	Se le donminan así a los modelos de simulación discretos, dinámicos y estocásticos.


# Modelos:
	- Es una abstracción de la realidad
	- Es una representación de la realidad que ayuda a entender cómo funciona esa parte del mundo.
	- Es una construcción intelectual y descriptiva de una parte del mundo en la que el observador está interesado.
	- Suposiciones básicas y simples para captar el comportamiento más importante.
