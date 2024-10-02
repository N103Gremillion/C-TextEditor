#include "cursor.h"

Cursor* initCursor(int width, int height, int row, int column, int r, int g, int b, char* label){
	Cursor* cursor = malloc(sizeof(Cursor));
    Rect blinker = *(createRect(40 + column * 10, 55 + row * 5, width, height, r, g, b, label));
       
	cursor->row = row;
	cursor->column = column;
	cursor->rowSize = 20;
	cursor->columnSize = 10;
	cursor->maxColumns = 90;
	cursor->state = EDIT_MODE;
	cursor->blinker = blinker;
	
	return cursor;
}
void shiftCursorRight(Cursor* cursor, int value){	
	printf("the current colum is %d \n", cursor->column);
	if (cursor->column < cursor->maxColumns){
		cursor->column++;
		cursor->blinker.rect.x += value;	
	}
}

void shiftCursorLeft(Cursor* cursor, int value){
	printf("the current colum is %d \n", cursor->column);
	if (cursor->column > 0){
		cursor->column--;
		cursor->blinker.rect.x -= value;
	}
}

void shiftCursorUp(Cursor* cursor){
	if (cursor->row > 0){
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
void renderCursor(SDL_Renderer* renderer, Cursor* cursor){
	renderRect(renderer, &(cursor->blinker));
}

