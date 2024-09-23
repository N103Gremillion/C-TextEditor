#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedNode{
	void* data;
    struct LinkedNode* next;
    struct LinkedNode* prev;
    int position;
} LinkedNode;

typedef struct LinkedList{
    LinkedNode* head;
    LinkedNode* tail;
    LinkedNode* cur;
    int size;
} LinkedList;

// prototypes

// for LinkedList
LinkedList* initList();
void freeList(LinkedList* list);
void insertList(LinkedList* list, LinkedNode* prev, void* data, int position);
void removeNode(LinkedList* list, LinkedNode* node);
int isEmpty(const LinkedList* list);

//getters
int getSize(const LinkedList* list);
LinkedNode* getHead(const LinkedList* list);
LinkedNode* getTail(const LinkedList* list);

// for ListNode
LinkedNode* initNode(void* data);
void* getData(LinkedNode* node);
LinkedNode* getNext(LinkedNode* node);
LinkedNode* getPrev(LinkedNode* node);
void freeNode(LinkedNode* node);

#endif
