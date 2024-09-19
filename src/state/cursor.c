#include "cursor.h"

Cursor* initCursor(int x, int y, int width, int height, int row, int column, int r, int g, int b, char* label){
	Cursor* cursor = malloc(sizeof(Cursor));
    Rect blinker = *(createRect(x, y, width, height, r, g, b, label));
       
	cursor->row = row;
	cursor->column = column;
	cursor->blinker = blinker;
	
	return cursor;
}
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);
