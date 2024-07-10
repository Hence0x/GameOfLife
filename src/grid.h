#ifndef GRID_H
#define GRID_H

#include "utils.h"

extern int grid[GRID_HEIGHT][GRID_WIDTH];
extern int next_grid[GRID_HEIGHT][GRID_WIDTH];
extern int generation;
extern Point brush;
extern int brush_size;

void rnd_grid();
int cnt_nbrs(int x, int y);
void update_grid();
void toggle_cells();

#endif // GRID_H