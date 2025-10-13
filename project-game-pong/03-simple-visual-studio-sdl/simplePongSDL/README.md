# Simple Pong SDL

A classic Pong game implementation using SDL3 and C++. This project demonstrates fundamental game programming concepts including real-time rendering, collision detection, input handling, AI programming, and game state management.

## Overview

This is a single-player Pong game where the human player controls the left paddle against an AI opponent controlling the right paddle. The game features smooth gameplay with physics-based ball movement, intelligent AI behavior, and structured game state management.

## Features

- **Single-player vs AI gameplay**
- **Intelligent AI opponent** with realistic movement and difficulty balancing
- **Real-time physics simulation** with delta time-based movement
- **Collision detection** between ball, paddles, and walls
- **Structured game state** using GameState structure for organized code
- **Scoring system** with automatic score tracking
- **Smooth graphics** rendered at 60 FPS
- **Responsive controls** with multiple input options
- **Game reset functionality**

## Controls

### Player (Left Paddle)
- **W** or **UP Arrow** - Move paddle up
- **S** or **DOWN Arrow** - Move paddle down

### Game Controls
- **R** - Reset game (scores and ball position)
- **ESC** - Quit game

## Game Rules

1. Player controls the left paddle, AI controls the right paddle
2. The ball bounces off the top and bottom walls
3. Player must hit the ball with their paddle to keep it in play
4. When the ball goes off the left side, AI scores a point
5. When the ball goes off the right side, player scores a point
6. The ball's angle changes based on where it hits the paddle
7. Game continues indefinitely until manually reset or quit

## Technical Implementation

### Game Architecture
- **SDL3-based**: Uses SDL3 for graphics rendering and input handling
- **Callback-driven**: Implements SDL's callback-based main loop
- **Structured programming**: Uses GameState structure for organized state management
- **Component-based**: Game objects use GameObject structure
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

#### GameState Structure
```cpp
struct GameState {
    int leftScore;
    int rightScore;
    Uint64 lastTime;
    bool ballActive;
    bool wPressed;
    bool sPressed;
    bool upPressed;
    bool downPressed;
    float aiReactionDelay;
    Uint64 lastAIUpdate;
};
```

#### Game Constants
- Window: 800x600 pixels
- Paddle: 15x80 pixels
- Ball: 15x15 pixels
- Player Paddle Speed: 400 pixels/second
- AI Paddle Speed: 320 pixels/second (balanced for difficulty)
- Ball Speed: 300 pixels/second

#### Key Functions
- `SDL_AppInit()` - Initialize game window and objects
- `SDL_AppEvent()` - Handle keyboard input and events
- `SDL_AppIterate()` - Main game loop (update and render)
- `SDL_AppQuit()` - Cleanup on exit
- `update_ai_paddle()` - AI logic for computer opponent
- `InitializeGame()` - Initialize all game objects and state

### AI System
The AI opponent features intelligent behavior:
- **Reactive Movement**: AI only moves when ball is approaching
- **Difficulty Balancing**: Slightly slower than human player (320 vs 400 pixels/second)
- **Tolerance Zone**: AI doesn't move when close enough to ball (15 pixel tolerance)
- **Center Return**: When ball moves away, AI slowly returns to center position
- **Realistic Behavior**: Mimics human-like reaction patterns

### Physics System
- **Collision Detection**: AABB (Axis-Aligned Bounding Box) collision
- **Ball Physics**: Velocity-based movement with wall bouncing
- **Paddle Interaction**: Ball angle changes based on collision point
- **Boundary Constraints**: Paddles constrained to screen bounds
- **Delta Time Movement**: Frame-rate independent physics

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

### AI Logic
```cpp
void update_ai_paddle(float deltaTime) {
    float paddle_center = rightPaddle.y + rightPaddle.h / 2.0f;
    float ball_center = ball.y + ball.h / 2.0f;
    
    if (ball.vx > 0) { // Ball moving towards AI
        float diff = ball_center - paddle_center;
        float tolerance = 15.0f;
        
        if (diff > tolerance) {
            rightPaddle.vy = AI_PADDLE_SPEED;
        } else if (diff < -tolerance) {
            rightPaddle.vy = -AI_PADDLE_SPEED;
        } else {
            rightPaddle.vy = 0;
        }
    } else { // Ball moving away, return to center
        // Gradual return to center logic
    }
}
```

### Structured Game State
```cpp
static GameState gameState;

// Centralized state management
gameState.leftScore = 0;
gameState.rightScore = 0;
gameState.ballActive = true;
// Input handling
if (gameState.wPressed || gameState.upPressed) 
    leftPaddle.vy = -PADDLE_SPEED;
```

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
- **AI programming techniques**
- **Structured programming with organized state management**
- **Real-time graphics rendering**
- **Input handling with multiple key options**
- **Basic physics simulation**
- **Collision detection algorithms**
- **Frame-rate independent game logic**
- **Professional code organization**

## Future Enhancements

Potential improvements could include:
- Multiple AI difficulty levels
- Sound effects and background music
- Particle effects for ball collisions
- Menu system with AI difficulty settings
- High score persistence
- Improved graphics and animations
- Power-ups and special effects
- Tournament mode against progressively harder AI

## License

This project uses SDL3, which is provided under the zlib license. The game code follows the same licensing terms as specified in the source files.
