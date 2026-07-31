/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Modularización y Funciones
 * Archivo    : tabla_multiplicar_func.c
 * Descripción: Función 'void' que imprime la tabla de multiplicar de un entero.
 * ============================================================================
 */

#include <stdio.h>

void tabla(int num) {
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
}

int main(void) {
    int num;

    printf("Ingrese un número: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    tabla(num);

    return 0;
}
