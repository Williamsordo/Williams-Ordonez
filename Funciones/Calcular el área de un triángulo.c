#include <stdio.h>

double areaTriangulo(double base, double altura) {
    return (base * altura) / 2;
}

int main() {
    double base, altura;
    printf("Ingrese la base y la altura del triángulo: ");
    scanf("%lf %lf", &base, &altura);
    printf("El área del triángulo es %.2f", areaTriangulo(base, altura));
    return 0;
}

