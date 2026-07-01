# Simple Pong (SDL3)

The graphical version of the console `super-simple-game` (Simple Pong) example,
built with the **SDL3** library. It is deliberately kept **as close as possible**
to the console version so the two can be read side by side: same grid, same
global variables, same function names, same logic. Only the drawing changes —
colored rectangles instead of printed characters.

**Game: Pong.** You control the left (green) paddle against the computer's right
(red) paddle. Bounce the ball past the opponent to score. First to 5 points wins.

## Controls

- **W** — move your paddle up
- **S** — move your paddle down
- **ESC** — quit

## How it maps to the console version

Both programs share the exact same skeleton and the same teaching concepts:

| Concept (week)              | Console version          | SDL version                         |
| --------------------------- | ------------------------ | ----------------------------------- |
| Main game loop (9)          | `while (game_running)`   | `while (game_running)` (unchanged)  |
| for loops for drawing (10)  | nested `printf` loops    | same nested loops, `draw_cell()`    |
| Functions with prototypes (11) | `move_ball`, `reset_ball`, ... | same names and logic         |
| Recursion (12)              | `countdown()`            | `countdown()` (unchanged idea)      |
| switch + integration (13)   | `switch` on `_getch()`   | `switch` on the key scancode        |
| Keyboard input              | `_kbhit()` / `_getch()`  | `SDL_PollEvent()`                   |
| Drawing                     | `printf` of text characters | `SDL_RenderFillRect` / debug text |

The game still runs on a **WIDTH × HEIGHT grid of cells** (40 × 20). Each cell is
drawn as a `CELL_SIZE`-pixel rectangle, so the window is 800 × 400. The state is
kept in the same plain global variables as the console version — **no structures
and no pointers** in the game logic. The only unavoidable pointers are the SDL
window/renderer handles and the address of the event we read; the only structure
is `SDL_FRect`, which SDL needs in order to draw a rectangle.

This version keeps the explicit `while (game_running)` loop (with `SDL_Delay(120)`
for timing) instead of SDL's callback model, precisely because the console game
is written that way.

## Building and running

> **Important:** the `SDL3/` folder is **not** included in git (it holds a
> multi-megabyte prebuilt SDK). After cloning the repository you **must** add it
> yourself first — Step 1 below. Without it the build fails immediately at
> `#include <SDL3/SDL.h>`.

### Step 1 — Get SDL3 (required)

Download the official Visual C++ development package from the SDL website
(<https://www.libsdl.org/> ▸ SDL3 ▸ *SDL3-devel-3.x.x-VC.zip*) and copy its
contents into a new `SDL3/` folder next to the project, so the layout looks
exactly like this:

```
super-simple-game-SDL/
├── main.cpp
├── super-simple-game-SDL.sln
├── super-simple-game-SDL.vcxproj
└── SDL3/
    ├── include/
    │   └── SDL3/        # SDL.h, SDL_main.h, ...
    └── lib/
        └── x64/         # SDL3.lib, SDL3.dll
```

The project is already configured to find SDL3 at these paths:

- **Include directory:** `SDL3\include`
- **Library directory:** `SDL3\lib\x64`, linking `SDL3.lib`
- A post-build step copies `SDL3.dll` next to the compiled `.exe` so the game
  runs straight away.

So once the folder is in place there is nothing else to configure.

### Step 2 — Build

1. Open `super-simple-game-SDL.sln` in **Visual Studio 2022**.
2. Choose the **x64** platform (`Debug` or `Release`).
3. Press **F5** (or Build ▸ Build Solution).

## Files

```
super-simple-game-SDL/
├── main.cpp                       # the whole game (well commented)
├── super-simple-game-SDL.sln      # Visual Studio solution
├── super-simple-game-SDL.vcxproj  # Visual Studio project (x64)
├── super-simple-game-SDL.vcxproj.filters
├── SDL3/                          # bundled SDL3 headers + library (not in git)
└── README.md                      # this file
```

## License

SDL3 is distributed under the zlib license. The game code follows the same
educational spirit as the rest of this repository.
