/****************** this is a struct that gives my gapbuffer a visible represnetion*************************/
#include "line.h"

Line* initLine(SDL_Renderer* renderer, int y, GapBuffer* gapBuffer, TTF_Font* font){
	
	Line* line = (Line*) malloc(sizeof(Line));
	
	line->renderer = renderer;
	
	// deminsions of chars in text
	line->height = 20;
	line->maxChars = 90;
	
	// gap buffer
	line->gapBuffer = gapBuffer;
	
	// sting of text
	line->text = fetchText(line->gapBuffer);
	
	return line;
}

void addToLine(Line* line, char key){
	if (strlen(line->text) < line->maxChars){ 
		insert(line->gapBuffer, key);
		line->text = fetchText(line->gapBuffer);
	}
	
	printf("Current Text : %s\n", line->text);
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
