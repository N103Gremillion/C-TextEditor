#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char c;
	int width;
	SDL_Rect rect;
}Character;

void loadTexture(Line* line);

#endif
