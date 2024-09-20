#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedNode{
	void* data;
    struct LinkedNode* next;
    struct LinkedNode* prev;
} LinkedNode;

typedef struct LinkedList{
    LinkedNode* head;
    LinkedNode* tail;
    int size;
} LinkedList;

// prototypes

// for LinkedList
LinkedList* initList();
void freeList(LinkedList* list);
void addNode(LinkedList* list, void* data);
void removeNode(LinkedList* list, LinkedNode* node);
int isEmpty(const LinkedList* list);
void traverse(LinkedList* list, void (*func)(void*));
LinkedNode* fetchNode(LinkedList* list, void* data);

//getters
int getSize(const LinkedList* list);
LinkedNode* getHead(const LinkedList* list);
LinkedNode* getTail(const LinkedList* list);

// for ListNode
LinkedNode* initNode(char* key, void* data);
void* getData(LinkedNode* node);
LinkedNode* getNext(LinkedNode* node);
LinkedNode* getPrev(LinkedNode* node);
void freeNode(LinkedNode* node);

#endif
