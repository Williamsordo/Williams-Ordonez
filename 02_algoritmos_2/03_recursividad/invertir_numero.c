/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Recursividad y Matemática Computacional
 * Archivo    : invertir_numero.c
 * Descripción: Función que invierte el orden numérico de las cifras de un entero.
 * ============================================================================
 */

#include <stdio.h>

int invertir(int num) {
    int rev = 0;
    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main(void) {
    int num;

    printf("Ingrese un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    printf("Número invertido: %d\n", invertir(num));

    return 0;
}
