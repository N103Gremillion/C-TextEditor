#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../state/cursor.h"
#include "../graphics/fileContents.h"

void handleEvents(int* running, SDL_Event* event, Cursor* cursor);
void pullEditKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void pullCommandKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void pullInsertKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void pullSaveKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
#endif
