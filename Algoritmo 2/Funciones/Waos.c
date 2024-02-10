#include <stdio.h>
#include <string.h>

// Función para comparar dos cadenas
int comparar(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

// Función para ordenar las palabras
void ordenarPalabras(char *palabras[], int numPalabras) {
    qsort(palabras, numPalabras, sizeof(char *), comparar);
}

int main() {
    int numPalabras = 5;
    char *palabras[numPalabras];

    // Leer las palabras desde el usuario
    printf("Ingresa %d palabras:\n", numPalabras);
    for (int i = 0; i < numPalabras; i++) {
        char palabra[100];
        scanf("%s", palabra);
        palabras[i] = strdup(palabra); // Almacenar una copia de la palabra
    }

    // Ordenar las palabras
    ordenarPalabras(palabras, numPalabras);

    // Imprimir las palabras ordenadas
    printf("Palabras ordenadas por longitud:\n");
    for (int i = 0; i < numPalabras; i++) {
        printf("%s\n", palabras[i]);
        free(palabras[i]); // Liberar la memoria asignada
    }

    return 0;
}
