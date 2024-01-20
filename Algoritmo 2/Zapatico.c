#include <stdio.h> 

int main() { 
    int cantidad; // Declara una variable entera llamada 'cantidad'
    float precio = 80.0, total, descuento; // Declara las variables 'precio', 'total' y 'descuento'

    printf("Introduce la cantidad de zapatos comprados: "); // Solicita al usuario que introduzca la cantidad de zapatos comprados
    scanf("%d", &cantidad); // Lee la cantidad introducida por el usuario

    total = cantidad * precio; // Calcula el total sin descuento multiplicando la cantidad por el precio

    if(cantidad > 10 && cantidad <= 20) { // Si la cantidad es mayor a 10 y menor o igual a 20
        descuento = total * 0.10; // El descuento es el 10% del total
    } else if(cantidad > 20 && cantidad <= 30) { // Si la cantidad es mayor a 20 y menor o igual a 30
        descuento = total * 0.20; // El descuento es el 20% del total
    } else if(cantidad > 30) { // Si la cantidad es mayor a 30
        descuento = total * 0.40; // El descuento es el 40% del total
    } else { // Si no
        descuento = 0; // No hay descuento
    }

    total = total - descuento; // Calcula el total con descuento restando el descuento al total sin descuento

    printf("El descuento es: $%.2f\n", descuento); // Imprime el descuento
    printf("El total a pagar es: $%.2f\n", total); // Imprime el total a pagar

    return 0; // Termina la ejecución del programa
}
