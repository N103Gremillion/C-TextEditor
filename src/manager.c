#include "manager.h"

int setupEditor(char* title, int width, int height){
	
    //intialize libs
    initalizeLibraries();
    
    // load font for the buttons
    TTF_Font* buttonFont = loadButtonFont();
    TTF_Font* textFont = loadTextFont();
    
    // get window and renderer components
    
    SDL_Window* window = createWindow(title, width, height);
	
    if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}  
	
    SDL_Renderer* renderer = createRenderer(window);
	
	// storage component for input
    Line* line = initLine(renderer, 60, initBuffer(), textFont);
    
    // create toolbar and get buttons 
    Rect* toolbar = createRect(0, 0, 1000, 50, 128, 128, 128, "Toolbar");
    Button** toolbarButtons = getToolbarButtons(renderer, buttonFont);

    // create cursor
    Cursor* cursor = initCursor(10, 20, 1, 1, 0, 0, 128, "Cursor");
    
    int isRunning = 1;
    int* running = &isRunning;
    SDL_Event event;

    while (isRunning)
    {
		handleEvents(running, &event, cursor, line);
		colorScreen(renderer);

		// loop through buttons and render each
		renderRect(renderer, toolbar);
		renderCursor(renderer, cursor);

		for (int i = 0; i < 8; i++){
		  renderButton(renderer, toolbarButtons[i], 128, 128, 128);
		}

		presentScreen(renderer);
    }

	// free all components on the heap / clean up
	freeRect(toolbar);
    for (int i = 0; i < 8; i++){
        freeButton(toolbarButtons[i]);
    }
    destroyRenderer(renderer);
    destroyWindow(window);
    TTF_CloseFont(buttonFont); 
    TTF_Quit();
    SDL_Quit();

    return 0;
    
}

void initalizeLibraries(){
	// initalize the video and font 
    if (SDL_Init(SDL_INIT_VIDEO)){
		printf("SDL didn't initalize correctly %s\n", SDL_GetError());
	}
    if (TTF_Init() == -1) {
		printf("TTF_Init failed: %s\n", TTF_GetError());
	}
}

TTF_Font* loadButtonFont(){
	TTF_Font* font;
    font = TTF_OpenFont("/home/nathan/Desktop/C/C-TextEditor/src/fonts/VollkornBold-ALwGg.ttf", 18);
    if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return NULL;
	}
	
	return font;
}

TTF_Font* loadTextFont(){
	TTF_Font* font;
    font = TTF_OpenFont("/home/nathan/Desktop/C/C-TextEditor/src/fonts/VollkornBold-ALwGg.ttf", 12);
    if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return NULL;
	}
	
	return font;
}




