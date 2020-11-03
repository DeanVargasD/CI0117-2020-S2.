
# CI0117 - Ejercicio 6


## Ejercicio 6  [omp_for]


La diferencia entre parallel, parallel for y for es la siguiente: 

Un "equipo" es el grupo de hilos que se están ejecutando en el momento. Al comienzo del programa, el equipo consta de un solo hilo. Un construct **parallel** divide el hilo actual en un nuevo equipo de hilos durante la duración del siguiente bloque, después de lo cual el equipo se fusiona nuevamente en uno. 
**for** divide el trabajo del bucle for entre los hilos del equipo actual. No crea hilos, solo divide el trabajo entre los hilos del equipo en ejecución. **parallel for** es una abreviatura de dos comandos a la vez: **parallel** y **for**.  **parallel** crea un nuevo equipo y, para las divisiones, ese equipo maneja diferentes partes del ciclo. Si el programa nunca contiene un **parallel** construct, nunca hay más de un hilo; el subproceso maestro que inicia el programa y lo ejecuta, como en los programas secuenciales.

Fuente:
https://bisqwit.iki.fi/story/howto/openmp/