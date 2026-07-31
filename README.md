# 🎓 Algoritmos y Programación - Portafolio de Ejercicios en C

![C Build Status](https://github.com/Williamsordo/Williams-Ordonez/actions/workflows/c-build.yml/badge.svg)
![Standard](https://img.shields.io/badge/c-C99%2FC11-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

Este repositorio contiene la colección oficial de ejercicios prácticos desarrollados durante las materias académicas de **Algoritmos y Programación I** y **Algoritmos y Programación II** en la universidad.

La arquitectura del repositorio sigue las mejores prácticas de la industria, estructurada de manera limpia, modular e integrada con **CI/CD (GitHub Actions)** para garantizar que todo el código compile sin errores.

---

## 🏛️ Estructura del Repositorio

```text
.
├── .github/
│   └── workflows/
│       └── c-build.yml                   # CI/CD: Compilación y validación automática
├── docs/                                 # Documentación detallada por materia
│   ├── ALGORITMOS_I.md                   # Temario y programa de Algoritmos I
│   └── ALGORITMOS_II.md                  # Temario y programa de Algoritmos II
├── 01_algoritmos_1/                      # Fundamentos de programación en C
│   ├── 01_condicionales/                 # Estructuras de decisión (if, else, switch)
│   └── 02_bucles/                        # Estructuras iterativas (for, while)
├── 02_algoritmos_2/                      # Programación modular y algoritmos avanzados
│   ├── 01_funciones/                     # Definición de funciones y parámetros
│   ├── 02_arreglos/                      # Estructuras de datos estáticas (vectores)
│   └── 03_recursividad_y_algoritmos/     # Recursividad y matemática computacional
├── .gitignore                            # Filtro para binarios y archivos temporales
├── LICENSE                               # Licencia de código abierto MIT
├── Makefile                              # Automatización de compilación
└── README.md                             # Documentación principal del repositorio
```

---

## 📘 Módulos Académicos

### 🟢 [Algoritmos y Programación I](docs/ALGORITMOS_I.md)
| Categoría | Archivo | Descripción |
|---|---|---|
| **Condicionales** | [`calificaciones.c`](01_algoritmos_1/01_condicionales/calificaciones.c) | Clasificación de notas (A-F). |
| **Condicionales** | [`descuento_zapatos.c`](01_algoritmos_1/01_condicionales/descuento_zapatos.c) | Lógica de descuentos al por mayor. |
| **Condicionales** | [`par_o_impar.c`](01_algoritmos_1/01_condicionales/par_o_impar.c) | Determinación de paridad mediante el operador residuo `%`. |
| **Condicionales** | [`positivo_negativo.c`](01_algoritmos_1/01_condicionales/positivo_negativo.c) | Evaluación de signo numérico. |
| **Condicionales** | [`piedra_papel_tijera.c`](01_algoritmos_1/01_condicionales/piedra_papel_tijera.c) | Juego interactivo contra la consola (`rand()`). |
| **Bucles** | [`diez_numeros_naturales.c`](01_algoritmos_1/02_bucles/diez_numeros_naturales.c) | Secuencia natural usando `while`. |
| **Bucles** | [`tabla_multiplicar.c`](01_algoritmos_1/02_bucles/tabla_multiplicar.c) | Tabla de multiplicar con `for`. |
| **Bucles** | [`rango_negativo_for.c`](01_algoritmos_1/02_bucles/rango_negativo_for.c) | Recorrido con valores decrecientes. |
| **Bucles** | [`patron_numeros.c`](01_algoritmos_1/02_bucles/patron_numeros.c) | Matriz triangular con ciclos anidados. |
| **Bucles** | [`conteo_digitos.c`](01_algoritmos_1/02_bucles/conteo_digitos.c) | Descomposición numérica e iteración. |

### 🟡 [Algoritmos y Programación II](docs/ALGORITMOS_II.md)
| Categoría | Archivo | Descripción |
|---|---|---|
| **Funciones** | [`area_triangulo.c`](02_algoritmos_2/01_funciones/area_triangulo.c) | Cálculo del área con retorno `double`. |
| **Funciones** | [`cuenta_regresiva.c`](02_algoritmos_2/01_funciones/cuenta_regresiva.c) | Procedimiento secuencial `void`. |
| **Funciones** | [`patron_asteriscos.c`](02_algoritmos_2/01_funciones/patron_asteriscos.c) | Renderizado de patrones mediante parámetros. |
| **Funciones** | [`suma_dos_numeros.c`](02_algoritmos_2/01_funciones/suma_dos_numeros.c) | Invocación de función matemática. |
| **Funciones** | [`tabla_multiplicar_func.c`](02_algoritmos_2/01_funciones/tabla_multiplicar_func.c) | Modularización de impresión de tablas. |
| **Arreglos** | [`promedio_lista.c`](02_algoritmos_2/02_arreglos/promedio_lista.c) | Paso de vectores y cálculo dinámico con `sizeof`. |
| **Recursividad** | [`invertir_numero.c`](02_algoritmos_2/03_recursividad_y_algoritmos/invertir_numero.c) | Inversión de posiciones numéricas. |
| **Recursividad** | [`maximo_comun_divisor.c`](02_algoritmos_2/03_recursividad_y_algoritmos/maximo_comun_divisor.c) | Algoritmo de Euclides recursivo. |
| **Recursividad** | [`numero_perfecto.c`](02_algoritmos_2/03_recursividad_y_algoritmos/numero_perfecto.c) | Sumatoria de divisores propios. |
| **Recursividad** | [`numero_primo.c`](02_algoritmos_2/03_recursividad_y_algoritmos/numero_primo.c) | Evaluación de primalidad optimizada $\sqrt{N}$. |

---

## 🛠️ Compilación y Ejecución

### Opción 1: Usando `make` (Linux / macOS / WSL / Git Bash con MinGW)
```bash
# Compilar todos los ejercicios del repositorio
make all

# Limpiar ejecutables y archivos objeto
make clean
```

### Opción 2: Compilación manual con `gcc` (Windows / Linux)
```bash
# Ejemplo: Compilar un ejercicio de Algoritmos I
gcc -Wall -Wextra -std=c99 01_algoritmos_1/01_condicionales/calificaciones.c -o calificaciones.exe

# Ejecutar en Windows
.\calificaciones.exe

# Ejecutar en Linux/macOS
./calificaciones.out
```

---

## 🚀 Integración Continua (CI/CD)
El repositorio cuenta con una integración automática mediante **GitHub Actions** (`.github/workflows/c-build.yml`). Cada vez que realices un `git push` o crees un `pull request`, GitHub verificará automáticamente la compilación sin errores de todos los archivos `.c`.

---
*Desarrollado por Williams Ordóñez - Formación Universitaria en Ingeniería.*
