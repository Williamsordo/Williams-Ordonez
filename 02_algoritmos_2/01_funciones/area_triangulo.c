/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Modularización y Funciones
 * Archivo    : area_triangulo.c
 * Descripción: Función para calcular el área de un triángulo dada base y altura.
 * ============================================================================
 */

#include <stdio.h>

double areaTriangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

int main(void) {
    double base, altura;

    printf("Ingrese la base y la altura del triángulo: ");
    if (scanf("%lf %lf", &base, &altura) != 2) {
        printf("Error: Entrada no válida.\n");
        return 1;
    }

    printf("El área del triángulo es %.2f\n", areaTriangulo(base, altura));

    return 0;
}
