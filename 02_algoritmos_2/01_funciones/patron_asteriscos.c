/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Modularización y Funciones
 * Archivo    : patron_asteriscos.c
 * Descripción: Dibuja un triángulo de asteriscos mediante una función paramétrica.
 * ============================================================================
 */

#include <stdio.h>

void patron(int filas) {
    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main(void) {
    int filas;

    printf("Ingrese el número de filas: ");
    if (scanf("%d", &filas) != 1 || filas <= 0) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    patron(filas);

    return 0;
}
