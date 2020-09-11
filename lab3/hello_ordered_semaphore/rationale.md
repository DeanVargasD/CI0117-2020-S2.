# CI0117 - Laboratorio 3

### 

## Ejercicio 3 [hello_ordered_semaphore]
*¿Permite este mecanismo de control de concurrencia resolver este problema de manera predecible? Explique las diferencias entre usar exclusión mutua y semáforos para resolver este problema en un archivo rationale.md dentro de su carpeta hello_ordered_semaphore.*

Como el anterior, este mecanismo también sirve, su principal diferencia es el contador a la hora de inicializar el semáforo. Curiosamente me parece un ejemplo más visual que el anterior, aunque básicamente es lo mismo: Dejar que el siguiente entre hasta que el actual salude. En este caso dejar pasar a alguien es aumentar el contador con un post.
