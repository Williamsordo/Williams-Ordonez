/*
 * Custom Dynamic Memory Allocator
 * -------------------------------
 * Asignador dinamico de memoria simulando malloc y free con
 * algoritmo first-fit y coalescing de bloques contiguos libres.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024

typedef struct MemoryBlock {
    size_t size;
    int is_free;
    struct MemoryBlock* next;
} MemoryBlock;

static char heap[HEAP_SIZE];
static MemoryBlock* free_list = (MemoryBlock*)heap;

/* Inicializar lista de bloques de memoria */
void mem_init(void) {
    free_list->size = HEAP_SIZE - sizeof(MemoryBlock);
    free_list->is_free = 1;
    free_list->next = NULL;
}

/* Asignar bloque de memoria (First Fit) */
void* custom_malloc(size_t size) {
    MemoryBlock* current = free_list;

    while (current != NULL) {
        if (current->is_free && current->size >= size) {
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

    printf("Error: Memoria insuficiente.\n");
    return NULL;
}

/* Liberar bloque y fusionar adyacentes (Coalescing) */
void custom_free(void* ptr) {
    if (ptr == NULL) return;

    MemoryBlock* block = (MemoryBlock*)((char*)ptr - sizeof(MemoryBlock));
    block->is_free = 1;

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

/* Mostrar estado del Heap */
void mem_status(void) {
    MemoryBlock* current = free_list;
    int block_num = 1;
    size_t total_used = 0;
    size_t total_free = 0;

    printf("\n--- Estado de Memoria (Heap) ---\n");
    while (current != NULL) {
        printf("Bloque %d | Size: %4zu B | State: %s\n",
               block_num++, current->size, current->is_free ? "LIBRE" : "OCUPADO");

        if (current->is_free) {
            total_free += current->size;
        } else {
            total_used += current->size;
        }
        current = current->next;
    }
    printf("Usado: %zu B | Libre: %zu B\n", total_used, total_free);
    printf("--------------------------------\n\n");
}

int main(void) {
    mem_init();

    printf("=== Demo: Custom Memory Allocator ===\n");
    mem_status();

    char* p1 = (char*)custom_malloc(128);
    char* p2 = (char*)custom_malloc(256);
    char* p3 = (char*)custom_malloc(64);

    if (p1) strcpy(p1, "Buffer de prueba 1");
    if (p2) strcpy(p2, "Buffer de prueba 2");

    if (p1) printf("p1: %s\n", p1);
    if (p2) printf("p2: %s\n", p2);

    mem_status();

    printf("Liberando p2 (256 bytes)...\n");
    custom_free(p2);
    mem_status();

    printf("Liberando p1 y p3...\n");
    custom_free(p1);
    custom_free(p3);
    mem_status();

    return 0;
}
