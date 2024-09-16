#include "cursor.h"

Cursor* initCursor(){
	Cursor* cursor = malloc(sizeof(Cursor));
	cursor->width = 5;
	cursor->height = 5;
	cursor->row = 1;
	cursor->column = 1;
	cursor->x = 50;
	cursor->y = 50;
	cursor->blinker = createRect(cursor->x, cursor->y, cursor->width, cursor->height, 255, 0, 0, "Cursor");
}
void shiftCursorRight(Cursor* cursor);
void shiftCursorLeft(Cursor* cursor);
void shiftCursorUp(Cursor* cursor);
void shiftCursorDown(Cursor* cursor);
