#include "rectangle.h"

Rect* createRect(int x, int y, int width, int height, int r, int g, int b, char* tag){
	
	Rect* rectangle = (Rect*)malloc(sizeof(Rect));
  SDL_Rect rect;
  Color rectColor = createColor(r, g, b, 255);

  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
  
  rectangle->color = rectColor;
  rectangle->rect = rect;
  return rectangle;
}

void freeRect(Rect* rectangle){
  free(rectangle->tag);
  free(rectangle);
}

