#include <stdio.h>

int mcd(int a, int b) {
    if (b != 0)
        return mcd(b, a % b);
    else
        return a;
}

int main() {
    int num1, num2;
    printf("Ingrese dos números: ");
    scanf("%d %d", &num1, &num2);
    printf("El MCD de %d y %d es %d", num1, num2, mcd(num1, num2));
    return 0;
}
