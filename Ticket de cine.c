#include <stdio.h>
#include <stdlib.h>

// Estructura para almacenar los detalles del ticket
struct Ticket {
    char cine[50];
    char sala[50];
    char asiento[50];
    char hora[50];
    char fecha[50];
    char pelicula[50];
    char nombre[50];
    char apellido[50];
    char cedula[50];
};

int main() {
    struct Ticket ticket;

    // Solicitar al usuario que ingrese los detalles del ticket
    printf("Ingrese el nombre del cine: ");
    fgets(ticket.cine, sizeof(ticket.cine), stdin);

    printf("Ingrese la sala: ");
    fgets(ticket.sala, sizeof(ticket.sala), stdin);

    printf("Ingrese el asiento: ");
    fgets(ticket.asiento, sizeof(ticket.asiento), stdin);

    printf("Ingrese la hora de la funcion: ");
    fgets(ticket.hora, sizeof(ticket.hora), stdin);

    printf("Ingrese la fecha de la funcion: ");
    fgets(ticket.fecha, sizeof(ticket.fecha), stdin);

    printf("Ingrese el nombre de la pelicula: ");
    fgets(ticket.pelicula, sizeof(ticket.pelicula), stdin);

    printf("Ingrese su nombre: ");
    fgets(ticket.nombre, sizeof(ticket.nombre), stdin);

    printf("Ingrese su apellido: ");
    fgets(ticket.apellido, sizeof(ticket.apellido), stdin);

    printf("Ingrese su cedula: ");
    fgets(ticket.cedula, sizeof(ticket.cedula), stdin);

    // Abrir el archivo de texto para escribir
    FILE *fp = fopen("ticket.txt", "w");
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Escribir los detalles del ticket en el archivo con un formato atractivo
    fprintf(fp, "------------------ TICKET DE CINE ------------------\n");
    fprintf(fp, "Cine: %s\n", ticket.cine);
    fprintf(fp, "Sala: %s\n", ticket.sala);
    fprintf(fp, "Asiento: %s\n", ticket.asiento);
    fprintf(fp, "Hora de la Funcion: %s\n", ticket.hora);
    fprintf(fp, "Fecha de la Funcion: %s\n", ticket.fecha);
    fprintf(fp, "Nombre de la Pelicula: %s\n", ticket.pelicula);
    fprintf(fp, "Nombre: %s\n", ticket.nombre);
    fprintf(fp, "Apellido: %s\n", ticket.apellido);
    fprintf(fp, "Cedula: %s\n", ticket.cedula);
    fprintf(fp, "---------------------------------------------------\n");

    printf("Ticket guardado con exito en ticket.txt\n");

    // Cerrar el archivo
    fclose(fp);

    return 0;
}

