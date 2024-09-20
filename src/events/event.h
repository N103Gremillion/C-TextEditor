#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../state/cursor.h"

typedef enum {
    EDIT_MODE,
    COMMAND_MODE,
    INSERT_MODE,
    SAVE_MODE
} EditorState;

void handleEvents(SDL_Event* event, int* running, Cursor* cursor);
void pullEditKeyboard(SDL_Keycode key, Cursor* cursor);
void pullCommandKeyboard(SDL_Keycode key);
void pullInsertKeyboard(SDL_Keycode key);
void pullSaveKeyboard(SDL_Keycode key);
#endif
