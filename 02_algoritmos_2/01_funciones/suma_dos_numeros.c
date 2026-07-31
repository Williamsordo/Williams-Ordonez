/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Modularización y Funciones
 * Archivo    : suma_dos_numeros.c
 * Descripción: Función básica que calcula y retorna la suma de dos enteros.
 * ============================================================================
 */

#include <stdio.h>

int suma(int a, int b) {
    return a + b;
}

int main(void) {
    int num1 = 5, num2 = 10;
    printf("La suma de %d y %d es %d\n", num1, num2, suma(num1, num2));
    return 0;
}
