//*Realiza un programa que te muestre el número total de dígitos en un número*//

#include <stdio.h>

int main() {
    int num;
    int count = 0;

    printf("Introduce un número: ");
    scanf("%d", &num);

    while(num != 0) {
        num /= 10;
        ++count;
    }

    printf("Número total de dígitos: %d", count);

    return 0;
}
