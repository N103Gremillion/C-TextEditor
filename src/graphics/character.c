#include "character.h"

Character initCharacter(SDL_Renderer* renderer, TTF_Font* font, char data, int x, int y, int height){	
	Character character;
	character.data = data;
	character.x = x;
	character.y = y;
	character.font = font;
	character.color.r = 0;
	character.color.g = 0;
	character.color.b = 0;
	character.color.a = 255;
	
	// create a temporary string for the char to calclate some values
	char text[2] = {data, '\0'};
	
	// claculate the height and width
	int width = 0, charHeight = 0;
	// function that sets the width and charHeight using the font and string
	TTF_SizeText(font, text, &width, &charHeight);
	character.width = width;
	character.height = charHeight;
	 
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = charHeight;
	character.rect = rect;
	setCharTexture(renderer, character);
	
	return character;
}

Character* initCharacters(int numOfChars){
	
	Character* newCharacters = (Character*) malloc(sizeof(Character) * numOfChars);
	
	return newCharacters;
}

void increaseCharactersLength(Character** characters, int newSize){
	Character* newCharacters = (Character*) realloc(*characters, newSize * sizeof(Character));
	
	*characters = newCharacters;
}
void setCharTexture(SDL_Renderer* renderer, Character character){
	char text[2] = {character.data, '\0'};
	
	SDL_Surface* surface = TTF_RenderText_Solid(character.font, text, character.color);
	character.texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}
