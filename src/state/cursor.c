#include "cursor.h"

Cursor* initCursor(int width, int height, int row, int column, int r, int g, int b, char* label){
	Cursor* cursor = malloc(sizeof(Cursor));
    Rect blinker = *(createRect(40 + row * 10, 55 + column * 5, width, height, r, g, b, label));
       
	cursor->row = row;
	cursor->column = column;
	cursor->rowSize = 20;
	cursor->columnSize = 10;
	cursor->maxColumns = 90;
	cursor->state = EDIT_MODE;
	cursor->blinker = blinker;
	
	return cursor;
}
void shiftCursorRight(Cursor* cursor){	
	if (cursor->column < cursor->maxColumns){
		cursor->column++;
		cursor->blinker.rect.x += cursor->columnSize;	
	}
}

void shiftCursorLeft(Cursor* cursor){
	if (cursor->column > 1){
		cursor->column--;
		cursor->blinker.rect.x -= cursor->columnSize;
	}
}

void shiftCursorUp(Cursor* cursor){
	if (cursor->row > 1){
		cursor->row--;
		cursor->blinker.rect.y -= cursor->rowSize;
	}
}

void shiftCursorDown(Cursor* cursor){
	if (cursor->row < 25){
		cursor->row++;
		cursor->blinker.rect.y += cursor->rowSize;
	}
}
