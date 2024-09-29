/****************** this is a struct that gives my gapbuffer a visible represnetion*************************/
#include "line.h"

Line* initLine(SDL_Renderer* renderer, int x, int y, GapBuffer* gapBuffer, TTF_Font* font){
	
	Line* line = (Line*) malloc(sizeof(Line));
	
	line->renderer = renderer;
	
	// deminsions of chars in text
	line->height = 20;
	line->maxChars = 90;
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

void addToLine(Line* line, char key){
	if (strlen(line->text) < line->maxChars){
		addCharacter(line, key);
		insert(line->gapBuffer, key);
		line->text = fetchText(line->gapBuffer);
	}
	printf("The text is : %s \n", line->text);
	printf("The chars are : ");
	for (int i = 0; i < line->numOfChars; i++){
		printf("%c", line->characters[i].data);
	}
	printf("\n");
	printf("The num of chars in characters is : %d\n", line->numOfChars);
}

void addCharacter(Line* line, char key){	
	// update the size of the array if it is full
	if (line->numOfChars >= line->charactersLength){
		increaseCharactersLength(&line->characters, line->charactersLength * 2);
		line->charactersLength *= 2;
	}
	
	// get index of where cursor is
	int index = line->gapBuffer->front;
	
	if (index != line->numOfChars){
		// shift all chars right to make room for the current one
		for (int i = line->numOfChars; i > index; i--){
			line->characters[i] = line->characters[i - 1];
		}
	}
	
	// calculate x position of the new char
	int charX;
	if (index == 0){
		charX = line->x;
	}
	else{
		Character previousCharacter = line->characters[index - 1];
		charX = previousCharacter.x + previousCharacter.width;
	}
	
	Character character = initCharacter(line->renderer, line->font, key, charX, line->y, line->height);
	
	// insert at the current gap position
	line->characters[index] = character;
	
	line->numOfChars++;
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
	
}
