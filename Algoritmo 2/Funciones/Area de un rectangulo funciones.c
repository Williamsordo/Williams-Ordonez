#include <stdio.h>

// Prototipo de la funci�n para calcular el �rea del rect�ngulo
float calcular_area_rectangulo(float base, float altura);

int main() {
    float base, altura, area;

    printf("Introduce la base del rectangulo: ");
    scanf("%f", &base);

    printf("Introduce la altura del rectangulo: ");
    scanf("%f", &altura);

    // Llamamos a la funci�n para calcular el �rea
    area = calcular_area_rectangulo(base, altura);

    if (area > 40 && altura > 10) {
        printf("El area del rectangulo es %.2f y es mayor a 40. Adem�s, la altura es %.2f y es mayor a 10.", area, altura);
    } else {
        printf("El area del rectangulo es %.2f y la altura es %.2f.", area, altura);
    }

    return 0;
}

// Implementaci�n de la funci�n para calcular el �rea del rect�ngulo
float calcular_area_rectangulo(float base, float altura) {
    return base * altura;
}

