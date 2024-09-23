#include "event.h"

void handleEvents(int* running, SDL_Event* event, Cursor* cursor, FileContents* contents){
	
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
					pullEditKeyboard(running, key, cursor, contents);
					break;
				// command mode calls the coresponding key event
				case COMMAND_MODE:
					pullCommandKeyboard(running, key, cursor, contents);
					break;
				// insert mode calls the coresponding key event
				case INSERT_MODE:
					pullInsertKeyboard(running, key, cursor, contents);
					break;
				// save mode calls the coresponding key event
				case SAVE_MODE:
					pullSaveKeyboard(running, key, cursor, contents);
					break;
			}
		}
    } 
}

// keyboard events for each of the states
void pullEditKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents){
	switch (key){
		// escape button
		case SDLK_ESCAPE:
			*running = 0;
			break;
		// right arrow
		case SDLK_RIGHT:
			// shift the current cursor over to the right
			shiftCursorRight(cursor);
			break;
		// left arrow
		case SDLK_LEFT:
			// shift the current cursor over to the left
			shiftCursorLeft(cursor);
			break;
		// up arrow
		case SDLK_UP:
			// shift up
			shiftCursorUp(cursor);
			break;
		// down arrow
		case SDLK_DOWN:
			// shift down
			shiftCursorDown(cursor);
			break;
		// enter
		case SDLK_RETURN:
			shiftCursorDown(cursor);
			break;
		case SDLK_SPACE:
			addToLine(contents, cursor->row, ' ');
			shiftCursorRight(cursor);
			break;
			
		// normal alphabet
		case SDLK_a:
			addToLine(contents, cursor->row, 'a');
			if (cursor->column >= cursor->maxColumns){
				shiftCursorDown(cursor);
				cursor->column = 1;
				
			}
			break;
	}
}

void pullCommandKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents){
	
}

void pullInsertKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents){
	
}

void pullSaveKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents){
	
}
