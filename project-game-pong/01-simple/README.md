# Cross-Platform Pong Game

A classic Pong game implemented in C programming language using only standard libraries, now **fully cross-platform** and compatible with Windows, Linux, and macOS.

## 🌍 Cross-Platform Features

This version has been completely rewritten to remove all operating system dependencies:

- **Windows Support**: Uses Windows.h for native console functions when available
- **Linux Support**: Uses POSIX terminal control and ANSI escape sequences
- **macOS Support**: Compatible with Unix-like systems using standard terminal libraries
- **Pure C Implementation**: No external dependencies beyond standard C library

## 🎮 Game Features

- **Classic Pong Gameplay**: Two paddles, one ball, endless fun!
- **Player vs AI**: Play against a simple computer opponent
- **Score Tracking**: First player to reach 5 points wins
- **Real-time Controls**: Smooth paddle movement with W/S keys
- **Collision Physics**: Realistic ball bouncing off paddles and walls
- **Cross-Platform Graphics**: ANSI escape sequences for universal terminal control

## 🕹️ How to Play

### Controls

- **W** - Move your paddle up
- **S** - Move your paddle down  
- **ESC** - Quit the game (Windows) or Ctrl+C (Unix systems)

### Gameplay

1. Your paddle is on the left side of the screen
2. The AI paddle is on the right side
3. Use W and S keys to move your paddle up and down
4. Try to hit the ball back to the AI's side
5. You score a point when the ball goes past the AI's paddle
6. The AI scores when the ball goes past your paddle
7. First player to reach 5 points wins!

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

## 🏗️ Technical Architecture

### Cross-Platform Abstraction Layer

The game uses conditional compilation to provide platform-specific implementations:

```c
#ifdef _WIN32
    // Windows-specific code using conio.h and windows.h
#elif defined(__linux__) || defined(__APPLE__)
    // Unix-like systems using POSIX terminal control
#endif
```

### Key Cross-Platform Functions

1. **`cross_platform_sleep()`** - Sleep/delay function
   - Windows: `Sleep(milliseconds)`
   - Unix: `usleep(milliseconds * 1000)`

2. **`cross_platform_kbhit()`** - Non-blocking keyboard input detection
   - Windows: `_kbhit()`
   - Unix: `fcntl()` with `O_NONBLOCK`

3. **`cross_platform_getch()`** - Character input without Enter
   - Windows: `_getch()`
   - Unix: `tcgetattr()/tcsetattr()` terminal manipulation

4. **`clear_screen()`** - Screen clearing
   - All platforms: ANSI escape sequence `\033[2J\033[H`

5. **`gotoxy()`** - Cursor positioning
   - All platforms: ANSI escape sequence `\033[y;xH`

### Terminal Management (Unix Systems)

- **`setup_terminal()`** - Configure terminal for raw input mode
- **`restore_terminal()`** - Restore original terminal settings
- Automatic cleanup on program exit

## 📋 Requirements

### Universal Requirements

- C compiler (GCC, Clang, or MSVC)
- Terminal/Console with ANSI escape sequence support

### Platform-Specific Requirements

#### Windows

- **MinGW/GCC**: Recommended for cross-platform development
- **Visual Studio**: MSVC compiler with Windows SDK
- **Windows Console**: Built-in support for ANSI sequences (Windows 10+)

#### Linux

- **GCC or Clang**: Standard system compiler
- **Terminal**: Any POSIX-compliant terminal (bash, zsh, etc.)
- **Libraries**: Standard C library with POSIX extensions

#### macOS

- **Xcode Command Line Tools**: `xcode-select --install`
- **Clang or GCC**: Available through Xcode or Homebrew
- **Terminal**: Built-in Terminal.app or any compatible terminal

## 🔍 Code Structure

### Header Files by Platform

```c
// Universal
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Windows-specific
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#endif

// Unix-specific
#ifdef __linux__ || __APPLE__
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
#endif
```

### Platform Detection

- `PLATFORM_WINDOWS` - Windows systems
- `PLATFORM_UNIX` - Linux and macOS systems

### Game Components

- **Ball Structure**: Position and velocity tracking
- **Paddle Structure**: Position and dimensions
- **Game State**: Score and status management
- **Physics Engine**: Movement and collision detection
- **AI Logic**: Simple computer opponent
- **Cross-Platform Input**: Universal keyboard handling
- **Cross-Platform Output**: ANSI-based rendering

## 🧪 Testing

The game has been tested on:

- ✅ Windows 10/11 (MinGW-GCC, Visual Studio)
- ✅ Linux (Ubuntu, Debian, CentOS)
- ✅ macOS (Monterey, Ventura)

## 🎯 Technical Highlights

### C Programming Concepts Demonstrated

- **Conditional Compilation**: Platform-specific code paths
- **Structure Programming**: Clean data organization
- **Function Abstraction**: Cross-platform API design
- **Terminal Control**: Low-level console manipulation
- **Non-blocking I/O**: Real-time input handling
- **ANSI Escape Sequences**: Universal terminal control

### Performance Features

- **Efficient Rendering**: Minimal screen updates
- **Responsive Controls**: Non-blocking input system
- **Optimized Physics**: Simple collision detection
- **Memory Efficient**: Stack-based data structures

## 🌟 Advantages of This Implementation

1. **True Portability**: Single source code for all platforms
2. **No External Dependencies**: Pure standard C libraries
3. **Educational Value**: Demonstrates cross-platform programming
4. **Terminal Compatibility**: Works in any modern terminal
5. **Maintainable Code**: Clean separation of platform concerns

## 🚨 Known Limitations

1. **Terminal Size**: Assumes 80x25 character terminal
2. **ANSI Support**: Requires ANSI escape sequence support
3. **Keyboard Layout**: Optimized for QWERTY layouts
4. **Color Support**: Basic monochrome display only

## 📜 License

This is an educational project demonstrating cross-platform C programming techniques.

---

**Enjoy this classic arcade game that runs everywhere C does!** 🎮
