#include "input.h"
#include "grid.h"
#include "utils.h"
#include <string.h>

void handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            cleanup();
            exit(0);
        case SDL_KEYDOWN:
            handle_keydown(event.key.keysym.sym);
            break;
        case SDL_MOUSEMOTION:
            handle_mouse_motion(&event.motion);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                toggle_cells();
            }
            break;
        }
    }
}

void handle_keydown(SDL_Keycode key) {
    switch (key) {
    case SDLK_SPACE:
        paused = !paused;
        break;
    case SDLK_r:
        rnd_grid();
        break;
    case SDLK_c:
        memset(grid, 0, sizeof(grid));
        generation = 0;
        break;
    case SDLK_UP:
        speed = (speed > 10) ? speed - 10 : 1;
        break;
    case SDLK_DOWN:
        speed += 10;
        break;
    case SDLK_LEFTBRACKET:
        brush_size = (brush_size > 1) ? brush_size - 1 : 1;
        break;
    case SDLK_RIGHTBRACKET:
        brush_size++;
        break;
    }
}

void handle_mouse_motion(SDL_MouseMotionEvent* event) {
    brush.x = event->x / CELL_SIZE;
    brush.y = event->y / CELL_SIZE;
    if (event->state & SDL_BUTTON_LMASK) {
        toggle_cells();
    }
}