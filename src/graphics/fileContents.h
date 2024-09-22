#ifndef FILECONTENTS_H
#define FILECONTENTS_H

#include "../dataStructures/linkedList/linkedList.h"

typedef struct{
	LinkedList** lines;
	int numOfLines;	
	int capacity;
} FileContents;

FileContents* initFileContents();
void initLine(FileContents* lines, int index);
void addToLine(FileContents* contents, int index, char character);
void freeFileContents(FileContents* contents);
void freeLine(FileContents* contents, int index);
void resize(FileContents* contents);
void checkForResize(FileContents* contents);

#endif
