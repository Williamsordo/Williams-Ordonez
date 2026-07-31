/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Control Condicionales
 * Archivo    : piedra_papel_tijera.c
 * Descripción: Simula el juego Piedra, Papel o Tijera contra la computadora.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int usuario, computadora;

    printf("Ingrese su elección (1: Piedra, 2: Papel, 3: Tijera): ");
    if (scanf("%d", &usuario) != 1 || usuario < 1 || usuario > 3) {
        printf("Error: Opción inválida. Debe ser 1, 2 o 3.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));
    computadora = rand() % 3 + 1;

    printf("La computadora eligió: ");
    switch (computadora) {
        case 1: printf("Piedra (1)\n"); break;
        case 2: printf("Papel (2)\n"); break;
        case 3: printf("Tijera (3)\n"); break;
    }

    if (usuario == computadora) {
        printf("Es un empate.\n");
    } else if ((usuario == 1 && computadora == 3) ||
               (usuario == 2 && computadora == 1) ||
               (usuario == 3 && computadora == 2)) {
        printf("¡Ganaste!\n");
    } else {
        printf("Perdiste.\n");
    }

    return 0;
}
