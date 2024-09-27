#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "color.h"

// stuct wrapping SDL_Rect
typedef struct{
    SDL_Rect rect;
    SDL_Rect innerRect; 
    Color color;
    SDL_Color labelColor;
    SDL_Texture* texture;
    TTF_Font* font;
    char* label;
    int isPressed;
    int isHovered;
} Button;

// function prototypes
Button* createButton(SDL_Renderer* renderer, int x, int y, int width, int height, int r, int g, int b, TTF_Font* font, char* label);
void setTexture(SDL_Renderer* renderer, Button* button);
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
Button** getToolbarButtons(SDL_Renderer* renderer ,TTF_Font* font);

#endif
