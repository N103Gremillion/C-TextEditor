#include "character.h"

Character initCharacter(SDL_Renderer* renderer, TTF_Font* font, char data, int x, int y, int height){	
	Character character;
	character.data = data;
	character.x = x;
	character.y = y;
	character.width = width;
	character.height = height;
	character.color.r = 0;
	character.color.g = 0;
	character.color.b = 0;
	character.color.a = 255;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	character.rect = rect;
	SDL_Texture* texture;
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
	SDL_Surface* surface = TTF_RenderText_Solid(character.font, &(character.data), character.color);
	character.texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}
