/*
 * ============================================================================
 * Asignatura : Algoritmos y Programación II
 * Módulo     : Estructuras de Datos No Lineales
 * Archivo    : arbol_binario.c
 * Descripción: Implementación de un Árbol Binario de Búsqueda (BST) en C
 *              con inserción dinámica de nodos mediante punteros y `malloc`.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para los nodos del árbol
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Función para crear un nuevo nodo dinámicamente en memoria
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función recursiva para insertar datos en el árbol binario de búsqueda
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Función para recorrer e imprimir el árbol en In-Order (Izquierda, Raíz, Derecha)
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Función para liberar la memoria del árbol de forma recursiva
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    Node* root = NULL;

    printf("Construyendo Árbol Binario de Búsqueda (BST)...\n");
    root = insert(root, 5); // Raíz
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    insert(root, 1);
    insert(root, 9);
    insert(root, 10);

    printf("Recorrido In-Order del árbol: ");
    printInOrder(root);
    printf("\n");

    // Liberar memoria asignada
    freeTree(root);

    return 0;
}
