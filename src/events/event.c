#include "event.h"

void handleEvents(SDL_Event* event,int* running){
	
	EditorState curState = EDIT_MODE;
	
    while (SDL_PollEvent(event)){
		// quit when the x is pressed
		if (event->type == SDL_QUIT){
			*running = 0;
            break;
		}
		else if (event->type == SDL_KEYDOWN){
			SDL_Keycode key = event->key.keysym.sym;
			// poll the keys for each of the states
			switch(curState){
				// edit mode calls the coresponding key event
				case EDIT_MODE:
					pullEditKeyboard(key);
				// command mode calls the coresponding key event
				case COMMAND_MODE:
					pullCommandKeyboard(key);
				// insert mode calls the coresponding key event
				case INSERT_MODE:
					pullInsertKeyboard(key);
				// save mode calls the coresponding key event
				case SAVE_MODE:
					pullSaveKeyboard(key);
			}
		}
    } 
}

// keyboard events for each of the states
void pullEditKeyboard(SDL_Keycode key){
	switch (key){
		case SDLK_ESCAPE:
			printf("Escape Pressed ");
	}
}

void pullCommandKeyboard(SDL_Keycode key){
	
}

void pullInsertKeyboard(SDL_Keycode key){
	
}

void pullSaveKeyboard(SDL_Keycode key){
	
}
