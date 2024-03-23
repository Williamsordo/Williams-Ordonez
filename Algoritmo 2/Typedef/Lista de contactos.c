#include <stdio.h>
#include <string.h>

// Definición de la estructura Contacto
typedef struct {
    char nombre[50];
    char telefono[20];
    char correo[50];
} Contacto;

// Función para agregar un contacto
void agregarContacto(Contacto *contacto, char *nombre, char *telefono, char *correo) {
    strcpy(contacto->nombre, nombre);
    strcpy(contacto->telefono, telefono);
    strcpy(contacto->correo, correo);
}

// Función para imprimir un contacto
void imprimirContacto(Contacto *contacto) {
    printf("Nombre: %s\n", contacto->nombre);
    printf("Telefono: %s\n", contacto->telefono);
    printf("Correo: %s\n", contacto->correo);
}

int main() {
    // Crear dos contactos
    Contacto contacto1, contacto2;

    // Agregar información a los contactos
    agregarContacto(&contacto1, "Williams Ordonez", "04446527443", "lordwasas@gmail.com");
    agregarContacto(&contacto2, "Barbaro Lopez", "02523434344", "Nmsldg@gmail.com");

    // Imprimir la información de los contactos
    imprimirContacto(&contacto1);
    printf("\n");
    imprimirContacto(&contacto2);

    return 0;
}
