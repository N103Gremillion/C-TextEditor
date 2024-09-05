#include "hashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// fucntions
HashMap* createHashMap(unsigned int size){

    HashMap* map = malloc(sizeof(HashMap));
    map->size = 0;
    map->capacity = 241;
    map->loadFactor = 0.0;
    map->buckets = (LinkedList**) calloc(241, sizeof(LinkedList*));

    return map;
}

void freeHashMap(HashMap* map){
    
    if (map == NULL){
        return;
    }

    // free the linkedList in buckets
    for (int i = 0; i < map->capacity; ++i){
        freeList(map->buckets[i]); 
    }

    free(map->buckets);
    free(map);
}

void resizeMap(HashMap* map){
}

float calcLoad(HashMap* map){
    return (float) map->size / map->capacity;
}

//void remove(HashMap* map, char* key);

void put(HashMap* map, char* key, void* value){
    int index = hash(key, map->capacity);
} 

void* get(HashMap* map, char* key){

}


// hash the key to get "unique" index in array
unsigned int hash(char* key, int capacity){

    if (key == NULL || key[0] == '\0') {
        return (unsigned int)-1;
    }

    // calc sum of asci values
    unsigned int sum= 0;
    
    for (int i = 0; key[i] != '\0'; i++){
        sum += (unsigned int) key[i];
    }

    return (sum % capacity);
        
}






