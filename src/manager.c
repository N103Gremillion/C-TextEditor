#include "manager.h"

int setupEditor(char* title, int width, int height){
	
	//intialize libs
	initalizeLibraries();
	
	// load font
	TTF_Font* font = loadFont();
	
	// get window and renderer components
    SDL_Window* window = createWindow(title, width, height);   
    SDL_Renderer* renderer = createRenderer(window);
	
	// create toolbar and get buttons 
	Rect* toolbar = createRect(0, 0, 800, 41, 128, 128, 128, "toolbar");
	Button** toolbarButtons = getToolbarButtons(renderer, font);

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
            renderButton(renderer, toolbarButtons[i], 128, 128, 128);
        }
        
        presentScreen(renderer);
    }
	
	// free all components on the heap / clean up
    for (int i = 0; i < 8; i++){
        freeButton(toolbarButtons[i]);
    }
    destroyRenderer(renderer);
    destroyWindow(window);
    TTF_CloseFont(font); 
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

TTF_Font* loadFont(){
	TTF_Font* font;
    font = TTF_OpenFont("/home/nathan/Desktop/C/C-TextEditor/src/FreeSans.ttf", 18);
    if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return NULL;
	}
	
	return font;
}

Button** getToolbarButtons(SDL_Renderer* renderer ,TTF_Font* font){
	Button** buttons = malloc(8);
	
	buttons[0] = createButton(renderer, 0, 0, 41, 41, 0, 0, 0, font, "File");
    buttons[1] = createButton(renderer, 40, 0, 50, 41, 0, 0, 0, font, "Edit");
    buttons[2] = createButton(renderer, 90, 0, 70, 41, 0, 0, 0, font, "Select");
    buttons[3] = createButton(renderer, 160, 0, 50, 41, 0, 0, 0, font, "View");
    buttons[4] = createButton(renderer, 210, 0, 50, 41, 0, 0, 0, font, "Go");
    buttons[5] = createButton(renderer, 260, 0, 50, 41, 0, 0, 0, font, "Run");
    buttons[6] = createButton(renderer, 310, 0, 90, 41, 0, 0, 0, font, "Terminal");
    buttons[7] = createButton(renderer, 400, 0, 50, 41, 0, 0, 0, font, "Help");

	return buttons;
}
