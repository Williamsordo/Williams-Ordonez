///*Hacer un Programa que te diga la calificacion de un estudiante ingresado por el usuario*///

///*consideramos que una nota de 100 es A, 90 es B, 80 es C, 70 es D, 60 es E, 50 es F y cualquier nota menor es reprobatoria*///

#include <stdio.h>

int main() {
    int nota;

    printf("Introduce tu calificación: ");
    scanf("%d", &nota);

    if(nota >= 100)
        printf("Aprobaste con una A\n");
    else if(nota >= 90)
        printf("Aprobaste con una B\n");
    else if(nota >= 80)
        printf("Aprobaste con una C\n");
    else if(nota >= 70)
        printf("Aprobaste con una D\n");
    else if(nota >= 60)
        printf("Aprobaste con una E\n");
    else if(nota >= 50)
        printf("Aprobaste con una F\n");
    else
        printf("Reprobaste el curso\n");

    return 0;
}
