#include "manager.h"

int setupEditor(char* title, int width, int height){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = createWindow(title, width, height);
    SDL_Renderer* renderer = createRenderer(window);

    int isRunning = 1;
    int* running = &isRunning;
    SDL_Event event;

    while (isRunning)
    {
        handleEvents(&event, running);
        colorScreen(renderer);
        presentScreen(renderer);
    }

    destroyRenderer(renderer);
    destroyWindow(window); 

    return 0;
}
