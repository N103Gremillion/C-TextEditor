#include "renderer.h"

SDL_Renderer* createRenderer(SDL_Window* window){
    return SDL_CreateRenderer(window, -1, 0);
}

void colorScreen(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderClear(renderer); 
}

void renderButton(SDL_Renderer* renderer, Button button){
		SDL_SetRenderDrawColor(renderer, button.color.r, button.color.g, button.color.b, button.color.a);
		SDL_RenderFillRect(renderer, &button.rect);
}

void presentScreen(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}

void destroyRenderer(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}
    
