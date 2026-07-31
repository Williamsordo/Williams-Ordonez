/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Repetición (Bucles)
 * Archivo    : rango_negativo_for.c
 * Descripción: Muestra números del -10 al -1 usando un ciclo 'for'.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int i;

    for (i = -10; i < 0; i++) {
        printf("%d\n", i);
    }

    return 0;
}
