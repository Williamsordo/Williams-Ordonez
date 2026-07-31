/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Repetición (Bucles)
 * Archivo    : tabla_multiplicar.c
 * Descripción: Genera la tabla de multiplicar de un entero dado usando 'for'.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int num, i;

    printf("Introduce un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    for (i = 1; i <= 10; ++i) {
        printf("%d * %d = %d\n", num, i, num * i);
    }

    return 0;
}
