#include <stdio.h>
#include <string.h> // Necesario para la función strcmp

int main() {
    char palabra1[50]; // Variable para almacenar la primera palabra ingresada por el usuario
    char palabra2[50]; // Variable para almacenar la segunda palabra ingresada por el usuario

    // Solicita al usuario la primera palabra
    printf("Por favor, ingrese la primera palabra: ");
    scanf("%s", palabra1);

    // Solicita al usuario la segunda palabra
    printf("Por favor, ingrese la segunda palabra: ");
    scanf("%s", palabra2);

    // Compara las dos palabras y muestra si son iguales o no
    if (strcmp(palabra1, palabra2) == 0) {
        printf("Las palabras son iguales.\n");
    } else {
        printf("Las palabras no son iguales.\n");
    }

    return 0;
}
