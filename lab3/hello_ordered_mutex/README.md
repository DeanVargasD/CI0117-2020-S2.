# CI0117 - Laboratorio 3

### 


## Ejercicio 2 [hello_ordered_mutex]
*¿Permite este mecanismo de control de concurrencia resolver este problema de manera predecible?*

En efecto el mecanismo funciona si aplicamos lock a todos los mutex del arreglo exceptuando al primero, de esta forma el primer hilo que se crea (thread0) entra en el mutex y únicamente él tendrá la potestad de abrir la puerta al hilo que está esperando por el siguiente mutex para saludar.

