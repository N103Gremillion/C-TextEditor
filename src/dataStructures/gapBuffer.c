#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapBuffer.h"

GapBuffer* initBuffer(){
	GapBuffer* gapBuffer = (GapBuffer*) malloc(sizeof(GapBuffer));
	char* buffer = (char*) malloc(sizeof(char) * 10);
	
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

void deleteChar(GapBuffer* buffer){
	int index = buffer->front;
	
	if (index <= 0){
		return;
	}
	
	// grow the size of the gap and remove the char at the previous position
	// buffer->buffer[index - 1] = '\0';
	buffer->gap++;
	buffer->front--;
}

void left(GapBuffer* buffer){
	if (buffer == NULL || buffer->front == 0 || buffer->length == 0){
		return;
	}
	// copy the chars of the left side of gap over to the right
	char leftChar = buffer->buffer[buffer->front - 1];
	
	buffer->front--;
	buffer->buffer[buffer->front + buffer->gap] = leftChar;
}
void right(GapBuffer* buffer){
	if (buffer == NULL || buffer->front + buffer->gap >= buffer->length || buffer->length == 0){
		return;
	}
	
	// copy the chars of the left side of buffer over to the right
	char rightChar = buffer->buffer[buffer->front + buffer->gap];	
	
	buffer->buffer[buffer->front] = rightChar;
	buffer->front++;
}
void grow(GapBuffer* buffer){
	
	int newSize = buffer->length * 2;
	int gapSize = 10;
	int gapPosition = buffer->front;
	char* newBuffer = realloc(buffer->buffer, newSize * sizeof(char));
		
	// shift over the elements to the right and add gap
	memmove(newBuffer + gapPosition + gapSize, newBuffer + gapPosition, (buffer->length - gapPosition) * sizeof(char));
	
	// reassing new values to the buffer
	buffer->buffer = newBuffer;
	buffer->length = newSize;
	buffer->gap += 10;
}

char* fetchText(GapBuffer* buffer){
	int totalValidChars = buffer->length - buffer->gap;
	char* text = (char*) malloc((totalValidChars + 1) * sizeof(char));
	int textIndex = 0;
	
	// copy everything before the gap
	for (int i = 0; i < buffer->front; i++){
		text[textIndex++] = buffer->buffer[i];
	}
	
	// copy anything after gap
	for (int i = buffer->front + buffer->gap; i < buffer->length; i++){
		text[textIndex++] = buffer->buffer[i];
	}
	
	text[textIndex] = '\0';
	return text;
}
