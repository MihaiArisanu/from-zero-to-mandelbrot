# Stage 3 — Camera Playground

This project introduces real-time graphics using raylib. It will display a
grid and a series of concentric circles that can be explored using a movable
2D camera.

The main goal is to understand the difference between world coordinates and
screen coordinates, and how a camera applies movement and zoom before objects
are drawn on the screen.

## Project status

Completed.

## Planned features

- [x] Open and close a raylib window
- [x] Draw concentric circles in world coordinates
- [x] Move the camera using `W`, `A`, `S` and `D`
- [x] Zoom in and out using the mouse
- [x] Reset the camera using `R`
- [x] Keep the zoom inside reasonable limits
- [x] Draw only the circles needed for the current view

## Planned controls

| Key | Action |
|---|---|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `R` | Reset the camera |

## Build and run

Build instructions will be added after the initial raylib setup is complete.

## What I learned

The main lessons from this stage will be summarized in the
[learning log](../../LEARNING_LOG.md).

## Run the app

Type in terminal:
```bash
cd projects/03-camera-playground
make run
```
