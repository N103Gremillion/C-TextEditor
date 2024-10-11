#include "event.h"

void handleEvents(int *running, SDL_Event *event, Cursor *cursor, Line *line)
{

	while (SDL_PollEvent(event))
	{
		// quit when the x is pressed
		if (event->type == SDL_QUIT)
		{
			*running = 0;
			break;
		}
		else if (event->type == SDL_KEYDOWN)
		{
			SDL_Keycode key = event->key.keysym.sym;
			SDL_Keymod mode = SDL_GetModState();
			// poll the keys for each of the states
			switch (cursor->state)
			{
			// edit mode calls the coresponding key event
			case EDIT_MODE:
				pullEditKeyboard(running, key, mode, cursor, line);
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
void pullEditKeyboard(int *running, SDL_Keycode key, SDL_Keymod mode, Cursor *cursor, Line *line)
{

	switch (key)
	{

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

	case SDLK_BACKSPACE:
		handleBackSpace(line, cursor);
		break;

	// renderable characters
	case SDLK_a:
	case SDLK_b:
	case SDLK_c:
	case SDLK_d:
	case SDLK_e:
	case SDLK_f:
	case SDLK_g:
	case SDLK_h:
	case SDLK_i:
	case SDLK_j:
	case SDLK_k:
	case SDLK_l:
	case SDLK_m:
	case SDLK_n:
	case SDLK_o:
	case SDLK_p:
	case SDLK_q:
	case SDLK_r:
	case SDLK_s:
	case SDLK_t:
	case SDLK_u:
	case SDLK_v:
	case SDLK_w:
	case SDLK_x:
	case SDLK_y:
	case SDLK_z:
	case SDLK_0:
	case SDLK_1:
	case SDLK_2:
	case SDLK_3:
	case SDLK_4:
	case SDLK_5:
	case SDLK_6:
	case SDLK_7:
	case SDLK_8:
	case SDLK_9:
	case SDLK_PERIOD:
	case SDLK_SLASH:
	case SDLK_COMMA:
	case SDLK_SEMICOLON:
	case SDLK_BACKSLASH:
	case SDLK_MINUS:
	case SDLK_EQUALS:
	case SDLK_SPACE:
	case SDLK_LEFTBRACKET:
	case SDLK_RIGHTBRACKET:
	{

		handleRenderableKeyPress(line, key, mode, cursor);
		break;
	}
	}
}

void pullCommandKeyboard(int *running, SDL_Keycode key, Cursor *cursor)
{
}

void pullInsertKeyboard(int *running, SDL_Keycode key, Cursor *cursor)
{
}

void pullSaveKeyboard(int *running, SDL_Keycode key, Cursor *cursor)
{
}

void handleRenderableKeyPress(Line *line, SDL_Keycode key, SDL_Keymod mode, Cursor *cursor)
{

	// check if the shift is pressed then change the key to uppercase
	if (key >= SDLK_a && key <= SDLK_z)
	{
		if (mode & KMOD_SHIFT || mode & KMOD_CAPS)
		{
			key = key - 32;
		}
	}

	if (cursor->row == 1)
	{
		// insert the appropriate char
		int shiftValue = addToLine(line, key);
		shiftCursorRight(cursor, shiftValue);
	}
}

void handleLeftKeyPress(Line *line, Cursor *cursor)
{

	int shiftValue = getLeftShiftValue(line);
	shiftCursorLeft(cursor, shiftValue);
	left(line->gapBuffer);

	// Update cursor width to the width of the previous character and color
	if (line->gapBuffer->front >= 0)
	{
		cursor->blinker.rect.w = line->characters[line->gapBuffer->front].width;
		line->characters[line->gapBuffer->front].color = (SDL_Color){173, 216, 230, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front]));

		if (line->gapBuffer->front + 1 < line->numOfChars)
		{
			line->characters[line->gapBuffer->front + 1].color = (SDL_Color){0, 0, 0, 255};
			setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front + 1]));
		}
	}
}

void handleRightKeyPress(Line *line, Cursor *cursor)
{

	if (line->gapBuffer->front >= line->gapBuffer->chars)
	{
		return;
	}

	int shiftValue = getRightShiftValue(line);
	shiftCursorRight(cursor, shiftValue);
	right(line->gapBuffer);

	// Update cursor width to the width of the next character and color
	if (line->gapBuffer->front < line->numOfChars)
	{
		cursor->blinker.rect.w = line->characters[line->gapBuffer->front].width;
		line->characters[line->gapBuffer->front].color = (SDL_Color){173, 216, 230, 255};
		line->characters[line->gapBuffer->front - 1].color = (SDL_Color){0, 0, 0, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front]));
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front - 1]));
	}
	else
	{
		line->characters[line->gapBuffer->front - 1].color = (SDL_Color){0, 0, 0, 255};
		setCharTexture(line->renderer, &(line->characters[line->gapBuffer->front - 1]));
	}
}

void handleBackSpace(Line *line, Cursor *cursor)
{

	int shiftValue = getLeftShiftValue(line);

	removeCharacterFromLine(line);
	shiftCursorLeft(cursor, shiftValue);
	deleteChar(line->gapBuffer);
}
