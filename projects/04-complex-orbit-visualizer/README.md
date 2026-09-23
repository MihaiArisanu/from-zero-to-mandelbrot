# Stage 4 — Complex Orbit Visualizer

This project will animate the repeated application of

```text
z = z² + c
```

in the complex plane. Each result becomes the starting point for the next
iteration, and the generated points will be connected to make the orbit
visible.

The goal is to understand the iteration used by the Mandelbrot set before
trying to calculate it for every pixel on the screen.

## Project status

Work in progress — the raylib window and build setup are ready.

## Planned features

- [x] Open and close a raylib window
- [x] Represent a complex number
- [x] Draw the real and imaginary axes
- [x] Convert complex coordinates to screen coordinates
- [x] Calculate one step of `z = z² + c`
- [x] Draw the points and lines of an orbit
- [ ] Animate the iterations one at a time
- [ ] Choose `c` using the mouse
- [ ] Reset and pause the animation
- [ ] Show when an orbit escapes

## Planned controls

| Input | Action |
|---|---|
| Mouse | Choose the complex number `c` |
| `Space` | Pause or continue the animation |
| `R` | Reset the current orbit |

## Build and run

```bash
cd projects/04-complex-orbit-visualizer
make run
```

## Results

Coming soon...

## What I learned

The main lessons from this stage will be summarized in the
[learning log](../../LEARNING_LOG.md).
