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
	TTF_Font* font;
}Character;

Character initCharacter(SDL_Renderer* renderer, TTF_Font* font, char data, int x, int y, int height);
Character* initCharacters(int numOfChars);
void increaseCharactersLength(Character** characters, int newSize);
void setCharTexture(SDL_Renderer* renderer, Character character);

#endif
