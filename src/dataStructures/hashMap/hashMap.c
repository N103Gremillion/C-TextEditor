#include "hashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// fucntions

/*
HashMap* createHashMap(){

    HashMap* map = malloc(sizeof(HashMap));
    map->size = 0;
    map->capacity = 257;
    map->loadFactor = 0.0;
    map->buckets = (LinkedList**) calloc(map->capacity, sizeof(LinkedList*));

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

void resizeMap(HashMap** mapPtr){
    
    HashMap* map = *mapPtr;

    // create new map with double capacity
    HashMap* newMap = malloc(sizeof(HashMap));
    newMap->loadFactor = 0.0;
    newMap->size = 0;
    newMap->capacity = map->capacity * 2;
    newMap->buckets = (LinkedList**) calloc(newMap->capacity, sizeof(LinkedList*));
       
    // rehash old values and add to the new map
    for (int i = 0; i < map->capacity; i++){
        if (map->buckets[i] != NULL){
            LinkedList* list = map->buckets[i];
            LinkedNode* cur = list->head;
            while (cur != NULL){
                put(newMap, cur->key, cur->data);
                cur = cur->next; 
            }
        }
    }
    
    // free and refefference
    freeHashMap(map);
    *mapPtr = newMap;

}

float calcLoad(HashMap* map){
    return (float) map->size / map->capacity;
}

//void remove(HashMap* map, char* key);

void put(HashMap* map, char* key, void* value){

    if ((float)map->size / map->capacity > 0.75){
        resizeMap(&map);
    }

    int index = hash(key, map->capacity);
    LinkedNode* node = initNode(key, value);

    if (map->buckets[index] == NULL){
        map->buckets[index] = initList();
    }
    addNode(map->buckets[index], node);
    map->size++;
    map->loadFactor = calcLoad(map);
} 

void* get(HashMap* map, char* key){
    
    int index = hash(key, map->capacity);
    
    if (map->buckets[index] == NULL){
        return NULL;
    }
    
    LinkedList* list = map->buckets[index];
    LinkedNode* cur = list->head;

    while (cur != NULL){
        if (strcmp(cur->key, key) == 0){
            printf("%s\n", cur->key);
            return cur->data;
        }
        cur = cur->next;
    }

    return NULL;
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
*/





