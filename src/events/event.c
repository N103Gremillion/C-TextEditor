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
			handleRightKeyPress(line, cursor);
			break;
			
		// left arrow
		case SDLK_LEFT:
			handleLeftKeyPress(line, cursor);
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
			
		// all alphabetical letters
		case SDLK_a: case SDLK_b: case SDLK_c: case SDLK_d: case SDLK_e:
		case SDLK_f: case SDLK_g: case SDLK_h: case SDLK_i: case SDLK_j:
		case SDLK_k: case SDLK_l: case SDLK_m: case SDLK_n: case SDLK_o:
		case SDLK_p: case SDLK_q: case SDLK_r: case SDLK_s: case SDLK_t:
		case SDLK_u: case SDLK_v: case SDLK_w: case SDLK_x: case SDLK_y: 
		case SDLK_z: case SDLK_SPACE:{
			
			handleRenderableKeyPress(line, key, cursor);
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

void handleRenderableKeyPress(Line* line, SDL_Keycode key, Cursor* cursor){
	
	if (cursor->row == 1) {
		// insert the appropriate char
		int shiftValue = addToLine(line, key);
		shiftCursorRight(cursor, shiftValue);
	}
	
}

void handleLeftKeyPress(Line* line, Cursor* cursor){
	
	int shiftValue = getLeftShiftValue(line);
	shiftCursorLeft(cursor, shiftValue);
	left(line->gapBuffer);
	
	// Update cursor width to the width of the previous character and color
	if (line->gapBuffer->front >= 0)
	{
		cursor->blinker.rect.w = line->characters[line->gapBuffer->front].width;
		line->characters[line->gapBuffer->front].color = (SDL_Color) {173, 216, 230, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front]));
		
		if (line->gapBuffer->front + 1 < line->numOfChars){
			line->characters[line->gapBuffer->front + 1].color = (SDL_Color) {0, 0, 0, 255};
			setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front + 1]));
		}
	}
	
}

void handleRightKeyPress(Line* line, Cursor* cursor){
	
	if (line->gapBuffer->front >= line->gapBuffer->chars){
				return;
	}
	
	int shiftValue = getRightShiftValue(line);
	shiftCursorRight(cursor, shiftValue);
	right(line->gapBuffer);
	
	// Update cursor width to the width of the next character and color
	if (line->gapBuffer->front < line->numOfChars) {
		cursor->blinker.rect.w = line->characters[line->gapBuffer->front].width;
		line->characters[line->gapBuffer->front].color = (SDL_Color) {173, 216, 230, 255};
		line->characters[line->gapBuffer->front - 1].color = (SDL_Color) {0, 0, 0, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front]));
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front - 1]));
	}
	else {
		line->characters[line->gapBuffer->front - 1].color = (SDL_Color) {0, 0, 0, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front - 1]));
	}
	
}
