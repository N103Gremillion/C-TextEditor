#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


//************************* for LinkedList **************************
LinkedList* initList(){
	
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->cur = NULL;
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

void insertList(LinkedList* list, LinkedNode* prev, void* data, int position){
	
	if (data == NULL){
		return;
	}
	
	LinkedNode* node = initNode(data);
	node->position = position;
	
	if (list->head == NULL){
		list->head = node;
		list->tail = node;
		return;
	}
	
	
	if (prev != NULL){
		prev->next = node;
		node->prev = prev;
	}
	else {
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	
	list->cur = node;
	list->size++;
}

void removeNode(LinkedList* list, LinkedNode* node){
    if (list == NULL || node == NULL){
        return;
    }

    // special casses
    if (list->head == node && list->tail == node){
		list->head = NULL;
		list->tail = NULL;
	}
    else if (list->head == node){
		list->head = node->next;
		if (list->head != NULL){
			list->head->prev = NULL;
		}
    }
    else if (list->tail == node){
		list->tail = node->prev;
		if (list->tail != NULL){
			list->tail->next = NULL;
		}
	}
    else{
        LinkedNode* prev = node->prev;
        LinkedNode* next = node->next;
        
        prev->next = next;
        if (next != NULL){ 
			node->next = NULL;     
		}                       
    }
    list->size--;
    free(node);
}

int isEmpty(const LinkedList* list){
   return list->head == NULL ? 1 : 0; 
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


//************** for ListNode **********************
LinkedNode* initNode(void* data){

    LinkedNode* node = malloc(sizeof(LinkedNode));
    node->data = data;
    node->next = NULL;
	node->prev = NULL;
	
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

LinkedNode* getPrev(LinkedNode* node){
	if (node == NULL){
		return NULL;
	}
	return node->prev;
}

void freeNode(LinkedNode* node){
    if (node != NULL){
        if (node->data != NULL){
            free(node->data);
        }
        free(node);
    }
}


