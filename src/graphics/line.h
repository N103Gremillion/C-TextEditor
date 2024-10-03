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
	int numOfChars;
	int y;
	int x;
	GapBuffer* gapBuffer;
	int charactersLength;
	Character* characters; // keep track of all the characters 
	char* text;
	TTF_Font* font;
	SDL_Renderer* renderer;
	
} Line;

Line* initLine(SDL_Renderer* renderer, int x, int y, GapBuffer* gapBuffer, TTF_Font* font);
int addToLine(Line* line, char key);
int addCharacter(Line* line, char key);
void removeCharacterFromLine(Line* line);
int getLeftShiftValue(Line* line);
int getRightShiftValue(Line* line);
// gives more memory to the text 
void increaseTextMemory(char** textLocation);
void freeLine(Line* line);
void freeText(char* text);
void renderLine(SDL_Renderer* renderer, Line* line);

#endif
