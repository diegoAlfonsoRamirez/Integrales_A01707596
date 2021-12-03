# Central de Plantilla de trabajadores de un Laboratorio.

>Ejemplo 1: Buscar o actualizar un dato.
> 
> Paso 1: Seleccionar la opción -> (2).
> Paso 2: Seleccionar una de las opciones disponibles -> Ejemplo - (1).
> Paso 3: Selecciona una de las opciones disponibles -> Ejemplo - (1).
> Paso 4: Introduce la posición del dato que deseas reemplazar -> Ejemplo - (2).
> Paso 5: Introduce el dato con el que deseas actualizar -> Ejemplo - (3).
> Paso 6: Pulse cualquier tecla para salir y ver la nueva lista.
> 
Se incluyen las funciones de lectura y escritura de archivos CSV, la lectura viene por defecto, mientras que la escritura es una
opción propia del menú, siendo ambas, estructuras consultadas aparte de lo mostrado en el curso.

## SICT0302B: Toma decisiones 

### Selecciona y usa una estructura lineal adecuada al problema

En este algoritmo hago uso de una lista doblemente ligada para poder actualizar y buscar un único dato en especifico, ya que éstas listas tienen
la propiedad de poder actualizarse y dejar todo en un orden sencillo de comprender, además de poder acceder a este dato tanto por el head como por
el tail de la lista, siendo eficiente en términos temporales.

### Selecciona un algoritmo de ordenamiento adecuado al problema

Para éste algoritmo hice uso de un Bubble sort, al ser sencillo de implementar y manejar datos que no tienen una gran diferencia entre si. No se hizi
uso de un merge sort a fin de no hacer uso de la memoria, siendo que tampoco se debe de preocupar mucho por el tiempo de ordenamiento, pues se espera 
que el laboratorio se confidencial y de poco personal.

### Usa un árbol adecuado para resolver un problema

Use un árbol Heap, pues al tener una implementación de tipo HeapMin, puedo obtener el dato más pequeño de la lista (TimeY) en un tiempo básicamente constante.

### Selecciona un algoritmo de Hashing adecuado al problema

Para éste caso hago uso de un hash como una herramienta de "busqueda", ya que a diferencia de las listas o árboles, con un hash puedo buscar un dato de forma
mucho más precisa, ya que puedo incluir muchos más datos en la key, que no puedo en una lista o árbol, y me ayuda a evitar problemas que pueden
presentarse en búsquedas que sólo permiten un dato que puede estar repetido, aunque sería un problema si y solo si existiera un elemento con todos
los datos repetidos, algo poco probable.

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

Se presentó un caso de prueba al inicio del README, siendo que en los demás casos, se incluyen (para input manual) en el documento casos.

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

#### Ordenar la base de datos

Para cualquiera de los casos de ordenamiento, al ser un bubble sort, la complejidad temporal sería de O(n^2).

#### Buscar o actualizar un dato

Utilizando listas doblemente ligadas, puedo acceder a la información tanto desde el tail como el head, por lo que puedo reducir el tiempo
de acceso a O(n/2).

#### Agregar un nuevo empleado a la base de datos

Esta función es algo complicada, ya que a primera vista podría parecer un O(1), pero se vuelve un O(n) ya que la función debe de reescribir
los datos anteriores a fin de no dejar en blanco toda la tabla con excepción del nuevo dato agreado.

#### Consulta del personal en plantilla

En éste caso, hago uso de un hash a fin de crear datos únicos relacionados con la información de cada elemento, sumado a esto, la hash table debe
de recorrerse nuevamente a fin de encontar el elemento al que corresponda la llave proporcionada, por lo que la complejidad asciende a O(n^2).

#### Consulta del elemento más reciente

Siendo que se obtiene únicamente el elemento del incio del árbol, la complejidad temporal de ésta función es O(1)

## SICT0303B: Implementa acciones científicas 

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

El programa puede búscar información tanto por el método de hash como por el de listas (opción 2 y 4).
El programa permite obtener las listas ordenadas dependiendo de nuestra elección
El programa permite obtener los empleados y sus datos en las 2 primeras entradas, deplegando la lista en pantalla.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

El personal y sus datos están guardados en un archivo CSV, desde el cual se puede leer para obtener la información en pantalla posteriormetne.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera

Se puede agregar un nuevo empleado y sus datos en el CSV, aunque la escritura puede resultar un poco lenta dessde el punto de vista de calculo de complejidad.
