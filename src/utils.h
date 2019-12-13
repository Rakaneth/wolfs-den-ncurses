#include <stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define abs(a) ((a) < 0) ? (a) : -(a)
#define HASH_SIZE 313
#define HASH2_PRIME 53

typedef struct hash_entry_t {
    size_t idx;
    void* data;
} HashEntry;

typedef struct hash_t {
    size_t size;
    size_t count;
    HashEntry table[HASH_SIZE];
} HashTable;

typedef enum hashop_result_t {
    HASH_INSERT_ERR,
    HASH_INSERT_OK,
    HASH_DELETE_ERR,
    HASH_DELETE_OK,
} HashResult;

int clamp(int val, int low, int high);
int between(int val, int low, int high);

HashTable* newHashTable();
void destroyHashTable();
HashResult hashInsert(HashTable* tbl, const char* key, void* data);
void* hashGet(HashTable* tbl, const char* key);