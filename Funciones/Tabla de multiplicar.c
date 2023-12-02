#include <stdio.h>

void tabla(int num) {
    for(int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    tabla(num);
    return 0;
}
