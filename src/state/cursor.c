#include "cursor.h"

Cursor* initCursor(int x, int y, int width, int height, int row, int column, int r, int g, int b, char* label){
	Cursor* cursor = 
	malloc(sizeof(Cursor));
    SDL_Rect blinker;
    blinker.x = x;
    blinker.y = y;
    blinker.w = width;
    blinker.h = height;
	cursor->row = row;
	cursor->column = column;
	cursor->blinker = blinker;
}
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);
