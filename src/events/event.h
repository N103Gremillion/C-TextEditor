#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../state/cursor.h"
#include "../graphics/fileContents.h"
#include "../graphics/line.h"

void handleEvents(int* running, SDL_Event* event, Cursor* cursor, Line* line);
void pullEditKeyboard(int* running, SDL_Keycode key, SDL_Keymod mod, Cursor* cursor, Line* line);
void pullCommandKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void pullInsertKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void pullSaveKeyboard(int* running, SDL_Keycode key, Cursor* cursor);
void handleRenderableKeyPress(Line* line, SDL_Keycode key, SDL_Keymod mod, Cursor* cursor);
void handleLeftKeyPress(Line* line, Cursor* cursor);
void handleRightKeyPress(Line* line, Cursor* cursor);
#endif
