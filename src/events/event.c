#include "event.h"

void handleEvents(SDL_Event* event,int* running){
   while (SDL_PollEvent(event)){
        switch (event->type)
        {
        case SDL_QUIT:
            *running = 0;
            break;

        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                *running = 0;
            }
            break;
        }
    } 

}
