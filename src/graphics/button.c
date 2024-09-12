#include <stdlib.h>
#include "button.h"

// function prototypes
Button* createButton(SDL_Renderer* renderer, int x, int y, int width, int height, int r, int g, int b, int fontSize){  

    Button* button = (Button*)malloc(sizeof(Button));
    SDL_Rect rect;
    SDL_Rect innerRect;
    SDL_Color textColor;
    SDL_Color labelColor = {0, 0, 0, 255};
	TTF_Font* font = TTF_OpenFont("arial.ttf", fontSize);
    Color rectColor = createColor(r, g, b, 255);
	
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    innerRect.x = x + 1;
    innerRect.y = y + 1;   
    innerRect.w = width - 2;   
    innerRect.h = height - 2;
    button->color = rectColor;
    button->labelColor = labelColor;
    button->isPressed = 0;
    button->isHovered = 0;        
    button->rect = rect;
    button->innerRect = innerRect;
    button->label = "Hello";
    button->font = font;
    setTexture(renderer, button);

    return button;

}

void setTexture(SDL_Renderer* renderer, Button* button){
	SDL_Surface* surface = TTF_RenderText_Solid(button->font, button->label, button->labelColor);
	button->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void freeButton(Button* button){
    if (button != NULL){
        if (button->label != NULL){
            free(button->label);
        }
        free(button);
        button = NULL;
    }
}

// so called setters
void changeButtonWidth(Button* button, int width){
    if (button != NULL && width <= 0){
        button -> rect.w = width;
    }
}

void changeButtonHeight(Button* button, int height){
    if (button != NULL && height <= 0){
        button -> rect.h = height;
    }
}

void changeButtonX(Button* button, int x){
    if (button != NULL){
        button -> rect.x = x;
    }
}

void changeButtonY(Button* button, int y){
    if (button != NULL){
        button -> rect.y = y;
    }
}


// so called getters
void getButtonWidth(const Button* button,int* width){    
    if (button != NULL && width != NULL){
        *width = button->rect.w;
    }
}

void getButtongHeight(const Button* button, int* height){
    if (button != NULL && height != NULL){
        *height = button -> rect.h;
    }
}

void getButtonX(const Button* button, int* x){
    if (button != NULL && x != NULL){
        *x = button -> rect.x;
    }
}

void getButtonY(const Button* button, int* y){
    if (button != NULL && y != NULL){
        *y = button -> rect.y;
    }
}



