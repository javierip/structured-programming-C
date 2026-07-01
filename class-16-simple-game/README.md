# Simple Pong Game

A minimal Pong game that integrates concepts seen from week 9 to 13:
`while` game loop (week 9), `for` loops to draw the field (week 10), functions
with prototypes (week 11), recursion for the start countdown (week 12), and a
`switch` for keyboard control (week 13). Uses only simple variables — no
structures and no pointers in the game logic.

It comes in two versions that share the exact same skeleton so they can be read
side by side — only the drawing changes:

* **Console version** — draws the field with `printf` characters.
* **SDL3 version** — draws the same field as colored rectangles in a window.

## Contents

* `super-simple-game/super-simple-game.cpp`: the console game source code.
* `super-simple-game-SDL/`: the graphical (SDL3) version, as a Visual Studio
  2022 solution. See its own [README](super-simple-game-SDL/README.md) for
  build instructions. The bundled `SDL3/` SDK is not tracked in git — the
  linked README explains how to obtain it.

## How to play

Same controls in both versions:

* Move your paddle with `W` (up) and `S` (down).
* The computer controls the right paddle.
* First to 5 points wins. Press `ESC` to quit.
