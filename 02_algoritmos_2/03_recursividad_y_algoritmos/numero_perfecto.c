/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Recursividad y Matemática Computacional
 * Archivo    : numero_perfecto.c
 * Descripción: Determina si la suma de los divisores propios es igual al número.
 * ============================================================================
 */

#include <stdio.h>

int esPerfecto(int num) {
    if (num <= 0) return 0;

    int suma = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return (suma == num);
}

int main(void) {
    int num;

    printf("Ingrese un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    if (esPerfecto(num)) {
        printf("%d es un número perfecto.\n", num);
    } else {
        printf("%d no es un número perfecto.\n", num);
    }

    return 0;
}
