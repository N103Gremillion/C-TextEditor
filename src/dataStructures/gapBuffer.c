#include <stdio.h>
#include <stdlib.h>
#include "gapBuffer.h"

GapBuffer* initBuffer(){
	GapBuffer* gapBuffer = (GapBuffer*) malloc(sizeof(GapBuffer));
	char* buffer = (char*) malloc(sizeof(char) * 30);
	int front = 10; /* size of all components before the cursor */
	int gap = 10; /* size of gap */ 
	int length = 30;
	
	return gapBuffer;
}

// this function is used right when you enter a line to adjust the gap
void shiftGap(GapBuffer* gap, int cursorPosition){
	
}

void insert(GapBuffer* buffer, char data){
}

void remove(GapBuffer* buffer){
}

void left(GapBuffer* buffer){
	if (buffer == NULL || buffer->front == 0){
		break;
	}
	// copy the chars of the 
	buffer-
}
void right(GapBuffer* buffer);
void grow(GapBuffer* buffer);
