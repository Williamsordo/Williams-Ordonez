#include <stdio.h>

int esPerfecto(int num) {
    int suma = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    if(esPerfecto(num)) {
        printf("%d es un número perfecto", num);
    } else {
        printf("%d no es un número perfecto", num);
    }
    return 0;
}

