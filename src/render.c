#include "render.h"
#include "grid.h"

void draw_grid() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x]) {
                SDL_Rect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // draw brush
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int dy = -brush_size; dy <= brush_size; dy++) {
        for (int dx = -brush_size; dx <= brush_size; dx++) {
            int x = (brush.x + dx + GRID_WIDTH) % GRID_WIDTH;
            int y = (brush.y + dy + GRID_HEIGHT) % GRID_HEIGHT;
            SDL_Rect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}