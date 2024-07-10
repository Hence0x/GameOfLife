#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

extern bool paused;
extern int speed;

void handle_events();
void handle_keydown(SDL_Keycode key);
void handle_mouse_motion(SDL_MouseMotionEvent* event);

#endif // INPUT_H