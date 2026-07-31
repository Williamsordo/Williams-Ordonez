/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Recursividad y Matemática Computacional
 * Archivo    : numero_primo.c
 * Descripción: Algoritmo optimizado para la evaluación de números primos.
 * ============================================================================
 */

#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    int num;

    printf("Ingrese un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    if (esPrimo(num)) {
        printf("%d es un número primo.\n", num);
    } else {
        printf("%d no es un número primo.\n", num);
    }

    return 0;
}
