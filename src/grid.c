#include "grid.h"
#include <stdlib.h>

void rnd_grid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
    generation = 0;
}

int cnt_nbrs(int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + GRID_WIDTH) % GRID_WIDTH;
            int ny = (y + dy + GRID_HEIGHT) % GRID_HEIGHT;
            count += grid[ny][nx];
        }
    }
    return count;
}



void update_grid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int nbrs = cnt_nbrs(x, y);
            next_grid[y][x] = grid[y][x] ? (nbrs == 2 || nbrs == 3) : (nbrs == 3);
        }
    }

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = next_grid[y][x];
        }
    }
    generation++;
}



void toggle_cells() {
    for (int dy = -brush_size; dy <= brush_size; dy++) {
        for (int dx = -brush_size; dx <= brush_size; dx++) {
            int x = (brush.x + dx + GRID_WIDTH) % GRID_WIDTH;
            int y = (brush.y + dy + GRID_HEIGHT) % GRID_HEIGHT;
            grid[y][x] = !grid[y][x];
        }
    }
}