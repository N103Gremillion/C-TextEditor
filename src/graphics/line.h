/****************** struct that represents the elements in a gap buffer(line) for rendering in the textEditor*************************/
#ifndef LINE_H
#define LINE_H

#include "../dataStructures/gapBuffer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
	
	int charWidth;
	int charHeight;
	SDL_Rect rect;
	SDL_Color color;
	GapBuffer* gapBuffer;
	char* text;
	TTF_Font* font;
	SDL_Texture* texture;
	int needsRedraw;
	
} Line;

Line* initLine(SDL_Renderer* renderer, int y, int x, GapBuffer* gapBuffer, TTF_Font* font);
void loadTexture(SDL_Renderer* renderer, Line* line);
// gives more memory to the text 
void adjustText(char** textLocation);
void freeLine(Line* line);
void freeText(char* text);


#endif
