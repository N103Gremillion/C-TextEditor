#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include "color.h"

// stuct wrapping SDL_Rect
typedef struct{
    SDL_Rect rect;
} Button;

// function prototypes
Button createButton(int x, int y, int width, int height);
void freeButton(Button* button);

// so called setters
void changeButtonWidth(Button* button,int width);
void changeButtonHeight(Button* button, int height);
void changeButtonX(Button* button, int x);
void changeButtonY(Button* button, int y);

// so called getters
void getButtonWidth(const Button* button,int* width);
void getButtongHeight(const Button* button, int* height);
void getButtonX(const Button* button, int* x);
void getButtonY(const Button* button, int* y);


#endif
