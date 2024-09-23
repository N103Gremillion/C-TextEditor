#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../state/cursor.h"
#include "../graphics/fileContents.h"

void handleEvents(int* running, SDL_Event* event, Cursor* cursor, FileContents* contents);
void pullEditKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents);
void pullCommandKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents);
void pullInsertKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents);
void pullSaveKeyboard(int* running, SDL_Keycode key, Cursor* cursor, FileContents* contents);
#endif
