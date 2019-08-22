# lab-Memory-API

# Questions
1. Escriba un programa simple llamado null.c que cree un puntero a un entero, llevelo a null y entonces intente desreferenciarlo (esto es, asignarle un valor). Compile este programa llamado null. ¿Qué pasa cuando usted ejecuta este programa?

Una vez se ejecuta el programa, el sistema lanza la excepción Segmentation fault, debido a que está accediendo a un espacio de memoria que no le pertenece

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/1.png)

2. Compile el programa del ejercicio anterior usando información de simbolos (con la flag -g). Al hacer esto se esta poniendo mas informacion en el ejecutable para permitir al debugger acceder a informacion util sobre los nombres de las variables y cosas similares. Ejecute el programa bajo el debugger digitando en consola (para el caso) gdb null y entonces una vez el gdb este corriendo ejecute run. ¿Qué muestra gdb?

Me permite observar, además de la excepción, la línea que la está generando con su correspondiente código

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/2.png)

3. Haga uso de la herramienta valgrind en el programa empleado en los puntos anteriores. Se usará la herramienta memcheck que es parte de valgrind para analizar lo que pasa: valgrind --leak-check=yes null. ¿Qué pasa cuando corre esto?, Â¿Puede usted interpretar la salida de la herramienta anterior?

En consola se puede observar lo que ocurre en memoria. Ocurre una excepcion debido a que se está asignando un valor sin determinar el tamaño en memoria, tal y como se hace con la función malloc.

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/3.png)

4. Escriba un programa sencillo que asigne memoria usando malloc() pero olvide liberarla antes de que el programa termina. ¿Qué pasa cuando este programa se ejecuta?, ¿Puede usted usar gdb para encontrar problemas como este?, ¿Que dice acerca de Valgrind (de nuevo use este con la bandera --leak check=yes)?

Una vez se ejecuta el programa, no se evidencia problema alguno

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/4.png)

Cuando se ejecuta usando el comando gdb, la salida exitosa por lo que no es posible encontrar problemas usando dicho comando.

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/4_1.png)

Por el contrario, valgrind nos permite darnos cuenta de que efectivamente se presenta un error con la función malloc

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/4_2.png)

5. Escriba un programa que cree un array de enteros llamado data de un tamaño de 100 usando malloc; entonces, lleve el data[100] a 0. ¿Qué pasa cuando este programa se ejecuta?, ¿Qué pasa cuando se corre el programa usando valgrind?, ¿El programa es correcto?

El programa no es correcto, debido a que como se evidencia en el pantallazo, una vez ejecutado el programa con valgrind, se presenta un desbordamiento al acceder a la posición 100 del vector ya que este va de la posición 0 a la 99

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/5.png)

6. Codifique un programa que asigne un array de enteros (como arriba), luego lo libere, y entonces intente imprimir el valor de un elemento del array. ¿El programa corre?, ¿Que pasa cuando hace uso de valgrind?

El programa no corre. Se puede observar un error debido a que se libera la memoria antes de imprimir el valor que se encuentra en alguna posición del vector	

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/6.png)

7. Ahora pase un funny value para liberar (e.g. un puntero en la mitad del array que usted ha asignado) ¿Qué pasa?, ¿Ústed necesita herramientas para encontrar este tipo de problemas?

Tal y como se puede observar en el pantallazo, no se evidencia ninguna excepcion. Por lo que sí es necesario el uso de herramientas para encontralas.

![alt text](https://github.com/Luisem11/LabSO/blob/master/Lab-Memory-API/7.png)
