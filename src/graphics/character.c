
Character* initCharacter(SDL_Renderer* renderer, char c, int x, int y, int width, int height){	
	char data;
	int x;
	int y;
	int width;
	int height;
	SDL_Color color;
	SDL_Rect rect;
	SDL_Texture* texture;
}

void setTexture(SDL_Renderer* renderer, Button* button){
	SDL_Surface* surface = TTF_RenderText_Solid(button->font, button->label, button->labelColor);
	button->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}
