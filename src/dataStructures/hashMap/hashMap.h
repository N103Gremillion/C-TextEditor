#ifndef HASHMAP_H
#define HASHMAP_H

#include "../linkedList/linkedList.h"
/*
// this is set to a size of 151 and not dynamically allocated
typedef struct {
    LinkedList** buckets;
    int size;
    int capacity;
    float loadFactor;
} HashMap;

// prototypes
HashMap* createHashMap();
void destroyHashMap(HashMap* map);
void resizeMap(HashMap** map);
float calcLoad(HashMap* map);
void put(HashMap* map, char* key, void* value); 
void* get(HashMap* map, char* key);
//void remove(HashMap* map, char* key);
unsigned int hash(char* key, int capacity);
*/
#endif
