#include <stdio.h>

int invertir(int num) {
    int rev = 0;
    while(num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    printf("Número invertido: %d", invertir(num));
    return 0;
}
