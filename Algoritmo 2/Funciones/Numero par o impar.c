#include <stdio.h>

// Prototipo de la función para verificar si un número es par o impar
int verificar_paridad(int num);

int main() {
    int num;

    printf("Introduce un numero: ");
    scanf("%d", &num);

    // Llamamos a la función para verificar la paridad del número
    int resultado = verificar_paridad(num);

    if (resultado == 0)
        printf("%d es un numero par.\n", num);
    else
        printf("%d es un numero impar.\n", num);

    return 0;
}

// Implementación de la función para verificar la paridad
int verificar_paridad(int num) {
    // Si el residuo de la división del número entre 2 es igual a 0, es par
    // De lo contrario, es impar
    return num % 2;
}
