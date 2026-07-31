/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Repetición (Bucles)
 * Archivo    : conteo_digitos.c
 * Descripción: Cuenta e imprime la cantidad total de dígitos de un número.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int num, temp;
    int count = 0;

    printf("Introduce un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    temp = num;

    if (temp == 0) {
        count = 1;
    } else {
        while (temp != 0) {
            temp /= 10;
            ++count;
        }
    }

    printf("Número total de dígitos: %d\n", count);

    return 0;
}
