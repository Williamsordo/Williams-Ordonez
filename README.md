# 🎓 Algoritmos, Estructuras de Datos y Sistemas en C - Portafolio Profesional

![C Build Status](https://github.com/Williamsordo/Williams-Ordonez/actions/workflows/c-build.yml/badge.svg)
![Standard](https://img.shields.io/badge/c-C99%2FC11-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

Este repositorio alberga un **portafolio profesional de desarrollo de sistemas, estructuras de datos avanzadas y fundamentos de programación en C**, estructurado bajo estándares de código limpio de la industria y validado con **Integración Continua (GitHub Actions CI/CD)**.

---

## 🏛️ Estructura del Repositorio

```text
.
├── .github/
│   └── workflows/
│       └── c-build.yml                   # CI/CD: Compilación automatizada en cada push
├── docs/                                 # Documentación detallada por materia
│   ├── ALGORITMOS_I.md                   # Programa temático de Algoritmos I
│   └── ALGORITMOS_II.md                  # Programa temático de Algoritmos II
├── 01_algoritmos_1/                      # Fundamentos de programación
│   ├── 01_condicionales/                 # Toma de decisiones (if, else, switch)
│   └── 02_bucles/                        # Estructuras iterativas (for, while)
├── 02_algoritmos_2/                      # Modularización y algoritmos avanzados
│   ├── 01_funciones/                     # Programación modular
│   ├── 02_arreglos/                      # Vectores y estructuras estáticas
│   ├── 03_recursividad_y_algoritmos/     # Algoritmos recursivos y teoría de números
│   └── 04_estructuras_de_datos/          # Árboles Binarios de Búsqueda (BST)
├── 03_proyectos_destacados/              # 🔥 PROYECTOS DE ALTO IMPACTO (Nivel Senior)
│   ├── 01_key_value_store/               # Motor de Base de Datos KV con Persistencia
│   ├── 02_gestor_memoria_dinamica/       # Custom Malloc & Free Heap Allocator
│   └── 03_servidor_web_http/             # Micro Servidor Web HTTP & API REST Sockets
├── .gitignore                            # Filtro para ejecutables y temporales
├── LICENSE                               # Licencia de código abierto MIT
├── Makefile                              # Automatización de compilación con 'make'
└── README.md                             # Documentación principal
```

---

## 🔥 Proyectos Destacados (Nivel Senior / Sistemas Operativos)

Estos 3 proyectos demuestran dominio en gestión de memoria, algoritmos complejos, programación de red mediante sockets y persistencia de datos:

### 1. 🗄️ Motor de Base de Datos Key-Value con Persistencia (`03_proyectos_destacados/01_key_value_store`)
- **Descripción**: Implementación de un motor de almacenamiento en memoria estilo Redis/SQLite.
- **Conceptos**: Tabla Hash con *linear probing* para resolución de colisiones ($O(1)$ lookup), persistencia de datos binaria a disco (`.db`), comandos `SET`, `GET`, `DELETE` y serialización de estructuras.

### 2. 🧠 Custom Dynamic Memory Allocator & Pool Manager (`03_proyectos_destacados/02_gestor_memoria_dinamica`)
- **Descripción**: Simulador de asignador dinámico de memoria estilo `malloc` y `free` de bajo nivel.
- **Conceptos**: Gestión de cabeceras de bloques de memoria en el Heap, algoritmo *First-Fit*, fusión de memoria contigua libre (*Coalescing*) para prevenir fragmentación y diagnóstico de fugas de memoria (*Memory Leaks*).

### 3. 🌐 Micro Servidor Web HTTP & API REST (`03_proyectos_destacados/03_servidor_web_http`)
- **Descripción**: Servidor HTTP multiplataforma desarrollado en C puro con Sockets TCP (Winsock2 / POSIX).
- **Conceptos**: Protocolo TCP/IP, parsing de encabezados HTTP GET, despacho de archivos estáticos HTML y endpoints de API REST JSON (`/api/status`).

---

## 📘 Módulos Académicos Universitaos

### 🟢 [Algoritmos y Programación I](docs/ALGORITMOS_I.md)
| Módulo | Archivo | Descripción |
|---|---|---|
| **Condicionales** | [`calificaciones.c`](01_algoritmos_1/01_condicionales/calificaciones.c) | Clasificación de notas (A-F). |
| **Condicionales** | [`descuento_zapatos.c`](01_algoritmos_1/01_condicionales/descuento_zapatos.c) | Lógica de descuentos al por mayor. |
| **Condicionales** | [`par_o_impar.c`](01_algoritmos_1/01_condicionales/par_o_impar.c) | Evaluación de paridad con operador residuo `%`. |
| **Condicionales** | [`positivo_negativo.c`](01_algoritmos_1/01_condicionales/positivo_negativo.c) | Evaluación de signo numérico. |
| **Condicionales** | [`piedra_papel_tijera.c`](01_algoritmos_1/01_condicionales/piedra_papel_tijera.c) | Juego interactivo en consola (`rand()`). |
| **Bucles** | [`diez_numeros_naturales.c`](01_algoritmos_1/02_bucles/diez_numeros_naturales.c) | Secuencia natural con `while`. |
| **Bucles** | [`tabla_multiplicar.c`](01_algoritmos_1/02_bucles/tabla_multiplicar.c) | Tabla de multiplicar con `for`. |
| **Bucles** | [`rango_negativo_for.c`](01_algoritmos_1/02_bucles/rango_negativo_for.c) | Recorrido con decrementos. |
| **Bucles** | [`patron_numeros.c`](01_algoritmos_1/02_bucles/patron_numeros.c) | Matriz triangular con ciclos anidados. |
| **Bucles** | [`conteo_digitos.c`](01_algoritmos_1/02_bucles/conteo_digitos.c) | Conteo e iteración de cifras. |

### 🟡 [Algoritmos y Programación II](docs/ALGORITMOS_II.md)
| Módulo | Archivo | Descripción |
|---|---|---|
| **Funciones** | [`area_triangulo.c`](02_algoritmos_2/01_funciones/area_triangulo.c) | Retorno `double` y cálculo geométrico. |
| **Funciones** | [`cuenta_regresiva.c`](02_algoritmos_2/01_funciones/cuenta_regresiva.c) | Procedimiento `void`. |
| **Funciones** | [`patron_asteriscos.c`](02_algoritmos_2/01_funciones/patron_asteriscos.c) | Renderizado con parámetros. |
| **Funciones** | [`suma_dos_numeros.c`](02_algoritmos_2/01_funciones/suma_dos_numeros.c) | Suma con retorno de entero. |
| **Funciones** | [`tabla_multiplicar_func.c`](02_algoritmos_2/01_funciones/tabla_multiplicar_func.c) | Impresión modularizada. |
| **Arreglos** | [`promedio_lista.c`](02_algoritmos_2/02_arreglos/promedio_lista.c) | Arreglos como parámetros y cálculo `sizeof`. |
| **Recursividad** | [`invertir_numero.c`](02_algoritmos_2/03_recursividad_y_algoritmos/invertir_numero.c) | Inversión de cifras. |
| **Recursividad** | [`maximo_comun_divisor.c`](02_algoritmos_2/03_recursividad_y_algoritmos/maximo_comun_divisor.c) | Algoritmo de Euclides recursivo. |
| **Recursividad** | [`numero_perfecto.c`](02_algoritmos_2/03_recursividad_y_algoritmos/numero_perfecto.c) | Sumatoria de divisores propios. |
| **Recursividad** | [`numero_primo.c`](02_algoritmos_2/03_recursividad_y_algoritmos/numero_primo.c) | Evaluación de primalidad optimizada $\sqrt{N}$. |
| **Estructuras** | [`arbol_binario.c`](02_algoritmos_2/04_estructuras_de_datos/arbol_binario.c) | Árbol Binario de Búsqueda (BST) y punteros. |

---

## 🛠️ Compilación y Ejecución

```bash
# Compilar todo con Make
make all

# O compilar un proyecto avanzado manualmente (ej: Key-Value Store)
gcc -Wall -Wextra -std=c99 03_proyectos_destacados/01_key_value_store/kv_store.c -o kv_store.exe
.\kv_store.exe
```

---
*Desarrollado por Williams Ordóñez.*
