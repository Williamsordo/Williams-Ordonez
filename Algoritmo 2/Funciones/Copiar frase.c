#include <stdio.h>
#include <stdlib.h> // Necesario para malloc y free
#include <string.h>

// Prototipo de la función para copiar la frase
void copiar_frase(const char *frase_original, char **copia);

int main() {
    char frase[100];
    char *copia = NULL; // Puntero a la copia de la frase

    printf("Por favor, ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Llamamos a la función para copiar la frase
    copiar_frase(frase, &copia);

    printf("Frase original: %s", frase);
    printf("Copia de la frase: %s", copia);

    // Liberamos la memoria asignada
    free(copia);

    return 0;
}

// Implementación de la función para copiar la frase
void copiar_frase(const char *frase_original, char **copia) {
    // Calculamos la longitud de la frase original
    size_t longitud = strlen(frase_original);

    // Asignamos memoria para la copia
    *copia = (char *)malloc(longitud + 1); // +1 para el carácter nulo

    if (*copia != NULL) {
        // Copiamos la frase original a la copia
        strncpy(*copia, frase_original, longitud);
        (*copia)[longitud] = '\0'; // Aseguramos que la copia termine con un carácter nulo
    } else {
        printf("Error al asignar memoria para la copia.\n");
    }
}
