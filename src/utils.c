#include "utils.h"

static HashEntry EMPTY_ENTRY = {0, NULL};

int clamp(int val, int low, int high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}

int between(int val, int low, int high) {
    return clamp(val, low, high) == val;
}

static unsigned long hash(char* str) {
    unsigned long n = 5381;
    int c;

    while (c = *str++)
        n = ((n<< 5) + n) + c;

    return n;
}

static unsigned long hash2(unsigned long collider) {
    return HASH2_PRIME - (collider % HASH2_PRIME);
}

static int hashFull(HashTable* h) { return h->count == h->size; }

HashTable* newHashTable() {
    HashTable* h = (HashTable*)calloc(1, sizeof(HashTable));
    h->size = HASH_SIZE;
    h->count = 0;
    for (int i=0; i<h->size; i++)
        h->table[i] = EMPTY_ENTRY;
    
    return h;
}

void destroyHashTable(HashTable* tbl) {
    for(int i = 0; i<tbl->size; i++) {
        if (tbl->table[i].data) {
            free(tbl->table[i].data);
        }
    }
    free(tbl);
}



HashResult hashInsert(HashTable* tbl, const char* key, void* data) {
    unsigned long raw = hash(key);
    size_t size = tbl->size;
    size_t idx = raw % size;
    unsigned long offset = hash2(raw);
    HashEntry newEntry;

    if (hashFull(tbl)) {
        return HASH_INSERT_ERR;
    }

    for (int i=0; i<size; i++) {
        if (tbl->table[idx].data) {
            //collision
            idx = (idx + offset) % size;
        } else {
            newEntry.data = data;
            newEntry.idx = idx;
            tbl->table[idx] = newEntry;
            tbl->count++;
            return HASH_INSERT_OK;
        }
    }

    return HASH_INSERT_ERR;
}

void* hashGet(HashTable* tbl, const char* key) {
    unsigned long raw = hash(key);
    size_t size = tbl->size;
    size_t idx = raw % size;
    unsigned long offset = hash2(raw);

    for (int i=0; i<size; i++) {
        if (tbl->table[idx].idx == idx)
            return tbl->table[idx].data;
        else
            idx = (idx + offset) % size;
    }

    return NULL;
}

HashResult hashDelete(HashTable* tbl, const char* key) {
    unsigned long raw = hash(key);
    size_t size = tbl->size;
    size_t idx = raw % size;
    unsigned long offset = hash2(raw);

    for (int i=0; i<size; i++) {
        if (tbl->table[idx].idx == idx) {
            free(tbl->table[idx].data);
            tbl->table[idx] = EMPTY_ENTRY;
            tbl->count--;
            return HASH_DELETE_OK;
        } else
            idx = (idx + offset) % size;
    }

    return HASH_DELETE_ERR;
}
