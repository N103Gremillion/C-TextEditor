#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "../../graphics/color.h"



void printValues(void* data){
    char* string = (char*) data;
    printf("%s", string);
}


int main(){

    Color red = createColor(255, 0, 0, 255);
    Color green = createColor(0, 255, 0, 255);
    Color blue = createColor(0, 0, 255, 255);

    LinkedNode* node1 = initNode("Red", &red);
    LinkedNode* node2 = initNode("Green", &green);
    LinkedNode* node3 = initNode("Blue", &blue);

    LinkedList* list = initList();

    addNode(list, node1);
    addNode(list, node2);
    addNode(list, node3);

    traverse(list,printValues);
}


