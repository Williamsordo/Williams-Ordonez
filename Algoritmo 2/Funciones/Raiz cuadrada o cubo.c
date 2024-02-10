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

    // Calcula y muestra el cuadrado del número
    printf("El cuadrado de %.2lf es %.2lf\n", numero, calcular_cuadrado(numero));

    // Calcula y muestra el cubo del número
    printf("El cubo de %.2lf es %.2lf\n", numero, calcular_cubo(numero));

    // Calcula y muestra la raíz cuadrada del número
    if (numero >= 0) {
        printf("La raiz cuadrada de %.2lf es %.2lf\n", numero, calcular_raiz_cuadrada(numero));
    } else {
        printf("La raiz cuadrada de %.2lf no está definida en los números reales\n", numero);
    }

    // Calcula y muestra la raíz cúbica del número
    printf("La raiz cubica de %.2lf es %.2lf\n", numero, calcular_raiz_cubica(numero));

    return 0;
}

// Implementación de las funciones
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

