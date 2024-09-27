


void loadTexture(Line* line){
	if (line->text == NULL || strlen(line->text) <= 0 || line->rect.w == 0){
		return;
	}
	 
	SDL_Surface* surface = TTF_RenderText_Solid(line->font, line->text, line->color);
	
	if (surface == NULL) {
        fprintf(stderr, "Failed to create surface: %s\n", TTF_GetError());
        return; // Exit if surface creation failed
    }
    
	line->texture = SDL_CreateTextureFromSurface(line->renderer, surface);
	
	if (line->texture == NULL) {
        fprintf(stderr, "Failed to create texture: %s\n", SDL_GetError());
    }
    
	SDL_FreeSurface(surface);
}
