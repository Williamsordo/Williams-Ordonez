# 📙 Algoritmos y Programación II

## Descripción de la Asignatura
Esta asignatura profundiza en la modularización de software, diseño de funciones reusables, paso de parámetros, manejo de estructuras de datos estáticas (arreglos), recursividad y estructuras de datos dinámicas no lineales (Árboles Binarios).

---

## 🎯 Contenidos y Módulos

### 1. Modularización y Funciones (`01_funciones/`)
Diseño de funciones `void` y con valor de retorno:
- `area_triangulo.c`: Funciones que retornan valores flotantes de doble precisión (`double`).
- `cuenta_regresiva.c`: Procedimientos `void` y control de flujo de salida.
- `patron_asteriscos.c`: Funciones parametrizadas para renderizado por consola.
- `suma_dos_numeros.c`: Definición de prototipos e invocación de funciones básicas.
- `tabla_multiplicar_func.c`: Separación de interfaz de usuario y lógica del cálculo.

### 2. Arreglos y Estructuras de Datos (`02_arreglos/`)
Manejo de colecciones de datos contiguos en memoria:
- `promedio_lista.c`: Pasaje de arreglos como parámetros (`const int arr[]`), cálculo de tamaño dinámico mediante `sizeof` e iteración.

### 3. Recursividad y Matemática Computacional (`03_recursividad_y_algoritmos/`)
Resolución de problemas mediante llamadas recursivas y optimización de complejidad temporal:
- `invertir_numero.c`: Manipulación numérica cifra por cifra.
- `maximo_comun_divisor.c`: Implementación recursiva del clásico Algoritmo de Euclides.
- `numero_perfecto.c`: Algoritmo de detección de propiedades aritméticas de suma de divisores.
- `numero_primo.c`: Test de primalidad eficiente limitando iteraciones a la raíz cuadrada $\sqrt{N}$.

### 4. Estructuras de Datos No Lineales (`04_estructuras_de_datos/`)
Gestión dinámica de memoria mediante punteros (`malloc`/`free`):
- `arbol_binario.c`: Implementación de un Árbol Binario de Búsqueda (BST), inserción recursiva y recorrido en In-Order.
