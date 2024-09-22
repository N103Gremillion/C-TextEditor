#include "event.h"

void handleEvents(SDL_Event* event,int* running, Cursor* cursor){
	
    while (SDL_PollEvent(event)){
		// quit when the x is pressed
		if (event->type == SDL_QUIT){
			*running = 0;
            break;
		}
		else if (event->type == SDL_KEYDOWN){
			SDL_Keycode key = event->key.keysym.sym;
			// poll the keys for each of the states
			switch(cursor->state){
				// edit mode calls the coresponding key event
				case EDIT_MODE:
					pullEditKeyboard(key, cursor);
					break;
				// command mode calls the coresponding key event
				case COMMAND_MODE:
					pullCommandKeyboard(key);
					break;
				// insert mode calls the coresponding key event
				case INSERT_MODE:
					pullInsertKeyboard(key);
					break;
				// save mode calls the coresponding key event
				case SAVE_MODE:
					pullSaveKeyboard(key);
					break;
			}
		}
    } 
}

// keyboard events for each of the states
void pullEditKeyboard(SDL_Keycode key, Cursor* cursor){
	switch (key){
		case SDLK_ESCAPE:
			printf("Escape Pressed ");
			break;
		case SDLK_RIGHT:
			// shift the current cursor over to the right
			shiftCursorRight(cursor);
			break;
		case SDLK_LEFT:
			// shift the current cursor over to the left
			shiftCursorLeft(cursor);
			break;
		case SDLK_UP:
			// shift up
			shiftCursorUp(cursor);
			break;
		case SDLK_DOWN:
			// shift down
			shiftCursorDown(cursor);
			break;
		case SDLK_RETURN:
			shiftCursorDown(cursor);
			break;
	}
}

void pullCommandKeyboard(SDL_Keycode key){
	
}

void pullInsertKeyboard(SDL_Keycode key){
	
}

void pullSaveKeyboard(SDL_Keycode key){
	
}
