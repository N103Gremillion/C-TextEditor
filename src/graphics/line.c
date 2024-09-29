/****************** this is a struct that gives my gapbuffer a visible represnetion*************************/
#include "line.h"

Line* initLine(SDL_Renderer* renderer, int y, GapBuffer* gapBuffer, TTF_Font* font){
	
	Line* line = (Line*) malloc(sizeof(Line));
	
	line->renderer = renderer;
	
	// deminsions of chars in text
	line->height = 20;
	line->maxChars = 90;
	line->numOfChars = 0;
	line->y = y;
	
	// gap buffer
	line->gapBuffer = gapBuffer;
	
	line->charactersLength = 50;
	line->characters = initCharacters(50);
	
	line->font = font;
	
	// sting of text
	line->text = fetchText(line->gapBuffer);
	
	return line;
}

void addToLine(Line* line, char key){
	if (strlen(line->text) < line->maxChars){ 
		addCharacter(line, key);
		insert(line->gapBuffer, key);
		line->text = fetchText(line->gapBuffer);
	}
}

void addCharacter(Line* line, char key){
	printf("The current index is : %d \n", line->gapBuffer->front);
	/*
	int index = line->gapBuffer->front;
	
	// if the gap is at the start of the line
	if (index == 0){
		
	}
	else{
		
	}
	int index = line->gapBuffer->front
	Character character = initCharacter(line->renderer, line->font, key, , line->y, line->height);
	line->numOfChars++
	*/
}
// give the text more memory
void increaseTextMemory(char** textLocation){
	if (textLocation == NULL){
		return;
	}
	
	int textSize = strlen(*textLocation);
	char* newText = (char*)realloc(*textLocation, textSize * 2);
	
	if (newText == NULL) {
     
        fprintf(stderr, "Reallocation failed: %s\n", strerror(errno));
        return; 
    }
    
	*textLocation = newText;
}

void freeLine(Line* line){
	if (line == NULL){
		return;
	}
	
	freeText(line->text);
	free(line);
}

void freeText(char* text){
	if (text == NULL){
		return;
	}
	free(text);
}
