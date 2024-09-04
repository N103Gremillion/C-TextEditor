#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


// for LinkedList
LinkedList* initList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void freeList(LinkedList* list){
    if (list != NULL){
        LinkedNode* cur = list->head;
        while(cur != NULL){
            LinkedNode* next = cur->next;
            freeNode(cur);
            cur = next;
        }

        free(list);
    }
}

void addNode(LinkedList* list, LinkedNode* node){
    if (list->head == NULL){
        list->head = node;
        list->tail = node;
    }
    else{
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
    node->next = NULL;
}

void removeNode(LinkedList* list, LinkedNode* node){
    if (list == NULL || node == NULL){
        return;
    }

    // special casses
    if (list->head == node){
        if (list->tail == node){
            list->tail = NULL; 
        }
        list->head = list->head->next;
        free(node);
    }
    else{
        LinkedNode* cur = list->head;
        while (cur->next != NULL){
            if (cur->next == node){
                cur->next = cur->next->next;
                if (node == list->tail){
                    list->tail = cur;
                }
                free(node);
                break;
            }
            cur = cur->next;
        }
                        
    }

    list->size--;
}

int isEmpty(const LinkedList* list){
   return list->head == NULL ? 1 : 0; 
}

void traverse(LinkedList* list, void (*func)(void*)){
    if (list == NULL || list->head == NULL){
        return;
    }

    LinkedNode* cur = list->head;
    
    while (cur != NULL){
        func(cur->key);
        cur = cur->next;
    }
}


//getters
int getSize(const LinkedList* list){
    if (list == NULL){
        return 0;
    }
    return list->size;
}

LinkedNode* getHead(const LinkedList* list){
    return list->head;
}

LinkedNode* getTail(const LinkedList* list){
    return list->tail;
}


// for ListNode
LinkedNode* initNode(char* key, void* data){

    LinkedNode* node = malloc(sizeof(LinkedNode));
    node->key = strdup(key);
    node->data = data;
    node->next = NULL;

    return node;
}

void* getData(LinkedNode* node){
    if (node == NULL){
        return NULL;
    }
    // caller must type cast this themself 
    return node->data;
}

LinkedNode* getNext(LinkedNode* node){
    if (node == NULL){
        return NULL;
    }
    return node->next;
}

void freeNode(LinkedNode* node){
    if (node != NULL){
        if (node->data != NULL){
            free(node->data);
        }
        free(node);
    }
}


