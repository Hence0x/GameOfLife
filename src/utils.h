#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 10
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)

typedef struct {
    int x;
    int y;
} Point;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

void init_sdl();
void cleanup();

#endif // UTILS_H