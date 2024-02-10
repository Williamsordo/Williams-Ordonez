#include <stdio.h>
#include <math.h> // Necesario para las funciones ceil, floor y round

// Prototipo de la función para redondear hacia arriba
double redondear_hacia_arriba(double num);

// Prototipo de la función para redondear hacia abajo
double redondear_hacia_abajo(double num);

// Prototipo de la función para redondear al entero más cercano
double redondear_al_entero_cercano(double num);

int main() {
    double numero;

    printf("Por favor, ingrese un numero decimal: ");
    scanf("%lf", &numero);

    // Llamamos a las funciones para calcular los diferentes redondeos
    double redondeo_arriba = redondear_hacia_arriba(numero);
    double redondeo_abajo = redondear_hacia_abajo(numero);
    double redondeo_entero = redondear_al_entero_cercano(numero);

    printf("El valor redondeado hacia arriba de %.2lf es %.2lf\n", numero, redondeo_arriba);
    printf("El valor redondeado hacia abajo de %.2lf es %.2lf\n", numero, redondeo_abajo);
    printf("El valor redondeado al entero mas cercano de %.2lf es %.2lf\n", numero, redondeo_entero);

    return 0;
}

// Implementación de la función para redondear hacia arriba
double redondear_hacia_arriba(double num) {
    return ceil(num);
}

// Implementación de la función para redondear hacia abajo
double redondear_hacia_abajo(double num) {
    return floor(num);
}

// Implementación de la función para redondear al entero más cercano
double redondear_al_entero_cercano(double num) {
    return round(num);
}
