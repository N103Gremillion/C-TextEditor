#include "manager.h"

int setupEditor(char* title, int width, int height){
	
	// initalize the video and font 
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    SDL_Window* window = createWindow(title, width, height);   
    SDL_Renderer* renderer = createRenderer(window);
	
	// toolbar
	Rect* toolbar = createRect(0, 0, 800, 41, 128, 128, 128, "toolbar");
	
    // creating buttons for the tool bar at the top of the editor
	Button* fileButton = createButton(renderer, 0, 0, 41, 41, 0, 0, 0, 12);
    Button* editButton = createButton(renderer, 40, 0, 41, 41, 0, 0, 0, 12);
    Button* selectionButton = createButton(renderer, 80, 0, 41, 41, 0, 0, 0, 12);
    Button* viewButton = createButton(renderer, 120, 0, 41, 41, 0, 0, 0, 12);
    Button* goButton = createButton(renderer, 160, 0, 41, 41, 0, 0, 0, 12);
    Button* runButton = createButton(renderer, 200, 0 , 41, 41, 0, 0, 0, 12);
    Button* TerminalButton = createButton(renderer, 240, 0 , 41, 41, 0, 0, 0, 12);
    Button* HelpButton = createButton(renderer, 280, 0 , 41, 41, 0, 0, 0, 12);
	Button* buttons[] = {fileButton, editButton, selectionButton, viewButton, goButton, runButton, TerminalButton, HelpButton};
    int isRunning = 1;
    int* running = &isRunning;
    SDL_Event event;

    while (isRunning)
    {
        handleEvents(&event, running);
        colorScreen(renderer);
        
        // loop through buttons and render each
        renderRect(renderer, *toolbar);
        for (int i = 0; i < 8; i++){
            renderButton(renderer, buttons[i], 128, 128, 128);
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
