#include <stdlib.h>
#include "button.h"

// function prototypes
// create and free
Button createButton(int x, int y, int width, int height){  

    Button button;
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    
    button.rect = rect;

    return button;

}

void freeButton(Button* button){
    if (button != NULL){
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



