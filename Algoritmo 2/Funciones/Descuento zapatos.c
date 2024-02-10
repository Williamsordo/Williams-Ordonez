#include <stdio.h>

// Prototipo de la función para calcular el descuento
float calcular_descuento(int cantidad, float precio);

int main() {
    int cantidad;
    float precio = 80.0, total, descuento;

    printf("Introduce la cantidad de zapatos comprados: ");
    scanf("%d", &cantidad);

    total = cantidad * precio;

    // Llamamos a la función para calcular el descuento
    descuento = calcular_descuento(cantidad, total);

    total = total - descuento;

    printf("El descuento es: $%.2f\n", descuento);
    printf("El total a pagar es: $%.2f\n", total);

    return 0;
}

// Implementación de la función para calcular el descuento
float calcular_descuento(int cantidad, float total) {
    float descuento;
    if (cantidad > 10 && cantidad <= 20) {
        descuento = total * 0.10;
    } else if (cantidad > 20 && cantidad <= 30) {
        descuento = total * 0.20;
    } else if (cantidad > 30) {
        descuento = total * 0.40;
    } else {
        descuento = 0;
    }
    return descuento;
}
