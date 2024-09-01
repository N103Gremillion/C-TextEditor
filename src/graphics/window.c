#include "window.h"
#include <stdio.h>

SDL_Window* createWindow(char* title, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    return window;
}

void destroyWindow(SDL_Window* window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
