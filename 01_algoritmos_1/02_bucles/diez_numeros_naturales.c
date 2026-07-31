/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Repetición (Bucles)
 * Archivo    : diez_numeros_naturales.c
 * Descripción: Imprime los primeros 10 números naturales usando 'while'.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int i = 1;

    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
