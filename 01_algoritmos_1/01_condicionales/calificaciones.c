/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Control Condicionales
 * Archivo    : calificaciones.c
 * Descripción: Clasifica la nota numérica de un estudiante en la escala A-F.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int nota;

    printf("Introduce tu calificación (0-100): ");
    if (scanf("%d", &nota) != 1) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    if (nota >= 100) {
        printf("Aprobaste con una A\n");
    } else if (nota >= 90) {
        printf("Aprobaste con una B\n");
    } else if (nota >= 80) {
        printf("Aprobaste con una C\n");
    } else if (nota >= 70) {
        printf("Aprobaste con una D\n");
    } else if (nota >= 60) {
        printf("Aprobaste con una E\n");
    } else if (nota >= 50) {
        printf("Aprobaste con una F\n");
    } else {
        printf("Reprobaste el curso\n");
    }

    return 0;
}
