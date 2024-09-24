#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapBuffer.h"

GapBuffer* initBuffer(){
	GapBuffer* gapBuffer = (GapBuffer*) malloc(sizeof(GapBuffer));
	char* buffer = (char*) malloc(sizeof(char) * 10);
	
	memset(buffer, '\0', 10); /* initalize all to be */
	gapBuffer->buffer = buffer;
	gapBuffer->front = 0; /* size of all components before the cursor */
	gapBuffer->gap = 10; /* size of gap */ 
	gapBuffer->length = 10;
	
	return gapBuffer;
}

void insert(GapBuffer* buffer, char data){
	if (buffer == NULL){
		return;
	}
	
	if (buffer->gap <= 0) {
		grow(buffer);
	}
	
	buffer->buffer[buffer->front] = data;	
	
	buffer->front++;
	buffer->gap--;
}


void left(GapBuffer* buffer){
	if (buffer == NULL || buffer->front == 0 || buffer->length == 0){
		return;
	}
	// copy the chars of the left side of gap over to the right
	char leftChar = buffer->buffer[buffer->front - 1];
	char gapValue = buffer->buffer[buffer->front];
	
	buffer->front--;
	buffer->buffer[buffer->front + buffer->gap] = leftChar;
	buffer->buffer[buffer->front] = gapValue;
}
void right(GapBuffer* buffer){
	if (buffer == NULL || buffer->front + buffer->gap >= buffer->length || buffer->length == 0){
		return;
	}
	
	// copy the chars of the left side of buffer over to the right
	char rightChar = buffer->buffer[buffer->front + buffer->gap];
	char gapValue = buffer->buffer[buffer->front + buffer->gap - 1];
	
	
	buffer->buffer[buffer->front] = rightChar;
	buffer->buffer[buffer->front + buffer->gap] = gapValue;
	buffer->front++;
}
void grow(GapBuffer* buffer){
	
	int newSize = buffer->length * 2;
	int gapSize = 10;
	int gapPosition = buffer->front;
	char* newBuffer = realloc(buffer->buffer, newSize * sizeof(char));
		
	// shift over the elements to the right and add gap
	memmove(newBuffer + gapPosition + gapSize, newBuffer + gapPosition, (buffer->length - gapPosition) * sizeof(char));
	
	// initalize the gap to contain \0 characters
	memset(newBuffer + gapPosition, '\0', gapSize * sizeof(char));
	
	// reassing new values to the buffer
	buffer->buffer = newBuffer;
	buffer->length = newSize;
	buffer->gap += 10;
}

char* fetchText(GapBuffer* buffer){
	int totalValidChars = buffer->length - buffer->gap;
	char* text = (char*) malloc((totalValidChars + 1));
	int index = 0;
	int textIndex = 0;
	
	while (index < buffer->length){
		char cur = buffer->buffer[index];
		if (cur != '\0'){
			text[textIndex] = cur;
			textIndex++;
		}
		index++;
	}
	text[textIndex] = '\0';
	return text;
}
