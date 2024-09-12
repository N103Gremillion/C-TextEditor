#include "manager.h"

int setupEditor(char* title, int width, int height){
	
	// initalize the video and font 
    SDL_Init(SDL_INIT_VIDEO);
    if (TTF_Init() == -1) {
		printf("TTF_Init failed: %s\n", TTF_GetError());
		return 1;
	}
    TTF_Font* font;
    font = TTF_OpenFont("/home/nathan/Desktop/C/C-TextEditor/src/graphics/Pixellettersfull-BnJ5.ttf", 24);
    if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return 1;
	}
    SDL_Window* window = createWindow(title, width, height);   
    SDL_Renderer* renderer = createRenderer(window);
    
    // get the surface for the 
    SDL_Color black = {0, 0, 0, 255};
	SDL_Surface* surface = TTF_RenderText_Solid(font, "Hello world", black);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	// rectangle location of the text
	SDL_Rect rectangle;
	rectangle.x = 100;
	rectangle.y = 150;
	rectangle.w = 200;
	rectangle.h = 50;
	
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
        for (int i = 0; i < 1; i++){
            renderButton(renderer, buttons[i], 128, 128, 128);
        }
        SDL_RenderCopy(renderer, texture, NULL, &rectangle);
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
