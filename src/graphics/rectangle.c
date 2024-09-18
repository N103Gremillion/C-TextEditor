#include "rectangle.h"

Rect* createRect(int x, int y, int width, int height, int r, int g, int b, char* label) {
    // Allocate memory for the Rect struct
    Rect* rectangle = (Rect*)malloc(sizeof(Rect));
    if (rectangle == NULL) {
        perror("Failed to allocate memory for Rect");
        return NULL;
    }
    
    // Initialize the SDL_Rect and Color
    SDL_Rect rect;
    Color rectColor = createColor(r, g, b, 255);

    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    // Set the properties of the Rect struct
    rectangle->color = rectColor;
    rectangle->rect = rect;
    rectangle->label = label;
    return rectangle;
}


void freeRect(Rect* rectangle){
  free(rectangle);
}

