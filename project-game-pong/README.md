# Project Game Pong - Structured Programming in C

A collection of Pong game implementations demonstrating various programming approaches, libraries, and development environments. This project showcases the evolution from simple console-based games to advanced graphics-based implementations.

## Project Overview

This repository contains multiple implementations of the classic Pong game, each designed to demonstrate different aspects of structured programming in C/C++. The implementations progress from basic console output to sophisticated graphics libraries.

## Project Structure

```
project-game-pong/
├── 03-simple-visual-studio-sdl/ # SDL3 graphics implementation
│   └── simplePongSDL/
│       ├── main.cpp            # Main game implementation
│       └── README.md           # SDL version documentation
└── README.md                   # This file
```

## Game Implementations

### SDL3 Graphics Version
**Location:** `03-simple-visual-studio-sdl/simplePongSDL/`
- **Technology:** C++ with SDL3 graphics library
- **Features:**
  - Real-time 2D graphics rendering
  - Smooth animation with delta time
  - Hardware-accelerated rendering
  - Professional game loop architecture using SDL3 callbacks
  - Keyboard input handling (W/S and Arrow keys)
  - Physics-based ball movement and collision
  - Dynamic paddle collision with angle variation
  - Score tracking and display
  - Game reset functionality
- **Learning Focus:**
  - Graphics programming fundamentals
  - Event-driven programming with SDL3 callbacks
  - Real-time systems and frame-independent movement
  - External library integration
  - Game physics and collision detection
  - Object-oriented design patterns

**Key Features:**
- Two-player local multiplayer
- 800x600 pixel game window
- Professional game architecture using SDL_AppInit, SDL_AppEvent, SDL_AppIterate callbacks
- AABB collision detection
- Delta time-based movement for consistent gameplay across different frame rates
- Visual elements: center line, score display, control instructions

### Future Implementations (Planned)

#### Console Basic Version
**Location:** `01-console-basic/` *(planned)*
- **Technology:** Pure C with console I/O
- **Features:** 
  - Text-based game representation
  - Simple keyboard input
  - Basic collision detection
  - Score tracking

#### Console Advanced Version
**Location:** `02-console-advanced/` *(planned)*
- **Technology:** Enhanced C with advanced console features
- **Features:**
  - Improved console graphics
  - Better input handling
  - Enhanced visual representation

#### OpenGL Version
**Location:** `04-opengl-version/` *(planned)*
- **Technology:** C++ with OpenGL
- **Features:**
  - 3D graphics capabilities
  - Shader programming
  - Advanced visual effects

## Development Progression

### Current Phase: Graphics Programming
The project currently demonstrates advanced graphics-based game development:
- SDL3 library integration
- Event-driven programming with callback architecture
- Real-time rendering and animation
- Professional game engine concepts
- Hardware-accelerated 2D graphics

### Future Phases (Planned)

#### Phase 1: Console Foundations *(planned)*
- Basic C programming concepts
- Console input/output operations
- Simple game loop implementation

#### Phase 2: Advanced Console Programming *(planned)*
- Advanced console manipulation
- Improved code organization
- Better data structures

#### Phase 3: Advanced Graphics *(planned)*
- 3D graphics and mathematics
- Shader programming
- Cross-platform development

## Learning Objectives

### Programming Concepts Demonstrated
- **Structured Programming:** Function-based code organization with clear separation of concerns
- **Data Structures:** GameObject structs with position, dimensions, and velocity
- **Algorithms:** AABB collision detection, physics simulation
- **Memory Management:** Proper SDL resource management
- **Input/Output:** Event-based input handling with SDL3

### Game Development Concepts
- **Game Loop:** SDL3 callback-based architecture (Init, Event, Iterate, Quit)
- **Physics:** Velocity-based movement, collision response, angle calculation
- **Graphics:** 2D rendering with SDL_Renderer, real-time animation
- **User Interface:** Keyboard input mapping, on-screen text display
- **State Management:** Game state tracking (scores, ball position, paddle states)

### Software Engineering
- **Code Organization:** Modular design with clear function separation
- **Documentation:** Comprehensive code comments and project documentation
- **Build Systems:** Visual Studio project configuration with SDL3 integration
- **External Libraries:** Professional library integration and dependency management

## Getting Started

### Prerequisites
- **Visual Studio 2019 or later** (Windows development environment)
- **SDL3 development libraries** 
- **C++ compiler** with C++11 support

### Building and Running

#### SDL3 Version (Current Implementation)
1. Install SDL3 development libraries
2. Open the Visual Studio project in `03-simple-visual-studio-sdl/simplePongSDL/`
3. Configure project settings:
   - Set include directories for SDL3 headers
   - Set library directories for SDL3 libraries
   - Link against SDL3.lib and SDL3main.lib
4. Build and run the project

### Controls
- **Player 1 (Left Paddle):** W (up) / S (down)
- **Player 2 (Right Paddle):** UP Arrow (up) / DOWN Arrow (down)
- **Game Controls:** R (reset) / ESC (quit)

## Technical Implementation Highlights

### SDL3 Callback Architecture
The game uses SDL3's modern callback-based main loop:
```cpp
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])    // Initialization
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)          // Event handling  
SDL_AppResult SDL_AppIterate(void* appstate)                         // Game loop
void SDL_AppQuit(void* appstate, SDL_AppResult result)               // Cleanup
```

### Physics System
- **Delta Time Movement:** Frame-rate independent physics
- **Collision Detection:** AABB algorithm for paddle and wall collisions
- **Dynamic Ball Physics:** Angle changes based on paddle collision point

## Contributing

This project is part of a structured programming course. The current implementation serves as an advanced example of graphics programming with SDL3.

Contributions should focus on:
- Code clarity and educational value
- Comprehensive documentation
- Progressive complexity
- Best practices demonstration

## Educational Resources

### Recommended Reading
- "The C Programming Language" by Kernighan & Ritchie
- "Game Programming Patterns" by Robert Nystrom
- SDL3 documentation and tutorials
- Graphics programming fundamentals

### Key Concepts Covered
- Structured programming principles
- Game development fundamentals
- Graphics programming basics
- Real-time systems
- Event-driven architecture

## License

This educational project follows standard academic licensing for course materials. Individual implementations may have specific licensing requirements based on the libraries used (e.g., SDL3 uses zlib license).
- Event-driven architecture

## License

This educational project follows standard academic licensing for course materials. Individual implementations may have specific licensing requirements based on the libraries used (e.g., SDL3 uses zlib license).
