/*
 * Key-Value Storage Engine
 * ------------------------
 * Almacenamiento clave-valor en memoria con tabla hash,
 * resolución de colisiones por linear probing y persistencia binaria.
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

/* Función hash (algoritmo djb2) */
unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

/* Inicializar estructura de la base de datos */
void kv_init(KVStore* store) {
    store->count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        store->entries[i].is_occupied = 0;
        store->entries[i].key[0] = '\0';
        store->entries[i].value[0] = '\0';
    }
}

/* Insertar o actualizar par clave-valor */
int kv_set(KVStore* store, const char* key, const char* value) {
    if (store->count >= TABLE_SIZE) {
        printf("Error: La base de datos esta llena.\n");
        return 0;
    }

    unsigned int index = hash(key);
    unsigned int start_index = index;

    while (store->entries[index].is_occupied) {
        if (strcmp(store->entries[index].key, key) == 0) {
            strncpy(store->entries[index].value, value, MAX_VAL_LEN - 1);
            store->entries[index].value[MAX_VAL_LEN - 1] = '\0';
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) return 0;
    }

    store->entries[index].is_occupied = 1;
    strncpy(store->entries[index].key, key, MAX_KEY_LEN - 1);
    store->entries[index].key[MAX_KEY_LEN - 1] = '\0';
    strncpy(store->entries[index].value, value, MAX_VAL_LEN - 1);
    store->entries[index].value[MAX_VAL_LEN - 1] = '\0';
    store->count++;
    return 1;
}

/* Buscar valor por clave */
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

    return NULL;
}

/* Eliminar registro */
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

    return 0;
}

/* Guardar tabla en archivo binario */
int kv_save_to_disk(KVStore* store, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error al abrir archivo para guardar.\n");
        return 0;
    }
    fwrite(store, sizeof(KVStore), 1, file);
    fclose(file);
    printf("Base de datos guardada en '%s'.\n", filename);
    return 1;
}

/* Cargar tabla desde archivo binario */
int kv_load_from_disk(KVStore* store, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error al abrir archivo '%s'.\n", filename);
        return 0;
    }
    fread(store, sizeof(KVStore), 1, file);
    fclose(file);
    printf("Base de datos cargada desde '%s'.\n", filename);
    return 1;
}

/* Mostrar registros activos */
void kv_list(KVStore* store) {
    printf("\n--- Registros en base de datos (%d) ---\n", store->count);
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (store->entries[i].is_occupied) {
            printf("[%03d] %-15s => %s\n", i, store->entries[i].key, store->entries[i].value);
            count++;
        }
    }
    if (count == 0) {
        printf("(Sin registros)\n");
    }
    printf("--------------------------------------\n\n");
}

int main(void) {
    KVStore db;
    kv_init(&db);

    printf("=== Motor Key-Value Storage ===\n");

    kv_set(&db, "usuario", "Williams Ordonez");
    kv_set(&db, "rol", "Software Engineer");
    kv_set(&db, "lenguaje", "C");

    kv_list(&db);

    printf("Buscar 'usuario': %s\n", kv_get(&db, "usuario"));
    printf("Buscar 'rol': %s\n", kv_get(&db, "rol"));

    kv_save_to_disk(&db, "database.db");

    printf("\nEliminando 'rol'...\n");
    kv_delete(&db, "rol");
    kv_list(&db);

    KVStore db_bak;
    kv_init(&db_bak);
    kv_load_from_disk(&db_bak, "database.db");
    kv_list(&db_bak);

    return 0;
}
