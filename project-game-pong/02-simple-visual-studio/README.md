# Cross-Platform Pong Game - Visual Studio Project

A classic Pong game implemented in C programming language, now **fully cross-platform** and compatible with Windows, Linux, and macOS. This version includes complete Visual Studio project files for professional development.

## 🌍 Cross-Platform Features

This implementation combines cross-platform compatibility with Visual Studio project integration:

- **Windows Support**: Native Windows console functions with Visual Studio integration
- **Linux Support**: POSIX terminal control and ANSI escape sequences
- **macOS Support**: Compatible with Unix-like systems using standard terminal libraries
- **Visual Studio Integration**: Complete project files for professional development
- **Pure C Implementation**: No external dependencies beyond standard C library

## 🎮 Game Features

- **Classic Pong Gameplay**: Two paddles, one ball, endless fun!
- **Player vs AI**: Play against a simple computer opponent
- **Score Tracking**: First player to reach 5 points wins
- **Real-time Controls**: Smooth paddle movement with W/S keys
- **Collision Physics**: Realistic ball bouncing off paddles and walls
- **Cross-Platform Graphics**: ANSI escape sequences for universal terminal control

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

## 🔧 Compilation

### Using Visual Studio (Windows - Recommended)

This project includes complete Visual Studio solution and project files for professional development:

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
   - Executable will be created in `x64/Debug/` or `x64/Release/` folder

### Cross-Platform Command Line Compilation

#### Windows (with GCC/MinGW)
```bash
gcc -o pong.exe main.c
```

#### Linux
```bash
gcc -o pong main.c
```

#### macOS
```bash
clang -o pong main.c
# or
gcc -o pong main.c
```

### Visual Studio Command Line (Windows)
```bash
cl main.c /Fe:pong.exe
```

## 🚀 Running the Game

### Windows
- **From Visual Studio**: Press `F5` or `Ctrl+F5`
- **From Command Line**: `./pong.exe` or `x64/Debug/PongGame.exe`

### Linux/macOS
```bash
./pong
```

## 🏗️ Project Structure

### Visual Studio Files
- **PongGame.sln**: Visual Studio solution file
- **PongGame.vcxproj**: Main project configuration file
- **PongGame.vcxproj.filters**: File organization for Solution Explorer
- **PongGame.vcxproj.user**: User-specific project settings
- **.vs/**: Visual Studio metadata directory
- **x64/**: Build output directory

### Source Files
- **main.c**: Cross-platform source code with Visual Studio compatibility
- **README.md**: This documentation file

## 🎯 Cross-Platform Architecture

### Platform Detection System
The game uses conditional compilation to provide platform-specific implementations:

```c
#ifdef _WIN32
    // Windows-specific code using conio.h and windows.h
    #define PLATFORM_WINDOWS
#elif defined(__linux__) || defined(__APPLE__)
    // Unix-like systems using POSIX terminal control
    #define PLATFORM_UNIX
#endif
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

This Visual Studio project is configured for cross-platform development:

- **Platform Support**: Both Win32 and x64 architectures
- **Configuration**: Debug and Release configurations
- **Compiler Settings**: Configured to compile as C code (not C++)
- **Cross-Platform Code**: Conditional compilation for Windows/Unix systems
- **Preprocessor Definitions**:
  - `_CRT_SECURE_NO_WARNINGS` - Suppresses secure CRT warnings
  - `_CRT_NONSTDC_NO_DEPRECATE` - Suppresses POSIX function warnings
- **Console Application**: Optimized for console-based game development
- **No Precompiled Headers**: Simple compilation without PCH overhead

### Cross-Platform Functions

The implementation includes platform-specific abstractions:

1. **`cross_platform_sleep()`** - Sleep/delay function
   - Windows: `Sleep(milliseconds)`
   - Unix: `usleep(milliseconds * 1000)`

2. **`cross_platform_kbhit()`** - Non-blocking keyboard input detection
   - Windows: `_kbhit()`
   - Unix: `fcntl()` with `O_NONBLOCK`

3. **`cross_platform_getch()`** - Character input without Enter
   - Windows: `_getch()`
   - Unix: `tcgetattr()/tcsetattr()` terminal manipulation

4. **Universal Screen Control**:
   - Screen clearing: ANSI escape sequence `\033[2J\033[H`
   - Cursor positioning: ANSI escape sequence `\033[y;xH`

## Code Features

This implementation demonstrates several C programming concepts:

- **Structures**: Used for Ball, Paddle, and GameState
- **Functions**: Modular code organization
- **Loops**: Main game loop and rendering loops
- **Conditional Logic**: Collision detection and game state management
- **Input/Output**: Console manipulation and keyboard input
- **Random Numbers**: For ball direction after scoring
- **System Calls**: For screen clearing and cursor positioning

## 📋 Requirements

### For Visual Studio Development (Windows)

- **Visual Studio 2019 or later** (Community, Professional, or Enterprise)
- **Windows SDK 10.0** or later
- **MSVC v143 compiler toolset** (included with Visual Studio)
- **Windows operating system**

### Cross-Platform Development

#### Windows
- **MinGW/GCC**: For cross-platform compilation
- **Windows Console**: Built-in support for ANSI sequences (Windows 10+)

#### Linux
- **GCC or Clang**: Standard system compiler
- **Terminal**: Any POSIX-compliant terminal (bash, zsh, etc.)
- **Libraries**: Standard C library with POSIX extensions

#### macOS
- **Xcode Command Line Tools**: `xcode-select --install`
- **Clang or GCC**: Available through Xcode or Homebrew
- **Terminal**: Built-in Terminal.app or any compatible terminal

### Universal Requirements
- C compiler (GCC, Clang, or MSVC)
- Terminal/Console with ANSI escape sequence support

## Game Flow

## 🌟 Key Benefits

1. **Professional Development**: Complete Visual Studio project setup
2. **True Cross-Platform**: Single source code works on Windows, Linux, and macOS
3. **No External Dependencies**: Pure standard C libraries only
4. **Educational Value**: Demonstrates professional C development practices
5. **Performance**: Native performance on each platform
6. **Maintainable**: Clean separation of platform-specific code

## 🎯 Technical Highlights

### C Programming Concepts Demonstrated
- **Conditional Compilation**: Platform-specific code paths
- **Structure Programming**: Clean data organization
- **Function Abstraction**: Cross-platform API design
- **Terminal Control**: Low-level console manipulation
- **Non-blocking I/O**: Real-time input handling
- **Visual Studio Integration**: Professional project setup

### Game Architecture
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

---

**Enjoy this professional-grade cross-platform Pong implementation!** 🎮

*Perfect for learning C programming, cross-platform development, and Visual Studio project management.*
