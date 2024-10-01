#include "event.h"

void handleEvents(int* running, SDL_Event* event, Cursor* cursor, Line* line){
	
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
					pullEditKeyboard(running, key, cursor, line);
					break;
				// command mode calls the coresponding key event
				case COMMAND_MODE:
					pullCommandKeyboard(running, key, cursor);
					break;
				// insert mode calls the coresponding key event
				case INSERT_MODE:
					pullInsertKeyboard(running, key, cursor);
					break;
				// save mode calls the coresponding key event
				case SAVE_MODE:
					pullSaveKeyboard(running, key, cursor);
					break;
			}
		}
    } 
}

// keyboard events for each of the states
void pullEditKeyboard(int* running, SDL_Keycode key, Cursor* cursor, Line* line){
	switch (key){
		// escape button
		case SDLK_ESCAPE:
			*running = 0;
			break;
		// right arrow
		case SDLK_RIGHT:
			// shift the current cursor over to the right
			right(line->gapBuffer);
			// shiftCursorRight(cursor);
			break;
		// left arrow
		case SDLK_LEFT:
			// shift the current cursor over to the left
			left(line->gapBuffer);
			// shiftCursorLeft(cursor);
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
			// shiftCursorDown(cursor);
			break;
		case SDLK_SPACE:
			// shiftCursorRight(cursor);
			break;
			
		// all alphabetical letters
		case SDLK_a: case SDLK_b: case SDLK_c: case SDLK_d: case SDLK_e:
		case SDLK_f: case SDLK_g: case SDLK_h: case SDLK_i: case SDLK_j:
		case SDLK_k: case SDLK_l: case SDLK_m: case SDLK_n: case SDLK_o:
		case SDLK_p: case SDLK_q: case SDLK_r: case SDLK_s: case SDLK_t:
		case SDLK_u: case SDLK_v: case SDLK_w: case SDLK_x: case SDLK_y: 
		case SDLK_z: {
			
			if (cursor->column >= cursor->maxColumns) {
				shiftCursorDown(cursor);
			} else if (cursor->row == 1) {
				// insert the appropriate char
				int shiftValue = addToLine(line, key);
				shiftCursorRight(cursor, shiftValue);
			}
			break;
			
		}
	}
}

void pullCommandKeyboard(int* running, SDL_Keycode key, Cursor* cursor){
	
}

void pullInsertKeyboard(int* running, SDL_Keycode key, Cursor* cursor){
	
}

void pullSaveKeyboard(int* running, SDL_Keycode key, Cursor* cursor){
	
}
