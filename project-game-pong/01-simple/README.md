# Pong Game

A classic Pong game implemented in C programming language using only standard libraries and Windows console functions.

## Features

- **Classic Pong Gameplay**: Two paddles, one ball, endless fun!
- **Player vs AI**: Play against a simple computer opponent
- **Score Tracking**: First player to reach 5 points wins
- **Real-time Controls**: Smooth paddle movement with W/S keys
- **Collision Physics**: Realistic ball bouncing off paddles and walls
- **Console-based Graphics**: Pure C implementation using Windows console

## How to Play

### Controls

- **W** - Move your paddle up
- **S** - Move your paddle down  
- **ESC** - Quit the game

### Gameplay

1. Your paddle is on the left side of the screen
2. The AI paddle is on the right side
3. Use W and S keys to move your paddle up and down
4. Try to hit the ball back to the AI's side
5. You score a point when the ball goes past the AI's paddle
6. The AI scores when the ball goes past your paddle
7. First player to reach 5 points wins!

## Compilation

To compile the game, you need a C compiler (like GCC):

```bash
gcc -o pong.exe main.c
```

## Running the Game

After compilation, run the executable:

```bash
./pong.exe
```

## Game Structure

### Key Components

1. **Ball Structure**: Tracks position (x,y) and velocity (dx,dy)
2. **Paddle Structure**: Tracks position and height
3. **Game State**: Manages scores and game running status
4. **Physics Engine**: Handles ball movement and collision detection
5. **AI Logic**: Simple computer opponent that follows the ball
6. **Input Handler**: Processes keyboard input for player control
7. **Renderer**: Draws the game field, paddles, ball, and score

### Technical Details

- **Field Size**: 80x25 characters
- **Paddle Height**: 5 characters
- **Ball Speed**: Updates every 100ms
- **AI Difficulty**: AI follows ball position with slight delay
- **Collision Detection**: Pixel-perfect collision between ball and paddles

## Code Features

This implementation demonstrates several C programming concepts:

- **Structures**: Used for Ball, Paddle, and GameState
- **Functions**: Modular code organization
- **Loops**: Main game loop and rendering loops
- **Conditional Logic**: Collision detection and game state management
- **Input/Output**: Console manipulation and keyboard input
- **Random Numbers**: For ball direction after scoring
- **System Calls**: For screen clearing and cursor positioning

## Requirements

- Windows operating system (uses Windows.h for console functions)
- C compiler (GCC recommended)
- Console/Command Prompt for running

## Game Flow

1. **Initialize**: Set up game objects and initial positions
2. **Game Loop**:
   - Clear screen
   - Draw current game state
   - Process player input
   - Update AI paddle position
   - Move ball and check collisions
   - Check for scoring conditions
   - Repeat until game ends
3. **Game Over**: Display final score and winner

Enjoy playing this classic arcade game implemented in pure C!
