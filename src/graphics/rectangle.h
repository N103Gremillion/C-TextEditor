#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "color.h"

typedef struct{
	SDL_Rect rect;
	Color color;
	char* label;
}Rect;
	
Rect* createRect(int x, int y, int width, int height, int r, int g, int b, char* label);
void freeRect(Rect* rectangle);

#endif
