
# CI0117 - Laboratorio 7
**Fecha de entrega:** Lunes 9 de Noviembre 11:50pm.
**Estudiantes:**
Josué Vargas Delgado B98194
Nelson Álvarez Cedeño B90368

## Ejercicio 1  [count_primes_serial]

El tiempo de ejecucion para 10.000.000 fue de 9.8695s

## Ejercicio 2  [count_primes_parallel]
El tiempo de ejecucion para 10.000.000 fue de 9.7987s

## Ejercicio 3  [count_primes_cyclic]
La política de  guided scheduling es similar a un scheduling dinámico, excepto que el tamaño del chunk cambia a medida que se ejecuta el programa. Comienza con grandes trozos, pero luego se ajusta
a tamaños de chunk más pequeños si la carga de trabajo está desequilibrada.
Al medir el tiempo que tomaron los diferentes tipos de scheduling, se tuvo que:

| N | static | dynamic | guided 
|---|---|---|---|
| 1  |  10.0371s |  9.8470s | 9.7042  | 
| 15525  | 9.8216s  |  10.5036 | 9.6859  
| 31050  |  10.6376s | 10.3374s  |  9.9042 
| 9999999  |  9.8293s  |9.7778| 9.8312  

Usualmente cuando cada iteración del ciclo toma más o menos el mismo tiempo el scheduling más efectivo es el static, mientras que si el tiempo varía es el dynamic.
En este caso, el que obtuvo mejor tiempo fue el guided, posiblemente al tipo de implementación que se utilizó para el problema y al número elegido (10.000.000).  Sin embargo, como de costumbre, los tiempos varían por ser ejecutado en máquina virtual, donde a veces el dynamic sobrepasa los tiempos del guided (como es la mayoría del tiempo).