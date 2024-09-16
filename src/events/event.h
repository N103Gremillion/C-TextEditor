#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>

typedef enum {
    EDIT_MODE,
    COMMAND_MODE,
    INSERT_MODE,
    SAVE_MODE
} EditorState;

void handleEvents(SDL_Event* event, int* running);
void pullEditKeyboard(SDL_Keycode key);
void pullCommandKeyboard(SDL_Keycode key);
void pullInsertKeyboard(SDL_Keycode key);
void pullSaveKeyboard(SDL_Keycode key);
#endif
