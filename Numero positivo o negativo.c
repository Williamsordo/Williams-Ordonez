///*Haz un programa que determine si un numero es negativo o positivo*///

///*Comprueba si el número es mayor que cero. Si es así, imprime que el número es positivo. Si el número no es mayor que cero, entonces comprueba si es menor que cero. Si es así, imprime que el número es negativo*//

#include <stdio.h>

int main() {
    int numero;

    printf("Por favor, ingrese un número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("El número es positivo.\n");
    } else if (numero < 0) {
        printf("El número es negativo.\n");
    } else {
        printf("El número es cero.\n");
    }

    return 0;
}
