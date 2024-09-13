#include "renderer.h"

SDL_Renderer* createRenderer(SDL_Window* window){
    return SDL_CreateRenderer(window, -1, 0);
}

void colorScreen(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderClear(renderer); 
}

void renderButton(SDL_Renderer* renderer, Button* button, int redVal, int greenVal, int blueVal) {
	
    // Render the outer button
    SDL_SetRenderDrawColor(renderer, button->color.red, button->color.green, button->color.blue, button->color.alpha);
    SDL_RenderFillRect(renderer, &button->rect);

    // Render the inner button
    SDL_SetRenderDrawColor(renderer, redVal, greenVal, blueVal, button->color.alpha);
    SDL_RenderFillRect(renderer, &button->innerRect);

    // Render the text
    renderText(renderer, button);
}

void renderText(SDL_Renderer* renderer, Button* button) {
	SDL_Rect textRect;
	textRect.x = button->innerRect.x;
	textRect.y = button->innerRect.y;
	textRect.w = button->innerRect.w  - button->innerRect.w/3;
	textRect.h = button->innerRect.h - button->innerRect.h/3;
    SDL_RenderCopy(renderer, button->texture, NULL, &textRect);
}

void renderRect(SDL_Renderer* renderer, Rect rectangle){
	SDL_SetRenderDrawColor(renderer, rectangle.color.red, rectangle.color.green, rectangle.color.blue, rectangle.color.alpha);
	SDL_RenderFillRect(renderer, &rectangle.rect);
}
void presentScreen(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}

void destroyRenderer(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}
    
