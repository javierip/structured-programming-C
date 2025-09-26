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

### Using Visual Studio (Recommended)

This project includes Visual Studio solution and project files for easy compilation:

1. **Open the solution:**
   - Double-click `PongGame.sln` to open in Visual Studio
   - Or open Visual Studio and use File → Open → Project/Solution

2. **Build the project:**
   - Press `Ctrl+Shift+B` to build the solution
   - Or go to Build → Build Solution
   - Or press `F5` to build and run

3. **Run the game:**
   - Press `F5` to run with debugging
   - Or `Ctrl+F5` to run without debugging
   - Executable will be created in `Debug/` or `Release/` folder

### Using Command Line (Alternative)

To compile with GCC or other C compilers:

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

### Visual Studio Project Configuration

This Visual Studio project is configured with:

- **Platform Support**: Both Win32 and x64 architectures
- **Configuration**: Debug and Release configurations
- **Compiler Settings**: Configured to compile as C code (not C++)
- **Preprocessor Definitions**: 
  - `_CRT_SECURE_NO_WARNINGS` - Suppresses secure CRT warnings
  - `_CRT_NONSTDC_NO_DEPRECATE` - Suppresses POSIX function warnings
- **Console Application**: Optimized for console-based game development
- **No Precompiled Headers**: Simple compilation without PCH overhead

### Project Files

- **PongGame.sln**: Visual Studio solution file
- **PongGame.vcxproj**: Main project configuration file
- **PongGame.vcxproj.filters**: File organization for Solution Explorer
- **main.c**: Main source code file
- **README.md**: This documentation file

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

### For Visual Studio Development

- **Visual Studio 2019 or later** (Community, Professional, or Enterprise)
- **Windows SDK 10.0** or later
- **MSVC v143 compiler toolset** (included with Visual Studio)
- **Windows operating system** (uses Windows.h for console functions)

### Alternative Requirements

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
