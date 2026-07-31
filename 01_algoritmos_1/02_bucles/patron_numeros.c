/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Repetición (Bucles)
 * Archivo    : patron_numeros.c
 * Descripción: Genera un patrón triangular numérico con bucles anidados.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
