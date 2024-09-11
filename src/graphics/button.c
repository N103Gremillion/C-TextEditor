#include <stdlib.h>
#include "button.h"

// function prototypes
Button* createButton(int x, int y, int width, int height, int r, int g, int b){  

    Button* button = (Button*)malloc(sizeof(Button));
    SDL_Rect rect;
    SDL_Rect innerRect;

    Color rectColor = createColor(r, g, b, 255);

    rect.x = x;
    innerRect.x = x + 1;
    rect.y = y;
    innerRect.y = y + 1;
    rect.w = width;
    innerRect.w = width - 2;
    rect.h = height;
    innerRect.h = height - 2;
    button->color = rectColor;
    button->isPressed = 0;
    button->isHovered = 0;        
    button->rect = rect;
    button->innerRect = innerRect;

    return button;

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



