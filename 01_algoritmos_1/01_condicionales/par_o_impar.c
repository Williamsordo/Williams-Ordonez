/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Control Condicionales
 * Archivo    : par_o_impar.c
 * Descripción: Determina si un número entero es par o impar.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int numero;

    printf("Introduce un número entero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    if (numero % 2 == 0) {
        printf("%d es un número par.\n", numero);
    } else {
        printf("%d es un número impar.\n", numero);
    }

    return 0;
}
