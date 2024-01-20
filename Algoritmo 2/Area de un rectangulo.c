#include <stdio.h> 

int main() { 
    float base, altura, area; // Declara las variables 'base', 'altura' y 'area'

    printf("Introduce la base del rectángulo: "); // Solicita al usuario que introduzca la base del rectángulo
    scanf("%f", &base); // Lee la base introducida por el usuario

    printf("Introduce la altura del rectángulo: "); // Solicita al usuario que introduzca la altura del rectángulo
    scanf("%f", &altura); // Lee la altura introducida por el usuario

    area = base * altura; // Calcula el área del rectángulo multiplicando la base por la altura

    if(area > 40 && altura > 10) { // Si el área es mayor a 40 y la altura es mayor a 10
        printf("El área del rectángulo es %.2f y es mayor a 40. Además, la altura es %.2f y es mayor a 10.", area, altura); // Imprime un mensaje personalizado
    } else {
        printf("El área del rectángulo es %.2f y la altura es %.2f.", area, altura); // Imprime el área y la altura del rectángulo
    }

    return 0; // Termina la ejecución del programa
}
