# Algoritmos, Estructuras de Datos y Programación en C

Este repositorio contiene ejercicios prácticos desarrollados para los cursos universitarios de **Algoritmos y Programación I** y **Algoritmos y Programación II**, junto con proyectos de programación de sistemas (gestión de memoria, sockets TCP y persistencia en disco).

---

## Estructura del Repositorio

```text
.
├── .github/
│   └── workflows/
│       └── c-build.yml           # Verificación de compilación en GitHub Actions
├── docs/                         # Documentación de los módulos de la materia
│   ├── ALGORITMOS_I.md
│   └── ALGORITMOS_II.md
├── 01_algoritmos_1/              # Fundamentos de programación en C
│   ├── 01_condicionales/         # Estructuras condicionales (if, else, switch)
│   └── 02_bucles/                # Estructuras iterativas (for, while)
├── 02_algoritmos_2/              # Modularización y estructuras avanzadas
│   ├── 01_funciones/             # Definición y paso de parámetros
│   ├── 02_arreglos/              # Manejo de vectores
│   ├── 03_recursividad/          # Algoritmos recursivos
│   └── 04_estructuras_datos/     # Árbol Binario de Búsqueda (BST)
├── 03_proyectos_sistemas/        # Proyectos prácticos de programación de sistemas
│   ├── 01_key_value_store/       # Base de datos clave-valor con persistencia binaria
│   ├── 02_gestor_memoria/        # Asignador dinámico de memoria (Custom Malloc/Free)
│   └── 03_servidor_http/         # Servidor HTTP con sockets TCP
├── .gitignore                    # Archivos ignorados por Git
├── LICENSE                       # Licencia MIT
├── Makefile                      # Archivo de compilación automática
└── README.md                     # Documentación principal
```

---

## Proyectos de Sistemas

### 1. Base de Datos Clave-Valor (`03_proyectos_sistemas/01_key_value_store`)
Implementación de un almacenamiento clave-valor en memoria basado en una tabla hash con resolución de colisiones (*linear probing*) y persistencia binaria en disco.

### 2. Gestor de Memoria Dinámica (`03_proyectos_sistemas/02_gestor_memoria`)
Simulación de un asignador de memoria en el Heap (*custom malloc/free*) con estrategia *first-fit*, fusión de bloques contiguos libres (*coalescing*) y reporte de uso de memoria.

### 3. Servidor Web HTTP (`03_proyectos_sistemas/03_servidor_http`)
Servidor web multiplataforma (Sockets TCP en Windows Winsock2 y POSIX) capaz de procesar solicitudes GET, servir páginas HTML estáticas y responder endpoints JSON.

---

## Módulos Académicos

### Algoritmos I
- `calificaciones.c`: Conversión de notas a escala alfabética.
- `descuento_zapatos.c`: Cálculo de descuentos por volumen.
- `par_o_impar.c`: Comprobación de paridad de números enteros.
- `positivo_negativo.c`: Clasificación de signo numérico.
- `piedra_papel_tijera.c`: Juego de consola con selección aleatoria.
- `diez_numeros_naturales.c`: Impresión de secuencia con ciclo `while`.
- `tabla_multiplicar.c`: Generación de tabla de multiplicar con `for`.
- `rango_negativo_for.c`: Iteración en rangos negativos.
- `patron_numeros.c`: Patrón triangular de números.
- `conteo_digitos.c`: Conteo iterativo de dígitos de un entero.

### Algoritmos II
- `area_triangulo.c`: Función con retorno `double` para cálculo de área.
- `cuenta_regresiva.c`: Procedimiento `void` con ciclo descendente.
- `patron_asteriscos.c`: Dibujo de pirámides con funciones parametrizadas.
- `suma_dos_numeros.c`: Suma básica con prototipo de función.
- `tabla_multiplicar_func.c`: Generación modular de tablas de multiplicar.
- `promedio_lista.c`: Pasaje de vectores a funciones y cálculo con `sizeof`.
- `invertir_numero.c`: Inversión numérica cifra por cifra.
- `maximo_comun_divisor.c`: Algoritmo de Euclides recursivo.
- `numero_perfecto.c`: Verificación de números perfectos.
- `numero_primo.c`: Test de primalidad optimizado ($\sqrt{N}$).
- `arbol_binario.c`: Árbol binario de búsqueda (BST) con memoria dinámica.

---

## Compilación y Ejecución

Para compilar todo el proyecto usando `make`:

```bash
make all
```

Para compilar un archivo individual con `gcc`:

```bash
gcc -Wall -Wextra -std=c99 03_proyectos_sistemas/01_key_value_store/kv_store.c -o kv_store
./kv_store
```
