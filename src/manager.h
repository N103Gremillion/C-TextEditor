#ifndef MANAGER_H
#define MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphics/window.h"
#include "graphics/renderer.h"
#include "events/event.h"
#include "graphics/button.h"
#include "graphics/rectangle.h"
#include "graphics/fileContents.h"
#include "dataStructures/gapBuffer.h"
#include "state/cursor.h"


int setupEditor(char* title, int windowWidth, int windowHeight);
void initalizeLibraries();
TTF_Font* loadFont();
Button** getToolbarButtons(SDL_Renderer* renderer ,TTF_Font* font);
# endif
