/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación I
 * Módulo     : Estructuras de Control Condicionales
 * Archivo    : descuento_zapatos.c
 * Descripción: Calcula el total de venta de zapatos con descuentos por volumen.
 * ============================================================================
 */

#include <stdio.h>

int main(void) {
    int zapatos;
    float total, descuento;

    printf("Ingrese el número de zapatos que desea comprar: ");
    if (scanf("%d", &zapatos) != 1 || zapatos < 0) {
        printf("Error: Cantidad de zapatos no válida.\n");
        return 1;
    }

    total = zapatos * 80.0f;

    if (zapatos > 10 && zapatos <= 20) {
        descuento = total * 0.10f;
    } else if (zapatos > 20 && zapatos <= 30) {
        descuento = total * 0.20f;
    } else if (zapatos > 30) {
        descuento = total * 0.40f;
    } else {
        descuento = 0.0f;
    }

    total = total - descuento;

    printf("El total a pagar después del descuento es: $%.2f\n", total);

    return 0;
}
