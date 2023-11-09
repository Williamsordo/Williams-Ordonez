///*Realiza un programa que simule el juego Piedra, papel o tijera, donde el usuario ingresa su elección y el programa genera una elección aleatoria.*///

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int usuario, computadora;

    printf("Ingrese su elección (1: Piedra, 2: Papel, 3: Tijera): ");
    scanf("%d", &usuario);

    srand(time(0));
    computadora = rand() % 3 + 1;

    printf("La computadora eligió: %d\n", computadora);

    if (usuario == computadora) {
        printf("Es un empate.\n");
    } else if ((usuario == 1 && computadora == 3) || (usuario == 2 && computadora == 1) || (usuario == 3 && computadora == 2)) {
        printf("¡Ganaste!\n");
    } else {
        printf("Perdiste.\n");
    }

    return 0;
}

