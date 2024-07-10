


#include <SDL2/SDL.h> /* https://github.com/microsoft/vcpkg */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "render.h"
#include "input.h"
#include "utils.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 10
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int grid[GRID_HEIGHT][GRID_WIDTH] = { 0 };
int next_grid[GRID_HEIGHT][GRID_WIDTH] = { 0 };
bool paused = false;
int generation = 0;
int speed = 100; // ms delay between generations
Point brush = { GRID_WIDTH / 2, GRID_HEIGHT / 2 };
int brush_size = 1;

int main(int argc, char* args[]) {
    srand(time(NULL));
    init_sdl();
    rnd_grid();

    Uint32 last_update = SDL_GetTicks();

    while (1) {
        handle_events();
        draw_grid();

        Uint32 current_time = SDL_GetTicks();
        if (!paused && current_time - last_update >= speed) {
            update_grid();
            last_update = current_time;
        }

        SDL_Delay(1);
    }

    return 0;
}