#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "button.h"
#include "rectangle.h"
#include "../state/cursor.h"
#include "../dataStructures/gapBuffer.h"
#include "line.h"

SDL_Renderer* createRenderer(SDL_Window* window);

void colorScreen(SDL_Renderer* renderer);

void presentScreen(SDL_Renderer* renderer);

void destroyRenderer(SDL_Renderer* renderer);

#endif

