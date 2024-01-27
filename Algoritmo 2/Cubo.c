#include <stdio.h>
#include <math.h>
// Necesario para las funciones sqrt y cbrt

int main() {
    double numero; // Variable para almacenar el número ingresado por el usuario

    // Solicita al usuario un número
    printf("Por favor, ingrese un número: ");
    scanf("%lf", &numero);

    // Calcula y muestra el cuadrado del número
    printf("El cuadrado de %.2lf es %.2lf\n", numero, pow(numero, 2));

    // Calcula y muestra el cubo del número
    printf("El cubo de %.2lf es %.2lf\n", numero, pow(numero, 3));

    // Calcula y muestra la raíz cuadrada del número
    if (numero >= 0) {
        printf("La raíz cuadrada de %.2lf es %.2lf\n", numero, sqrt(numero));
    } else {
        printf("La raíz cuadrada de %.2lf no está definida en los números reales\n", numero);
    }

    // Calcula y muestra la raíz cúbica del número
    printf("La raíz cúbica de %.2lf es %.2lf\n", numero, cbrt(numero));

    return 0;
}
