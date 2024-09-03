#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


// for LinkedList
void initList(LinkedList* list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
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

void addNode(LinkedList* list, LinkedNode* node);
void removeNode(LinkedList* list, LinkedNode* node);
int isEmpty(const LinkedList* list);
void traverse(LinkedList* list, void (*func)(void*));
LinkedNode* fetchNode(LinkedList* list, void* data);

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


