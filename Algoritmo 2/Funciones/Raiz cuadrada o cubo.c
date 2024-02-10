#include <stdio.h>
#include <math.h>

// Prototipos de las funciones
double calcular_cuadrado(double num);
double calcular_cubo(double num);
double calcular_raiz_cuadrada(double num);
double calcular_raiz_cubica(double num);

int main() {
    double numero;

    printf("Por favor, ingrese un numero: ");
    scanf("%lf", &numero);

    // Calcula y muestra el cuadrado del n�mero
    printf("El cuadrado de %.2lf es %.2lf\n", numero, calcular_cuadrado(numero));

    // Calcula y muestra el cubo del n�mero
    printf("El cubo de %.2lf es %.2lf\n", numero, calcular_cubo(numero));

    // Calcula y muestra la ra�z cuadrada del n�mero
    if (numero >= 0) {
        printf("La raiz cuadrada de %.2lf es %.2lf\n", numero, calcular_raiz_cuadrada(numero));
    } else {
        printf("La raiz cuadrada de %.2lf no est� definida en los n�meros reales\n", numero);
    }

    // Calcula y muestra la ra�z c�bica del n�mero
    printf("La raiz cubica de %.2lf es %.2lf\n", numero, calcular_raiz_cubica(numero));

    return 0;
}

// Implementaci�n de las funciones
double calcular_cuadrado(double num) {
    return pow(num, 2);
}

double calcular_cubo(double num) {
    return pow(num, 3);
}

double calcular_raiz_cuadrada(double num) {
    return sqrt(num);
}

double calcular_raiz_cubica(double num) {
    return cbrt(num);
}

