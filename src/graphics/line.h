/****************** struct that represents the elements in a gap buffer(line) for rendering in the textEditor*************************/
#ifndef LINE_H
#define LINE_H

#include "../dataStructures/gapBuffer.h"
#include "character.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
	
	int height;
	int maxChars;
	int numOfChars;
	int y;
	GapBuffer* gapBuffer;
	int charactersLength;
	Character* characters; // keep track of all the characters 
	char* text;
	TTF_Font* font;
	SDL_Renderer* renderer;
	
} Line;

Line* initLine(SDL_Renderer* renderer, int y, GapBuffer* gapBuffer, TTF_Font* font);
void addToLine(Line* line, char key);
void addCharacter(Line* line, char key);
// gives more memory to the text 
void increaseTextMemory(char** textLocation);
void freeLine(Line* line);
void freeText(char* text);

#endif
