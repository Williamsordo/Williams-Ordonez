#include <stdio.h>
#include <math.h> // Necesario para las funciones ceil, floor y round

int main() {
    double numero; // Variable para almacenar el n�mero decimal ingresado por el usuario

    // Solicita al usuario un n�mero decimal
    printf("Por favor, ingrese un numero decimal: ");
    scanf("%lf", &numero);

    // Calcula y muestra el valor redondeado hacia arriba del n�mero
    printf("El valor redondeado hacia arriba de %.2lf es %.2lf\n", numero, ceil(numero));

    // Calcula y muestra el valor redondeado hacia abajo del n�mero
    printf("El valor redondeado hacia abajo de %.2lf es %.2lf\n", numero, floor(numero));

    // Calcula y muestra el valor redondeado al entero m�s cercano del n�mero
    printf("El valor redondeado al entero mas cercano de %.2lf es %.2lf\n", numero, round(numero));

    return 0;
}
