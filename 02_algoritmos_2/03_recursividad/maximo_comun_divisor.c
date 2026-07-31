/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Recursividad y Matemática Computacional
 * Archivo    : maximo_comun_divisor.c
 * Descripción: Algoritmo recursivo de Euclides para hallar el MCD de dos números.
 * ============================================================================
 */

#include <stdio.h>

int mcd(int a, int b) {
    if (b != 0)
        return mcd(b, a % b);
    else
        return a;
}

int main(void) {
    int num1, num2;

    printf("Ingrese dos números: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    printf("El MCD de %d y %d es %d\n", num1, num2, mcd(num1, num2));

    return 0;
}
