#ifndef CURSOR_H
#define CURSOR_H

#include "../graphics/rectangle.h"
// struct to keep up with the location that I am at in the editor
typedef struct {
	// y axis
	int row;
	// x axis
	int column;
	int x;
	int y;
	int width;
	int height;
	// visual of the cursor
	Rect* blinker;
} Cursor;

Cursor* initCursor();
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);

	
#endif
