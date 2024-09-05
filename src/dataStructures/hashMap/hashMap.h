#ifndef HASHMAP_H
#define HASHMAP_H

#include "../linkedList/linkedList.h"

// this is set to a size of 151 and not dynamically allocated
typedef struct {
    LinkedNode** buckets;
    int size;
    int capacity;
    float loadFactor;
} HashMap;

// prototypes
void resizeMap(HashMap* map);
void calcLoad(HashMap* map);
void put(HashMap* map, char* key, void* value); 
void* get(HashMap* map, char* key);
void remove(HashMap* map, char* key);
unsigned int hash(char* key, int capacity);

#endif
