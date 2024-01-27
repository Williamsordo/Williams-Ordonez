#include <stdio.h>
#include <string.h> // Necesario para la función strcpy_s

int main() {
    char frase[100]; // Variable para almacenar la frase ingresada por el usuario
    char copia[100]; // Variable para almacenar la copia de la frase

    // Solicita al usuario una frase
    printf("Por favor, ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Crea una copia segura de la frase utilizando strcpy_s
    strcpy_s(copia, sizeof(copia), frase);

    // Muestra la frase original y su copia
    printf("Frase original: %s", frase);
    printf("Copia de la frase: %s", copia);

    return 0;
}
