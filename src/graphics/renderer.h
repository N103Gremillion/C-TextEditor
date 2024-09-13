#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "button.h"
#include "rectangle.h"

SDL_Renderer* createRenderer(SDL_Window* window);

void colorScreen(SDL_Renderer* renderer);

void presentScreen(SDL_Renderer* renderer);

void destroyRenderer(SDL_Renderer* renderer);

void renderButton(SDL_Renderer* renderer, Button* button, int redValue, int greenValue, int blueValue);

void renderText(SDL_Renderer* renderer, Button* button);

void renderRect(SDL_Renderer* renderer, Rect rectangle);

#endif

