#include <stdio.h>
#include <math.h>
// Necesario para las funciones sqrt y cbrt

int main() {
    double numero; // Variable para almacenar el n�mero ingresado por el usuario

    // Solicita al usuario un n�mero
    printf("Por favor, ingrese un n�mero: ");
    scanf("%lf", &numero);

    // Calcula y muestra el cuadrado del n�mero
    printf("El cuadrado de %.2lf es %.2lf\n", numero, pow(numero, 2));

    // Calcula y muestra el cubo del n�mero
    printf("El cubo de %.2lf es %.2lf\n", numero, pow(numero, 3));

    // Calcula y muestra la ra�z cuadrada del n�mero
    if (numero >= 0) {
        printf("La ra�z cuadrada de %.2lf es %.2lf\n", numero, sqrt(numero));
    } else {
        printf("La ra�z cuadrada de %.2lf no est� definida en los n�meros reales\n", numero);
    }

    // Calcula y muestra la ra�z c�bica del n�mero
    printf("La ra�z c�bica de %.2lf es %.2lf\n", numero, cbrt(numero));

    return 0;
}
