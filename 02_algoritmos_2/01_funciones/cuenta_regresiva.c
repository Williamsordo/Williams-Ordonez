/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Modularización y Funciones
 * Archivo    : cuenta_regresiva.c
 * Descripción: Función 'void' para simular una cuenta regresiva.
 * ============================================================================
 */

#include <stdio.h>

void cuentaRegresiva(void) {
    for (int i = 10; i > 0; i--) {
        printf("%d\n", i);
    }
    printf("¡Despegue!\n");
}

int main(void) {
    cuentaRegresiva();
    return 0;
}
