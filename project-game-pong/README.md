# Project Game Pong - Structured Programming in C

A progressive collection of Pong game implementations demonstrating the evolution from console-based programming to advanced graphics development in C/C++.

## Project Structure

```
project-game-pong/
├── 01-simple/                      # Console-based C implementation
│   ├── main.c                     # Cross-platform console game
│   └── README.md                  # Console version docs
├── 02-simple-visual-studio/       # Visual Studio console project
│   ├── main.c                     # Enhanced console version
│   ├── PongGame.vcxproj           # VS project file
│   └── README.md                  # VS project docs
├── 03-simple-visual-studio-sdl/   # SDL3 graphics implementation
│   └── simplePongSDL/
│       ├── main.cpp               # SDL3 graphics game
│       ├── simplePongSDL.vcxproj  # VS project with SDL3
│       └── README.md              # SDL3 version docs
└── README.md                      # This file
```

## Implementations Overview

### 1. Console Version (`01-simple`)

- **Technology:** Pure C with ANSI terminal control
- **Platform:** Cross-platform (Windows, Linux, macOS)
- **Features:** Player vs AI, 80x25 character display, W/S controls
- **Focus:** Basic C programming, cross-platform development

### 2. Visual Studio Console (`02-simple-visual-studio`)

- **Technology:** C with Visual Studio project integration
- **Platform:** Cross-platform with professional tooling
- **Features:** Enhanced console graphics, structured project files
- **Focus:** Professional development environment, project organization

### 3. SDL3 Graphics (`03-simple-visual-studio-sdl`)

- **Technology:** C++ with SDL3 graphics library
- **Platform:** Windows with Visual Studio
- **Features:** 800x600 graphics, Player vs AI, smooth animation
- **Focus:** Graphics programming, real-time systems, AI implementation

## Quick Start

### Console Versions (01 & 02)

```bash
# Compile and run
gcc -o pong main.c
./pong
```

### SDL3 Graphics Version (03)

1. Install SDL3 development libraries
2. Open `simplePongSDL.vcxproj` in Visual Studio
3. Configure SDL3 include/library paths
4. Build and run (F5)

## Game Features

| Feature | Console | VS Console | SDL3 Graphics |
|---------|---------|------------|---------------|
| Player vs AI | ✅ | ✅ | ✅ |
| Cross-platform | ✅ | ✅ | 🔶 Windows |
| Graphics | ASCII | ASCII | 2D Hardware |
| Controls | W/S | W/S | W/S + Arrow Keys |
| Score System | ✅ | ✅ | ✅ |
| Real-time Physics | Basic | Basic | Advanced |

## Learning Progression

1. **Start with `01-simple`** - Learn C fundamentals and cross-platform programming
2. **Move to `02-simple-visual-studio`** - Understand professional development tools
3. **Advance to `03-simple-visual-studio-sdl`** - Explore graphics programming and AI

## Key Learning Concepts

- **Structured Programming:** Function organization, data structures
- **Cross-Platform Development:** Conditional compilation, platform abstraction
- **Game Programming:** Game loops, collision detection, AI logic
- **Graphics Programming:** SDL3 integration, real-time rendering
- **Professional Development:** Visual Studio, project management

## Controls (All Versions)

- **W/S** or **UP/DOWN** - Move paddle
- **ESC** - Quit game
- **R** - Reset (SDL3 version)

## Requirements

- **C Compiler:** GCC, Clang, or Visual Studio
- **SDL3:** Required for graphics version only
- **Terminal:** 80x25 minimum for console versions

---

**Three implementations, one learning journey - from console to graphics!** 🎮
