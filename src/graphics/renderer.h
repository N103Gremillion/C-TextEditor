#ifndef REDERER_H
#define REDERER_H

#include <SDL2/SDL.h>

SDL_Renderer* createRenderer(SDL_Window* window);

void colorScreen(SDL_Renderer* renderer);

void presentScreen(SDL_Renderer* renderer);

void destroyRenderer(SDL_Renderer* renderer);

#endif

