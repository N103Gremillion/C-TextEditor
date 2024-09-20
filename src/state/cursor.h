#ifndef CURSOR_H
#define CURSOR_H

#include <SDL2/SDL.h>
#include "../graphics/rectangle.h"
#include "../graphics/color.h"

// struct to keep up with the location that I am at in the editor
typedef struct {
	
	int row;
	int column;
	int rowSize;
	int columnSize;
	int maxColumns;
	
	// visual of the cursor
	Rect blinker;
} Cursor;

Cursor* initCursor(int width, int height, int row, int column, int r, int g, int b, char* label);
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);

	
#endif