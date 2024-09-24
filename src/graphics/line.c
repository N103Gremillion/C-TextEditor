/****************** this is a struct that gives my gapbuffer a visible represnetion*************************/
#include "line.h"

Line* initLine(SDL_Renderer* renderer, int y, int x, GapBuffer* gapBuffer, TTF_Font* font){
	
	Line* line = (Line*) malloc(sizeof(Line));
	
	// deminsions of chars in text
	int charWidth;
	int charHeight;
	charWidth = 10;
	charHeight = 20;
	line->charWidth = charWidth;
	line->charHeight = charHeight;
	
	// rectangle around text
	line->rect.x = x;
	line->rect.y = y;
	line->rect.w = 0;
	line->rect.h = 20;
	
	// color of text
	line->color = (SDL_Color) {0, 0, 0, 255};
	
	// gap buffer
	line->gapBuffer = gapBuffer;
	
	// sting of text
	line->text = fetchText(gapBuffer);
	
	// font
	line->font = font;
	
	// texture
	loadTexture(renderer, line);
	
	// indicates when the loadTexture and update line functions need to be called (aka an input occurs on the line)
	line->needsRedraw = 0;
	
	return line;
}

void loadTexture(SDL_Renderer* renderer, Line* line){
	SDL_Surface* surface = TTF_RenderText_Solid(line->font, line->text, line->color);
	
	if (surface == NULL) {
        fprintf(stderr, "Failed to create surface: %s\n", TTF_GetError());
        return; // Exit if surface creation failed
    }
    
	line->texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	if (line->texture == NULL) {
        fprintf(stderr, "Failed to create texture: %s\n", SDL_GetError());
    }
    
	SDL_FreeSurface(surface);
}

// give the text more memory
void adjustText(char** textLocation){
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
