/*
 * ============================================================================
 * Proyecto   : Key-Value Storage Engine (Motor de Base de Datos Clave-Valor)
 * Nivel      : Avanzado / Portafolio Senior
 * Archivo    : kv_store.c
 * Descripción: Motor de base de datos en C con tabla Hash en memoria,
 *              búsqueda O(1), resolución de colisiones y persistencia binaria en disco.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 128
#define MAX_KEY_LEN 64
#define MAX_VAL_LEN 256

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
    int is_occupied;
} KVPair;

typedef struct {
    KVPair entries[TABLE_SIZE];
    int count;
} KVStore;

// Función de Hash (djb2 algorithm)
unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % TABLE_SIZE;
}

// Inicializar el almacenamiento
void kv_init(KVStore* store) {
    store->count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        store->entries[i].is_occupied = 0;
        store->entries[i].key[0] = '\0';
        store->entries[i].value[0] = '\0';
    }
}

// Insertar o actualizar clave-valor (SET)
int kv_set(KVStore* store, const char* key, const char* value) {
    if (store->count >= TABLE_SIZE) {
        printf("Error: La base de datos está llena.\n");
        return 0;
    }

    unsigned int index = hash(key);
    unsigned int start_index = index;

    // Linear Probing para resolver colisiones
    while (store->entries[index].is_occupied) {
        if (strcmp(store->entries[index].key, key) == 0) {
            // Actualizar valor existente
            strncpy(store->entries[index].value, value, MAX_VAL_LEN - 1);
            store->entries[index].value[MAX_VAL_LEN - 1] = '\0';
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) return 0; // Tabla llena
    }

    // Insertar nuevo registro
    store->entries[index].is_occupied = 1;
    strncpy(store->entries[index].key, key, MAX_KEY_LEN - 1);
    store->entries[index].key[MAX_KEY_LEN - 1] = '\0';
    strncpy(store->entries[index].value, value, MAX_VAL_LEN - 1);
    store->entries[index].value[MAX_VAL_LEN - 1] = '\0';
    store->count++;
    return 1;
}

// Consultar por clave (GET)
const char* kv_get(KVStore* store, const char* key) {
    unsigned int index = hash(key);
    unsigned int start_index = index;

    while (store->entries[index].is_occupied) {
        if (strcmp(store->entries[index].key, key) == 0) {
            return store->entries[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) break;
    }

    return NULL; // No encontrado
}

// Eliminar clave (DELETE)
int kv_delete(KVStore* store, const char* key) {
    unsigned int index = hash(key);
    unsigned int start_index = index;

    while (store->entries[index].is_occupied) {
        if (strcmp(store->entries[index].key, key) == 0) {
            store->entries[index].is_occupied = 0;
            store->entries[index].key[0] = '\0';
            store->entries[index].value[0] = '\0';
            store->count--;
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) break;
    }

    return 0; // No encontrado
}

// Guardar base de datos a disco binario
int kv_save_to_disk(KVStore* store, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: No se pudo abrir el archivo para guardar.\n");
        return 0;
    }
    fwrite(store, sizeof(KVStore), 1, file);
    fclose(file);
    printf("Base de datos guardada exitosamente en '%s'.\n", filename);
    return 1;
}

// Cargar base de datos desde disco binario
int kv_load_from_disk(KVStore* store, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: No se encontró el archivo '%s'.\n", filename);
        return 0;
    }
    fread(store, sizeof(KVStore), 1, file);
    fclose(file);
    printf("Base de datos cargada exitosamente desde '%s'.\n", filename);
    return 1;
}

// Listar todos los registros activos
void kv_list(KVStore* store) {
    printf("\n--- REGISTROS ACTIVOS EN LA BASE DE DATOS (%d) ---\n", store->count);
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (store->entries[i].is_occupied) {
            printf("[%03d] CLAVE: %-15s | VALOR: %s\n", i, store->entries[i].key, store->entries[i].value);
            count++;
        }
    }
    if (count == 0) {
        printf("(Base de datos vacía)\n");
    }
    printf("---------------------------------------------------\n\n");
}

int main(void) {
    KVStore db;
    kv_init(&db);

    printf("==================================================\n");
    printf("     DEMO: MOTOR DE BASE DE DATOS CLAVE-VALOR     \n");
    printf("==================================================\n");

    // Insertar datos de prueba
    kv_set(&db, "usuario_101", "Williams Ordóñez");
    kv_set(&db, "rol", "Lead Software Engineer");
    kv_set(&db, "lenguaje", "C / C++ / Python");
    kv_set(&db, "estado", "Activo");

    kv_list(&db);

    // Consulta de datos
    printf("Consultando 'usuario_101': %s\n", kv_get(&db, "usuario_101"));
    printf("Consultando 'rol': %s\n", kv_get(&db, "rol"));

    // Guardar en disco
    kv_save_to_disk(&db, "database.db");

    // Borrar un elemento
    printf("\nEliminando registro 'estado'...\n");
    kv_delete(&db, "estado");

    kv_list(&db);

    // Restaurar desde disco
    KVStore db_restaurada;
    kv_init(&db_restaurada);
    kv_load_from_disk(&db_restaurada, "database.db");
    kv_list(&db_restaurada);

    return 0;
}
