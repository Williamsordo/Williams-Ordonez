#include <stdio.h>

int main() {
    int numero;
    printf("Introduce un número: ");
    scanf("%d", &numero);

    if(numero % 2 == 0)
        printf("%d es un número par.\n", numero);
    else
        printf("%d es un número impar.\n", numero);

    return 0;
}
