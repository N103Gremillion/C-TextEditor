#include "renderer.h"

SDL_Renderer* createRenderer(SDL_Window* window){
    return SDL_CreateRenderer(window, -1, 0);
}

void colorScreen(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    SDL_RenderClear(renderer); 
}

void presentScreen(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}

void destroyRenderer(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}
    
