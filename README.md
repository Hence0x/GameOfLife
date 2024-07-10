# Conway's Game of Life Sandbox

Interactive implementation of Conway's Game of Life, with a graphical sandbox environment.

![image](https://github.com/TTayJus/GameOfLife/blob/main/image.png)


## Features

- Graphical interface using SDL2
- Interactive grid editing with a resizable brush
- Adjustable simulation speed
- Randomize and clear grid functions
- Pause/resume functionality
- Generation counter
- Toroidal (wrap-around) grid


### Controls

- Left-click and drag: Toggle cells on/off
- Spacebar: Pause/resume simulation
- R: Randomize the grid
- C: Clear the grid
- Up Arrow: Increase simulation speed
- Down Arrow: Decrease simulation speed
- [ : Decrease brush size
- ] : Increase brush size

## How it Works

Conway's Game of Life is a cellular automaton where cells in a grid evolve over discrete time steps based on a set of rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
