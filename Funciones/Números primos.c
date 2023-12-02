#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    if(esPrimo(num)) {
        printf("%d es un número primo", num);
    } else {
        printf("%d no es un número primo", num);
    }
    return 0;
}
