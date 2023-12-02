#include <stdio.h>

void patron(int filas) {
    for(int i = 1; i <= filas; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int filas;
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    patron(filas);
    return 0;
}

