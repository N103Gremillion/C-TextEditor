#ifndef CURSOR_H
#define CURSOR_H

#include <SDL2/SDL.h>
// struct to keep up with the location that I am at in the editor
typedef struct {
	// y axis
	int row;
	// x axis
	int column;
	// visual of the cursor
	SDL_Rect blinker;
} Cursor;

Cursor* initCursor(int x, int y, int width, int height, int row, int column, int r, int g, int b, char* label);
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);

	
#endif
