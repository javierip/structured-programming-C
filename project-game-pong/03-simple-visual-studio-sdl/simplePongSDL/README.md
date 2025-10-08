# Simple Pong SDL

A classic Pong game implementation using SDL3 and C. This project demonstrates fundamental game programming concepts including real-time rendering, collision detection, input handling, and game state management.

## Overview

This is a two-player Pong game where players control paddles to hit a ball back and forth. The game features smooth gameplay with physics-based ball movement and paddle collision detection.

## Features

- **Two-player local multiplayer gameplay**
- **Real-time physics simulation** with delta time-based movement
- **Collision detection** between ball, paddles, and walls
- **Scoring system** with automatic score tracking
- **Smooth graphics** rendered at 60 FPS
- **Responsive controls** with continuous input handling
- **Game reset functionality**

## Controls

### Player 1 (Left Paddle)
- **W** - Move paddle up
- **S** - Move paddle down

### Player 2 (Right Paddle)
- **UP Arrow** - Move paddle up
- **DOWN Arrow** - Move paddle down

### Game Controls
- **R** - Reset game (scores and ball position)
- **ESC** - Quit game

## Game Rules

1. Players control paddles on opposite sides of the screen
2. The ball bounces off the top and bottom walls
3. Players must hit the ball with their paddle to keep it in play
4. When the ball goes off the left or right side, the opposite player scores a point
5. The ball's angle changes based on where it hits the paddle
6. Game continues indefinitely until manually reset or quit

## Technical Implementation

### Game Architecture
- **SDL3-based**: Uses SDL3 for graphics rendering and input handling
- **Callback-driven**: Implements SDL's callback-based main loop
- **Component-based**: Game objects use a simple GameObject structure
- **Frame-independent**: Uses delta time for consistent movement speed

### Core Components

#### GameObject Structure
```cpp
struct GameObject {
    float x, y;      // Position
    float w, h;      // Dimensions
    float vx, vy;    // Velocity
};
```

#### Game Constants
- Window: 800x600 pixels
- Paddle: 15x80 pixels
- Ball: 15x15 pixels
- Paddle Speed: 400 pixels/second
- Ball Speed: 300 pixels/second

#### Key Functions
- `SDL_AppInit()` - Initialize game window and objects
- `SDL_AppEvent()` - Handle keyboard input and events
- `SDL_AppIterate()` - Main game loop (update and render)
- `SDL_AppQuit()` - Cleanup on exit

### Physics System
- **Collision Detection**: AABB (Axis-Aligned Bounding Box) collision
- **Ball Physics**: Velocity-based movement with wall bouncing
- **Paddle Interaction**: Ball angle changes based on collision point
- **Boundary Constraints**: Paddles constrained to screen bounds

## Build Requirements

### Dependencies
- **SDL3** development libraries
- **C++** compiler with C++11 support
- **Visual Studio** 2019 or later (Windows)

### Build Instructions

#### Windows (Visual Studio)
1. Install SDL3 development libraries
2. Configure project to link against SDL3
3. Set include directories for SDL3 headers
4. Build and run the project

#### Required SDL3 Libraries
- SDL3.lib
- SDL3main.lib

## Project Structure

```
simplePongSDL/
├── main.cpp          # Main game implementation
├── README.md         # This documentation
└── [project files]   # Visual Studio project files
```

## Code Highlights

### Game Loop
The game uses SDL3's callback-based architecture:
- `SDL_AppInit()` - One-time initialization
- `SDL_AppEvent()` - Event handling per frame
- `SDL_AppIterate()` - Game logic and rendering per frame
- `SDL_AppQuit()` - Cleanup

### Collision System
```cpp
bool CheckCollision(const GameObject& a, const GameObject& b) {
    return (a.x < b.x + b.w &&
            a.x + a.w > b.x &&
            a.y < b.y + b.h &&
            a.y + a.h > b.y);
}
```

### Ball Physics
The ball's trajectory changes based on where it hits the paddle, creating more dynamic gameplay:
```cpp
float relativeIntersectY = (ball.y + ball.h / 2) - (paddle.y + paddle.h / 2);
float normalizedIntersectY = relativeIntersectY / (paddle.h / 2);
ball.vy = normalizedIntersectY * BALL_SPEED * 0.75f;
```

## Learning Objectives

This project demonstrates:
- **Game programming fundamentals**
- **Real-time graphics rendering**
- **Input handling and game state management**
- **Basic physics simulation**
- **Collision detection algorithms**
- **Frame-rate independent game logic**

## Future Enhancements

Potential improvements could include:
- AI opponent for single-player mode
- Sound effects and background music
- Particle effects for ball collisions
- Menu system with difficulty settings
- High score persistence
- Improved graphics and animations

## License

This project uses SDL3, which is provided under the zlib license. The game code follows the same licensing terms as specified in the source files.
