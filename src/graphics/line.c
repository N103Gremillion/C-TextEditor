/****************** this is a struct that gives my gapbuffer a visible represnetion*************************/
#include "line.h"

Line* initLine(SDL_Renderer* renderer, int x, int y, GapBuffer* gapBuffer, TTF_Font* font){
	
	Line* line = (Line*) malloc(sizeof(Line));
	
	line->renderer = renderer;
	
	// deminsions of chars in text
	line->height = 20;
	line->numOfChars = 0;
	line->x = x;
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

int addToLine(Line* line, char key){
	
	int shift = addCharacter(line, key); 
	insert(line->gapBuffer, key);
	line->text = fetchText(line->gapBuffer);
	
	return shift;
}

int addCharacter(Line* line, char key){	
	// update the size of the array if it is full
	if (line->numOfChars >= line->charactersLength){
		increaseCharactersLength(&line->characters, line->charactersLength * 2);
		line->charactersLength *= 2;
	}
	
	// get index of where cursor is
	int index = line->gapBuffer->front;
	
	// get the new character's position
	int charX;
	if (index == 0) 
	{
		charX = line->x;
	} 
	else 
	{
		Character previousCharacter = line->characters[index - 1];
		charX = previousCharacter.x + previousCharacter.width;
	}
	
	int y = line->y;
	Character character = initCharacter(line->renderer, line->font, key, charX, y, line->height);

	// Shift characters to the right and update their x positions
	for (int i = line->numOfChars; i > index; i--) {
		line->characters[i] = line->characters[i - 1];
		line->characters[i].x += character.width; 
		line->characters[i].rect.x += character.width;
	}

	line->characters[index] = character;
	
	line->numOfChars++;
	
	return character.width;
}

// get the width (shift amount)
int getLeftShiftValue(Line* line){
	
	int index = line->gapBuffer->front;
	int shiftValue = 0;
	
	if (line->numOfChars != 0 && index > 0){
		shiftValue = line->characters[index - 1].rect.w;
	}
	return shiftValue;
	
}

int getRightShiftValue(Line* line){
	
	int index = line->gapBuffer->front;
	int shiftValue = 0;
	
	if (line->numOfChars != 0 && index < line->numOfChars){
		shiftValue = line->characters[index].rect.w;
	}
	
	return shiftValue;
	
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

void renderLine(SDL_Renderer* renderer, Line* line){
	for (int i = 0; i < line->numOfChars; i++){
		renderCharacter(renderer, line->characters[i]);	
	}
}
