#include <stdio.h>

int suma(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5, num2 = 10;
    printf("La suma de %d y %d es %d", num1, num2, suma(num1, num2));
    return 0;
}
