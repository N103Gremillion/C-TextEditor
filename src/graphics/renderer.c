#include "renderer.h"

SDL_Renderer* createRenderer(SDL_Window* window){
    return SDL_CreateRenderer(window, -1, 0);
}

void colorScreen(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderClear(renderer); 
}

void renderButton(SDL_Renderer* renderer, Button button, int redVal, int greenVal, int blueVal){
		SDL_SetRenderDrawColor(renderer, button.color.red, button.color.green, button.color.blue, button.color.alpha);
		SDL_RenderFillRect(renderer, &button.rect);
        SDL_SetRenderDrawColor(renderer, redVal, greenVal, blueVal, button.color.alpha);
        SDL_RenderFillRect(renderer, &button.innerRect);
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
    
