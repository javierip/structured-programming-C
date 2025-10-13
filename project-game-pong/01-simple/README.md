# Cross-Platform Pong Game - Console Version

A classic Pong game implemented in C programming language using only standard libraries, now **fully cross-platform** and compatible with Windows, Linux, and macOS. This is the foundational console-based implementation in the Pong game project series.

## 🌍 Cross-Platform Features

This version demonstrates fundamental cross-platform programming concepts:

- **Windows Support**: Uses Windows.h for native console functions when available
- **Linux Support**: Uses POSIX terminal control and ANSI escape sequences
- **macOS Support**: Compatible with Unix-like systems using standard terminal libraries
- **Pure C Implementation**: No external dependencies beyond standard C library
- **Educational Focus**: Demonstrates structured programming in C

## 🎮 Game Features

- **Classic Pong Gameplay**: Player vs AI in console environment
- **Player vs AI**: Play against a computer opponent with intelligent behavior
- **Score Tracking**: First player to reach 5 points wins
- **Real-time Controls**: Smooth paddle movement with W/S keys
- **Collision Physics**: Realistic ball bouncing off paddles and walls
- **Cross-Platform Graphics**: ANSI escape sequences for universal terminal control
- **Structured Code**: Clean function organization and data structures

## 🕹️ How to Play

### Controls

- **W** - Move your paddle up
- **S** - Move your paddle down  
- **ESC** - Quit the game (Windows) or Ctrl+C (Unix systems)

### Gameplay

1. Your paddle is on the left side of the screen (position x=2)
2. The AI paddle is on the right side (position x=FIELD_WIDTH-3)
3. Use W and S keys to move your paddle up and down
4. Try to hit the ball back to the AI's side
5. You score a point when the ball goes past the AI's paddle
6. The AI scores when the ball goes past your paddle
7. First player to reach 5 points wins!

## 🔧 Technical Implementation

### Game Architecture

#### Core Data Structures
```c
typedef struct {
    int x, y;       // Position
    int dx, dy;     // Velocity
} Ball;

typedef struct {
    int x, y;       // Position
    int height;     // Paddle size
} Paddle;

typedef struct {
    int player_score;
    int ai_score;
    int game_running;
} GameState;
```

#### Game Constants
- **Field Size**: 80x25 characters
- **Paddle Height**: 5 characters
- **Winning Score**: 5 points
- **Game Speed**: 100ms update cycle

#### Key Functions
- `initialize_game()` - Set up game objects and initial state
- `draw_game()` - Render the complete game field
- `update_ball()` - Handle ball movement and wall collisions
- `update_player_paddle()` - Process player input
- `update_ai_paddle()` - AI logic for computer opponent
- `check_collisions()` - Detect ball-paddle collisions
- `reset_ball()` - Reset ball position after scoring

### AI System
```c
void update_ai_paddle(void) {
    int paddle_center = ai_paddle.y + ai_paddle.height / 2;
    
    // Move towards ball with realistic difficulty
    if (ball.y < paddle_center && ai_paddle.y > 1) {
        ai_paddle.y--;
    }
    else if (ball.y > paddle_center &&
             ai_paddle.y + ai_paddle.height < FIELD_HEIGHT - 2) {
        ai_paddle.y++;
    }
}
```

### Cross-Platform Abstraction Layer

The game uses conditional compilation for platform-specific implementations:

```c
#ifdef _WIN32
    #define PLATFORM_WINDOWS
    #include <conio.h>
    #include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
    #define PLATFORM_UNIX
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #include <sys/select.h>
#endif
```

### Cross-Platform Functions

1. **`cross_platform_sleep(int milliseconds)`**
   - Windows: `Sleep(milliseconds)`
   - Unix: `usleep(milliseconds * 1000)`

2. **`cross_platform_kbhit(void)`**
   - Windows: `_kbhit()`
   - Unix: Non-blocking `fcntl()` implementation

3. **`cross_platform_getch(void)`**
   - Windows: `_getch()`
   - Unix: `tcgetattr()/tcsetattr()` terminal manipulation

4. **`setup_terminal(void)` / `restore_terminal(void)`**
   - Unix: Configure and restore terminal raw mode
   - Windows: No action needed

5. **Universal Terminal Control**
   - `clear_screen()`: ANSI escape sequence `\033[2J\033[H`
   - `gotoxy(x, y)`: ANSI escape sequence `\033[y;xH`

## 🔧 Compilation

### Windows (with GCC/MinGW)
```bash
gcc -o pong.exe main.c
```

### Linux
```bash
gcc -o pong main.c
```

### macOS
```bash
clang -o pong main.c
# or
gcc -o pong main.c
```

### Visual Studio (Windows)
```bash
cl main.c /Fe:pong.exe
```

## 🚀 Running the Game

### Windows
```bash
./pong.exe
```

### Linux/macOS
```bash
./pong
```

## 📋 Requirements

### Universal Requirements
- C compiler (GCC, Clang, or MSVC)
- Terminal/Console with ANSI escape sequence support
- Minimum terminal size: 80x25 characters

### Platform-Specific Requirements

#### Windows
- **MinGW/GCC**: Recommended for cross-platform development
- **Visual Studio**: MSVC compiler with Windows SDK
- **Windows Console**: Built-in support for ANSI sequences (Windows 10+)

#### Linux
- **GCC or Clang**: Standard system compiler
- **Terminal**: Any POSIX-compliant terminal
- **Libraries**: Standard C library with POSIX extensions

#### macOS
- **Xcode Command Line Tools**: `xcode-select --install`
- **Clang or GCC**: Available through Xcode or Homebrew
- **Terminal**: Built-in Terminal.app or compatible terminal

## 🎯 Learning Objectives

This implementation demonstrates key C programming concepts:

### Structured Programming
- **Function-based organization**: Clear separation of concerns
- **Data structures**: Use of `typedef struct` for game objects
- **Global state management**: Controlled use of global variables
- **Modular design**: Reusable cross-platform functions

### Systems Programming
- **Platform detection**: Conditional compilation techniques
- **Terminal control**: Low-level console manipulation
- **Non-blocking I/O**: Real-time input handling
- **Process control**: Signal handling and cleanup

### Game Programming Fundamentals
- **Game loop**: Initialize, update, render, repeat
- **State management**: Game objects and status tracking
- **Collision detection**: Simple AABB collision algorithms
- **AI programming**: Basic computer opponent logic

## 🌟 Key Benefits

1. **Educational Value**: Perfect introduction to C programming and cross-platform development
2. **No Dependencies**: Runs anywhere with a C compiler
3. **Portable**: Single source code for all major platforms
4. **Professional Practices**: Demonstrates clean code organization
5. **Foundation**: Base for more advanced game implementations

## 🚨 Known Limitations

1. **Fixed Terminal Size**: Assumes 80x25 character display
2. **ASCII Graphics**: Basic character-based rendering
3. **Keyboard Layout**: Optimized for QWERTY layouts
4. **Single Player**: AI opponent only
5. **No Sound**: Console-based audio limitations

## 📁 Project Context

This is part of the structured programming Pong game series:
- **01-simple**: This console-based implementation
- **02-simple-visual-studio**: Enhanced Visual Studio project version
- **03-simple-visual-studio-sdl**: Advanced SDL3 graphics version

Each version builds upon the previous, demonstrating programming evolution from console to graphics.

## 📜 License

This is an educational project demonstrating cross-platform C programming and structured programming techniques.

---

**A foundational example of cross-platform game programming in pure C!** 🎮

*Perfect for learning C programming, terminal control, and cross-platform development fundamentals.*
