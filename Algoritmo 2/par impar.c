#include <stdio.h> 

int main() { 
    int num; 

    printf("Introduce un número: "); // Solicita al usuario que introduzca un número
    scanf("%d", &num); // Lee el número introducido por el usuario

    if(num % 2 == 0) // Si el residuo de la división del número entre 2 es igual a 0
        printf("%d es un número par.", num); // Entonces el número es par
    else // Si no
        printf("%d es un número impar.", num); // El número es impar

    return 0; // Termina la ejecución del programa
}
