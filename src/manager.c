#include "manager.h"

int setupEditor(char* title, int width, int height){
	
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = createWindow(title, width, height);
    SDL_Renderer* renderer = createRenderer(window);

    // creating buttons for the tool bar at the top of the editor
	Button* fileButton = createButton(0, 0, 41, 41);
    Button* editButton = createButton(40, 0, 41, 41);
    Button* selectionButton = createButton(80, 0, 41, 41);
    Button* viewButton = createButton(120, 0, 41, 41);
    Button* goButton = createButton(160, 0, 41, 41);
    Button* runButton = createButton(200, 0 , 41, 41);
    Button* TerminalButton = createButton(240, 0 , 41, 41);
    Button* HelpButton = createButton(280, 0 , 41, 41);
	Button* buttons[] = {fileButton, editButton, selectionButton, viewButton, goButton, runButton, TerminalButton, HelpButton};
    int isRunning = 1;
    int* running = &isRunning;
    SDL_Event event;

    while (isRunning)
    {
        handleEvents(&event, running);
        colorScreen(renderer);
        // loop through buttons and render each
        for (int i = 0; i < 8; i++){
            renderButton(renderer, *buttons[i], 255, 255, 255);
        }
        presentScreen(renderer);
    }

    for (int i = 0; i < 8; i++){
        freeButton(buttons[i]);
    }
    destroyRenderer(renderer);
    destroyWindow(window); 

    return 0;
    
}
