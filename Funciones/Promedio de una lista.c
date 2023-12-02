#include <stdio.h>

double promedio(int arr[], int tam) {
    int suma = 0;
    for(int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return (double)suma / tam;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int tam = sizeof(arr) / sizeof(arr[0]);
    printf("El promedio es %.2f", promedio(arr, tam));
    return 0;
}
