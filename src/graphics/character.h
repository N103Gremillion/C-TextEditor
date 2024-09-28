#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char data;
	int x;
	int y;
	int width;
	int height;
	SDL_Color color;
	SDL_Rect rect;
	SDL_Texture* texture;
}Character;

Character* initCharacter(char character);
void loadTexture(Line* line);

#endif
