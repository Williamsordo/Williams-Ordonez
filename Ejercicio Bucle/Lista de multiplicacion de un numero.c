//*Escribir un programa para imprimir la tabla de multiplicar de un número dado*//

#include <stdio.h>

int main() {
    int num, i;
    printf("Introduce un número: ");
    scanf("%d", &num);
    for(i = 1; i <= 10; ++i) {
        printf("%d * %d = %d \n", num, i, num * i);
    }
    return 0;
}
