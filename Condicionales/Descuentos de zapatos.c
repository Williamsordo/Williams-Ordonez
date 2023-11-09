///*Hacer un programa en Cpara una tienda de zapatos que tiene una promoción de descuento para vender al mayor, esta dependerá del número de zapatos que se compren. Si son más de diez, se les dará un 10% de descuento sobre el total de la compra; si el número de zapatos es mayor de veinte pero menor de treinta, se le otorga un 20% de descuento; y si son más treinta zapatos se otorgará un 40% de descuento. El precio de cada zapato es de $80*///


#include <stdio.h>

int main() {
    int zapatos;
    float total, descuento;

    printf("Ingrese el número de zapatos que desea comprar: ");
    scanf("%d", &zapatos);

    total = zapatos * 80;

    if (zapatos > 10 && zapatos <= 20) {
        descuento = total * 0.10;
    } else if (zapatos > 20 && zapatos <= 30) {
        descuento = total * 0.20;
    } else if (zapatos > 30) {
        descuento = total * 0.40;
    } else {
        descuento = 0;
    }

    total = total - descuento;

    printf("El total a pagar después del descuento es: $%.2f\n", total);

    return 0;
}
