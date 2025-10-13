# Cross-Platform Pong Game - Visual Studio Project

A classic Pong game implemented in C programming language, now **fully cross-platform** and compatible with Windows, Linux, and macOS. This version includes complete Visual Studio project files for professional development with Player vs AI gameplay.

## 🌍 Cross-Platform Features

This implementation combines cross-platform compatibility with Visual Studio project integration:

- **Windows Support**: Native Windows console functions with Visual Studio integration
- **Linux Support**: POSIX terminal control and ANSI escape sequences
- **macOS Support**: Compatible with Unix-like systems using standard terminal libraries
- **Visual Studio Integration**: Complete project files for professional development
- **Pure C Implementation**: No external dependencies beyond standard C library

## 🎮 Game Features

- **Classic Pong Gameplay**: Player vs AI in console environment!
- **Player vs AI**: Play against an intelligent computer opponent
- **Score Tracking**: First player to reach 5 points wins
- **Real-time Controls**: Smooth paddle movement with W/S keys
- **Intelligent AI**: Computer opponent with realistic behavior
- **Collision Physics**: Realistic ball bouncing off paddles and walls
- **Cross-Platform Graphics**: ANSI escape sequences for universal terminal control

## How to Play

### Controls
- **W** - Move your paddle up
- **S** - Move your paddle down  
- **ESC** - Quit the game

### Gameplay
1. Your paddle is on the left side of the screen (Player)
2. The AI paddle is on the right side (Computer opponent)
3. Use W and S keys to move your paddle up and down
4. Try to hit the ball back to the AI's side
5. You score a point when the ball goes past the AI's paddle
6. The AI scores when the ball goes past your paddle
7. First player to reach 5 points wins!

## 🔧 Compilation

### Using Visual Studio (Windows - Recommended)

This project includes complete Visual Studio solution and project files:

1. **Open the project:**
   - Open `PongGame.vcxproj` directly in Visual Studio
   - Or use File → Open → Project/Solution

2. **Project Configuration:**
   - **Target**: Console Application
   - **Language**: C (CompileAsC setting)
   - **Platforms**: Win32 and x64
   - **Configurations**: Debug and Release
   - **Toolset**: v143 (Visual Studio 2022)

3. **Build the project:**
   - Press `Ctrl+Shift+B` to build
   - Or Build → Build Solution
   - Or press `F5` to build and run

4. **Run the game:**
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
- **PongGame.vcxproj**: Main project configuration file
- **main.c**: Cross-platform source code with Visual Studio compatibility
- **README.md**: This documentation file

### Project Configuration Details
```xml
<PropertyGroup>
  <ConfigurationType>Application</ConfigurationType>
  <PlatformToolset>v143</PlatformToolset>
  <CharacterSet>Unicode</CharacterSet>
</PropertyGroup>

<ClCompile>
  <CompileAs>CompileAsC</CompileAs>
  <PreprocessorDefinitions>
    _CRT_SECURE_NO_WARNINGS;
    %(PreprocessorDefinitions)
  </PreprocessorDefinitions>
</ClCompile>
```

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

### Core Data Structures
```c
typedef struct {
    int x, y;           // Position
    int dx, dy;         // Velocity
} Ball;

typedef struct {
    int x, y;           // Position
    int height;         // Paddle size
} Paddle;

typedef struct {
    int player_score;   // Human player score
    int ai_score;       // AI opponent score
    int game_running;   // Game state flag
} GameState;
```

### Key Functions
- `initialize_game()` - Set up game objects and initial state
- `draw_game()` - Render the complete game field with ANSI graphics
- `update_ball()` - Handle ball movement and wall collisions
- `update_player_paddle()` - Process player W/S key input
- `update_ai_paddle()` - AI logic for computer opponent
- `check_collisions()` - Detect ball-paddle collisions with angle calculation
- `reset_ball()` - Reset ball position after scoring

### AI System Implementation
```c
void update_ai_paddle(void) {
    int paddle_center = ai_paddle.y + ai_paddle.height / 2;

    // Move towards ball with some delay for difficulty
    if (ball.y < paddle_center && ai_paddle.y > 1) {
        ai_paddle.y--;
    }
    else if (ball.y > paddle_center &&
             ai_paddle.y + ai_paddle.height < FIELD_HEIGHT - 2) {
        ai_paddle.y++;
    }
}
```

### Technical Details
- **Field Size**: 80x25 characters
- **Paddle Height**: 5 characters  
- **Winning Score**: 5 points
- **Game Speed**: 100ms update cycle
- **AI Difficulty**: Balanced for competitive gameplay
- **Collision Detection**: Accurate ball-paddle collision with angle variation

### Visual Studio Project Configuration

This Visual Studio project is optimized for C development:

- **Platform Support**: Win32 and x64 architectures
- **Configuration Types**: Debug and Release builds
- **Compiler Settings**: 
  - `CompileAs`: CompileAsC (ensures C compilation, not C++)
  - `SDLCheck`: false (allows traditional C functions)
  - `PrecompiledHeader`: NotUsing (simple compilation)
- **Preprocessor Definitions**:
  - `_CRT_SECURE_NO_WARNINGS` - Suppresses secure CRT warnings
  - Platform-specific definitions for cross-compatibility
- **Subsystem**: Console Application
- **Character Set**: Unicode support

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

1. **Professional Development Environment**: Complete Visual Studio project setup
2. **Educational Value**: Demonstrates C programming and game development
3. **Cross-Platform Compatibility**: Runs on Windows, Linux, and macOS
4. **No Dependencies**: Pure standard C implementation
5. **AI Programming**: Introduction to computer opponent logic
6. **Visual Studio Best Practices**: Proper project configuration for C development

## 🎯 Technical Highlights

### C Programming Concepts Demonstrated
- **Cross-Platform Programming**: Conditional compilation for different OS
- **Structured Programming**: Clean function and data organization
- **Game Loop Architecture**: Initialize → Update → Render → Repeat
- **State Management**: Global game state with structured data
- **AI Programming**: Simple but effective computer opponent
- **Console Graphics**: ANSI escape sequences for visual output
- **Real-time Input**: Non-blocking keyboard input handling

### Professional Development Practices
- **Visual Studio Integration**: Complete project configuration
- **Cross-Platform Design**: Single codebase for multiple platforms
- **Code Organization**: Modular function design
- **Documentation**: Comprehensive inline comments
- **Error Handling**: Robust terminal setup and cleanup

### Game Architecture Flow
1. **Initialize**: Configure terminal, set up game objects
2. **Welcome Screen**: Display instructions and wait for start
3. **Main Game Loop**:
   - Clear screen with ANSI sequences
   - Draw game field, paddles, ball, and score
   - Process player input (W/S keys)
   - Update AI paddle position intelligently
   - Move ball and handle wall collisions
   - Check paddle collisions with angle calculation
   - Check scoring conditions and update scores
   - Control game speed (100ms delay)
4. **Game Over**: Display winner and final score
5. **Cleanup**: Restore terminal settings

---

**A professional cross-platform Pong implementation with AI opponent!** 🎮

*Perfect for learning C programming, cross-platform development, AI basics, and Visual Studio project management.*
