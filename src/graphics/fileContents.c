#include "fileContents.h"
#include <stdio.h>
#include <stdlib.h>

//**************************** File Contents *********************************
FileContents* initFileContents(){
	int capacity = 10;
	int numOfLines = 1;
	
	FileContents* contents = (FileContents*) malloc(sizeof(FileContents));
	LinkedList** lines = (LinkedList**) malloc(capacity * sizeof(LinkedList*));
	
	contents->lines = lines;
	contents->capacity = capacity;
	contents->numOfLines = numOfLines;
	
	return contents;
}

void initLine(FileContents* contents, int index){
	if (contents == NULL || contents->lines == NULL){
		return;
	} 
	if (index < 0 || index >= contents->capacity){
		return;
	}
	LinkedList* line = initList();
	contents->lines[index] = line;
	contents->numOfLines++;
}

void freeFileContents(FileContents* contents){
	if (contents != NULL && contents->lines != NULL){
		for (int i = 0; i < contents->numOfLines; i++){
			freeList(contents->lines[i]);
		}
		free(contents->lines);
		free(contents);
	}	
}

void freeLine(FileContents* contents, int index){
	if (index < 0 || index >= contents->capacity || contents == NULL || contents->lines == NULL || contents->lines[index] == NULL){
		return;
	}
	freeList(contents->lines[index]);
	contents->lines[index] = NULL;
}

void addToLine(FileContents* contents, int index, char character){
	if (contents == NULL || index < 0 || index >= contents->numOfLines){
		return;
	}
	
	LinkedList* line = contents->lines[index];	
	
	if (line == NULL){
		return;
	}
	
	char* c = malloc(sizeof(char));
	*c = character;
	
	addNode(line, (void*) c);
}

void resize(FileContents* contents){
	if (contents == NULL){
		return;
	}
	// resize current array to hold 2 times as much
	contents->capacity *= 2; 
	LinkedList** newLines = (LinkedList**) malloc(sizeof(LinkedList*) * contents->capacity);

	// copy the contents of the previous lines
	for (int i = 0; i < contents->numOfLines; i++){
		newLines[i] = contents->lines[i];
	}

	free(contents->lines);

	contents->lines = newLines;
}

void checkForResize(FileContents* contents){
	if (contents == NULL){
		return;
	}
	if (contents->numOfLines >= (contents->capacity / 2)){
		resize(contents);
	}
}

