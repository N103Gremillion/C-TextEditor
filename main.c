#define SDL_MAIN_HANDLED
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1600
#include <stdio.h>
#include "./dependencies/include/SDL.h"

int main(int argc, char *argv[])
{  
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    // initalize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("There was an issue initalizeing SDL! %s\n", SDL_GetError());
    }
    else{
        // set window properties
        window = SDL_CreateWindow(
            "Editor Window", 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );

        if (window == NULL){
            printf("Error trying to get window up %s\n", SDL_GetError());
        }
        else {
            // use window surface as the surface
            screenSurface = SDL_GetWindowSurface(window);

            // fill in the surface with prefered color
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xAA, 0xAA, 0xAA ));

            SDL_UpdateWindowSurface(window);

            // this keeps the window up
            int running = 1;

            SDL_Event event;

            while (running){
                while (SDL_PollEvent(&event)){
                    if (event.type == SDL_QUIT){
                        running = 0;
                    }
                }
            }
            SDL_FreeSurface(screenSurface);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }

    return 0;
}