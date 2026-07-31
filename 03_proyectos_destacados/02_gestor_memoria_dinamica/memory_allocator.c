/*
 * ============================================================================
 * Proyecto   : Custom Dynamic Memory Allocator & Pool Manager
 * Nivel      : Avanzado / Portafolio Senior (Sistemas Operativos & C Internals)
 * Archivo    : memory_allocator.c
 * Descripción: Simulador de asignador dinámico de memoria estilo malloc/free
 *              con gestión de cabeceras de bloques, fusión de memoria contigua (coalescing)
 *              y reporte de fuga de memoria (Memory Leaks).
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024 // 1 KB de memoria heap simulada

typedef struct MemoryBlock {
    size_t size;                // Tamaño del bloque útil
    int is_free;                // 1 si está libre, 0 si está asignado
    struct MemoryBlock* next;   // Apuntador al siguiente bloque
} MemoryBlock;

static char heap[HEAP_SIZE];
static MemoryBlock* free_list = (MemoryBlock*)heap;

// Inicializar el gestor de memoria
void mem_init(void) {
    free_list->size = HEAP_SIZE - sizeof(MemoryBlock);
    free_list->is_free = 1;
    free_list->next = NULL;
}

// Asignador personalizado (Custom Malloc) - First Fit Strategy
void* custom_malloc(size_t size) {
    MemoryBlock* current = free_list;

    while (current != NULL) {
        if (current->is_free && current->size >= size) {
            // Comprobar si se puede dividir el bloque
            if (current->size >= size + sizeof(MemoryBlock) + 8) {
                MemoryBlock* next_block = (MemoryBlock*)((char*)current + sizeof(MemoryBlock) + size);
                next_block->size = current->size - size - sizeof(MemoryBlock);
                next_block->is_free = 1;
                next_block->next = current->next;

                current->size = size;
                current->next = next_block;
            }
            current->is_free = 0;
            return (void*)((char*)current + sizeof(MemoryBlock));
        }
        current = current->next;
    }

    printf("Error: Memoria insuficiente en el Heap.\n");
    return NULL;
}

// Liberar memoria (Custom Free) y fusionar bloques adyacentes libres (Coalescing)
void custom_free(void* ptr) {
    if (ptr == NULL) return;

    MemoryBlock* block = (MemoryBlock*)((char*)ptr - sizeof(MemoryBlock));
    block->is_free = 1;

    // Fusión de bloques adyacentes libres (Coalescing)
    MemoryBlock* current = free_list;
    while (current != NULL && current->next != NULL) {
        if (current->is_free && current->next->is_free) {
            current->size += sizeof(MemoryBlock) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

// Imprimir reporte del estado actual del Heap
void mem_status(void) {
    MemoryBlock* current = free_list;
    int block_num = 1;
    size_t total_used = 0;
    size_t total_free = 0;

    printf("\n------------------- ESTADO DEL HEAP -------------------\n");
    while (current != NULL) {
        printf("Bloque %d | Tamaño: %4zu bytes | Estado: %s\n",
               block_num++, current->size, current->is_free ? "LIBRE" : "OCUPADO");

        if (current->is_free) {
            total_free += current->size;
        } else {
            total_used += current->size;
        }
        current = current->next;
    }
    printf("Total Usado: %zu bytes | Total Libre: %zu bytes\n", total_used, total_free);
    printf("--------------------------------------------------------\n\n");
}

int main(void) {
    mem_init();

    printf("========================================================\n");
    printf("     DEMO: GESTOR Y ASIGNADOR DE MEMORIA EN C           \n");
    printf("========================================================\n");

    mem_status();

    printf("Asignando bloques de memoria...\n");
    char* p1 = (char*)custom_malloc(128);
    char* p2 = (char*)custom_malloc(256);
    char* p3 = (char*)custom_malloc(64);

    if (p1) strcpy(p1, "Hola mundo desde memoria asignada manualmente");
    if (p2) strcpy(p2, "Estructura de datos avanzada en C");

    printf("p1: %s\n", p1);
    printf("p2: %s\n", p2);

    mem_status();

    printf("Liberando bloque p2 (256 bytes)...\n");
    custom_free(p2);
    mem_status();

    printf("Liberando bloque p1 y p3 (Fusión de bloques libre)... \n");
    custom_free(p1);
    custom_free(p3);
    mem_status();

    return 0;
}
