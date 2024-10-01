#ifndef GAPBUFFER_H
#define GAPBUFFER_H

typedef struct{
	char* buffer;
	int front; /* size of all components before the cursor */
	int gap; /* size of gap */
	int chars; 
	int length;
} GapBuffer;

GapBuffer* initBuffer();
// void shiftGap(GapBuffer* gap, int cursorPosition)
void insert(GapBuffer* buffer, char data);
void deleteChar(GapBuffer* buffer);
void left(GapBuffer* buffer);
void right(GapBuffer* buffer);
void grow(GapBuffer* buffer);
char* fetchText(GapBuffer* buffer);

#endif
