#ifndef GAPBUFFER_H
#define GAPBUFFER_H

typedef struct{
	char* buffer;
	int front; /* size of all components before teh cursor */
	int gap; /* size of gap */ 
	int length;
} GapBuffer;

GapBuffer* initBuffer();
// void shiftGap(GapBuffer* gap, int cursorPosition)
void insert(GapBuffer* buffer, char data);
void left(GapBuffer* buffer);
void right(GapBuffer* buffer);
void grow(GapBuffer* buffer);

#endif
