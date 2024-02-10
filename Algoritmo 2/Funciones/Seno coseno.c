#include <stdio.h>
#include <math.h>

#define PI 3.1415926536

// Prototipos de las funciones
float calcular_seno(float angulo);
float calcular_coseno(float angulo);
float calcular_tangente(float angulo);

int main() {
    float x, rad, seno, coseno, tangente;

    printf("Ingresa un angulo en grados: ");
    scanf("%f", &x);

    rad = x * PI / 180;

    // Llamamos a las funciones para calcular seno, coseno y tangente
    seno = calcular_seno(rad);
    coseno = calcular_coseno(rad);
    tangente = calcular_tangente(rad);

    printf("El seno = %.4f\n", seno);
    printf("El coseno = %.4f\n", coseno);
    printf("La tangente = %.4f\n", tangente);

    return 0;
}

// Implementación de las funciones
float calcular_seno(float angulo) {
    return sin(angulo);
}

float calcular_coseno(float angulo) {
    return cos(angulo);
}

float calcular_tangente(float angulo) {
    return tan(angulo);
}
