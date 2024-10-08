#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapBuffer.h"

GapBuffer* initBuffer(){
	GapBuffer* gapBuffer = (GapBuffer*) malloc(sizeof(GapBuffer));
    char* buffer = (char*) calloc(50, sizeof(char));  // Use calloc to initialize to '\0' to pr
    
    gapBuffer->buffer = buffer;
    gapBuffer->front = 0; 
    gapBuffer->gap = 12;   // Set initial gap size
    gapBuffer->length = 50;  
    gapBuffer->chars = 0;
    
    return gapBuffer;
}

void insert(GapBuffer* buffer, char data){
	if (buffer == NULL){
		return;
	}
	
	if (buffer->gap <= 2) {
		grow(buffer);
	}
	
	buffer->buffer[buffer->front] = data;	
	buffer->front++;
	buffer->gap--;
	buffer->chars++;
}

void deleteChar(GapBuffer* buffer){
	int index = buffer->front;
	
	if (index <= 0){
		return;
	}
	
	buffer->gap++;
	buffer->front--;
	buffer->chars--;
}

void left(GapBuffer* buffer){
	if (buffer == NULL || buffer->front == 0 || buffer->length == 0){
		return;
	}
	
	buffer->buffer[buffer->front + buffer->gap - 1] = buffer->buffer[buffer->front - 1];  // Shift left character to gap
	buffer->front--;
	buffer->gap++;
}
void right(GapBuffer* buffer){
	if (buffer == NULL || buffer->front + buffer->gap >= buffer->length || buffer->front == buffer->chars || buffer->length == 0){
		return;
	}
	
	buffer->buffer[buffer->front] = buffer->buffer[buffer->front + buffer->gap];  // Shift character to front
	buffer->front++;
	buffer->gap--;
}
void grow(GapBuffer* buffer){
	
	int newSize = buffer->length * 2;
	int gapSize = 10;
	int gapPosition = buffer->front;
	char* newBuffer = realloc(buffer->buffer, newSize * sizeof(char));
		
	// shift over the elements to the right and add gap
	memmove(newBuffer + gapPosition + gapSize, newBuffer + gapPosition, (buffer->length - gapPosition) * sizeof(char));
	memset(newBuffer + buffer->length, 0, (newSize - buffer->length) * sizeof(char));

	
	for (int i = gapPosition; i < gapPosition + gapSize; i++) {
        newBuffer[i] = '\0';
    }
    
	// reassing new values to the buffer
	buffer->buffer = newBuffer;
	buffer->length = newSize;
	buffer->gap += gapSize;
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
