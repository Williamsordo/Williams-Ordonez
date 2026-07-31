/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Control Condicionales
 * Archivo    : positivo_negativo.c
 * Descripción: Determina si un número es positivo, negativo o cero.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int numero;

    printf("Por favor, ingrese un número: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    if (numero > 0) {
        printf("El número es positivo.\n");
    } else if (numero < 0) {
        printf("El número es negativo.\n");
    } else {
        printf("El número es cero.\n");
    }

    return 0;
}
