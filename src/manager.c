#include "manager.h"

int setupEditor(char* title, int width, int height){
	
	// initalize the video and font 
    SDL_Init(SDL_INIT_VIDEO);
    if (TTF_Init() == -1) {
		printf("TTF_Init failed: %s\n", TTF_GetError());
		return 1;
	}
    TTF_Font* font;
    font = TTF_OpenFont("/home/nathan/Desktop/C/C-TextEditor/src/FreeSans.ttf", 18);
    if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return 1;
	}
	
    SDL_Window* window = createWindow(title, width, height);   
    SDL_Renderer* renderer = createRenderer(window);
	
	// rectangle location of the text
	SDL_Rect rectangle;
	rectangle.x = 100;
	rectangle.y = 150;
	rectangle.w = 200;
	rectangle.h = 50;
	
	// toolbar
	Rect* toolbar = createRect(0, 0, 800, 41, 128, 128, 128, "toolbar");
	
    // creating buttons for the tool bar at the top of the editor
	Button* fileButton = createButton(renderer, 0, 0, 41, 41, 0, 0, 0, font, "File");
    Button* editButton = createButton(renderer, 40, 0, 41, 41, 0, 0, 0, font, "Edit");
    Button* selectionButton = createButton(renderer, 80, 0, 41, 41, 0, 0, 0, font, "Selecet");
    Button* viewButton = createButton(renderer, 120, 0, 41, 41, 0, 0, 0, font, "View");
    Button* goButton = createButton(renderer, 160, 0, 41, 41, 0, 0, 0, font, "Go");
    Button* runButton = createButton(renderer, 200, 0 , 41, 41, 0, 0, 0, font, "Run");
    Button* TerminalButton = createButton(renderer, 240, 0 , 41, 41, 0, 0, 0, font, "Terminal");
    Button* HelpButton = createButton(renderer, 280, 0 , 41, 41, 0, 0, 0, font, "Help");
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
    TTF_CloseFont(font); 
    TTF_Quit();
    SDL_Quit();

    return 0;
    
}
