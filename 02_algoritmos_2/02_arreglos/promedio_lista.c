/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Arreglos y Estructuras de Datos
 * Archivo    : promedio_lista.c
 * Descripción: Función que calcula el promedio de los elementos en un arreglo.
 * ============================================================================
 */

#include <stdio.h>

double promedio(const int arr[], int tam) {
    if (tam <= 0) return 0.0;

    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return (double)suma / tam;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("El promedio es %.2f\n", promedio(arr, tam));

    return 0;
}
