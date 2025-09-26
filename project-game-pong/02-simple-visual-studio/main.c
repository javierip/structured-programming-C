// Cross-platform Pong Game in C
// Compatible with Windows, Linux, and macOS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Platform detection
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define PLATFORM_WINDOWS
#elif defined(__linux__) || defined(__APPLE__)
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #include <sys/select.h>
    #define PLATFORM_UNIX
#endif

// Game constants
#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define PADDLE_HEIGHT 5
#define WINNING_SCORE 5

// Game structures
typedef struct
{
    int x, y;
    int dx, dy;
} Ball;

typedef struct
{
    int x, y;
    int height;
} Paddle;

typedef struct
{
    int player_score;
    int ai_score;
    int game_running;
} GameState;

// Global game objects
Ball ball;
Paddle player_paddle;
Paddle ai_paddle;
GameState game_state;

// Cross-platform function declarations
void cross_platform_sleep(int milliseconds);
int cross_platform_kbhit(void);
int cross_platform_getch(void);
void setup_terminal(void);
void restore_terminal(void);

#ifdef PLATFORM_UNIX
static struct termios old_terminal_settings;
static int terminal_setup = 0;
#endif

// Function declarations
void initialize_game(void);
void clear_screen(void);
void draw_game(void);
void update_ball(void);
void update_player_paddle(void);
void update_ai_paddle(void);
void check_collisions(void);
void reset_ball(void);
void gotoxy(int x, int y);

// Initialize game objects and state
void initialize_game(void)
{
    // Initialize ball in center
    ball.x = FIELD_WIDTH / 2;
    ball.y = FIELD_HEIGHT / 2;
    ball.dx = 1;
    ball.dy = 1;

    // Initialize paddles
    player_paddle.x = 2;
    player_paddle.y = FIELD_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    player_paddle.height = PADDLE_HEIGHT;

    ai_paddle.x = FIELD_WIDTH - 3;
    ai_paddle.y = FIELD_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    ai_paddle.height = PADDLE_HEIGHT;

    // Initialize game state
    game_state.player_score = 0;
    game_state.ai_score = 0;
    game_state.game_running = 1;

    // Seed random number generator
    srand(time(NULL));
}

// Move cursor to specific position
// Cross-platform terminal setup
void setup_terminal(void) {
#ifdef PLATFORM_UNIX
    if (!terminal_setup) {
        struct termios new_settings;
        tcgetattr(0, &old_terminal_settings);
        new_settings = old_terminal_settings;
        new_settings.c_lflag &= ~(ICANON | ECHO);
        new_settings.c_cc[VMIN] = 0;
        new_settings.c_cc[VTIME] = 0;
        tcsetattr(0, TCSANOW, &new_settings);
        terminal_setup = 1;
    }
#endif
}

// Cross-platform terminal restoration
void restore_terminal(void) {
#ifdef PLATFORM_UNIX
    if (terminal_setup) {
        tcsetattr(0, TCSANOW, &old_terminal_settings);
        terminal_setup = 0;
    }
#endif
}

// Cross-platform sleep function
void cross_platform_sleep(int milliseconds) {
#ifdef PLATFORM_WINDOWS
    Sleep(milliseconds);
#elif defined(PLATFORM_UNIX)
    usleep(milliseconds * 1000);
#endif
}

// Cross-platform keyboard hit detection
int cross_platform_kbhit(void) {
#ifdef PLATFORM_WINDOWS
    return _kbhit();
#elif defined(PLATFORM_UNIX)
    int ch;
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, flags);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
#endif
}

// Cross-platform get character function
int cross_platform_getch(void) {
#ifdef PLATFORM_WINDOWS
    return _getch();
#elif defined(PLATFORM_UNIX)
    int ch;
    struct termios old_settings, new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
#endif
}

// Cross-platform cursor positioning using ANSI escape sequences
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

// Clear screen using ANSI escape sequence
void clear_screen(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}

// Draw the entire game
void draw_game(void)
{
    int i, j;

    gotoxy(0, 0);

    // Draw top border
    for (i = 0; i < FIELD_WIDTH; i++)
    {
        printf("#");
    }
    printf("\n");

    // Draw game field
    for (i = 1; i < FIELD_HEIGHT - 1; i++)
    {
        for (j = 0; j < FIELD_WIDTH; j++)
        {
            if (j == 0 || j == FIELD_WIDTH - 1)
            {
                printf("#"); // Side borders
            }
            else if (j == FIELD_WIDTH / 2)
            {
                printf("|"); // Center line
            }
            else if (j == ball.x && i == ball.y)
            {
                printf("O"); // Ball
            }
            else if (j == player_paddle.x &&
                     i >= player_paddle.y &&
                     i < player_paddle.y + player_paddle.height)
            {
                printf("|"); // Player paddle
            }
            else if (j == ai_paddle.x &&
                     i >= ai_paddle.y &&
                     i < ai_paddle.y + ai_paddle.height)
            {
                printf("|"); // AI paddle
            }
            else
            {
                printf(" "); // Empty space
            }
        }
        printf("\n");
    }

    // Draw bottom border
    for (i = 0; i < FIELD_WIDTH; i++)
    {
        printf("#");
    }
    printf("\n");

    // Draw score
    printf("Player: %d    AI: %d    Press ESC to quit\n",
           game_state.player_score, game_state.ai_score);
    printf("Use W/S keys to move your paddle\n");
}

// Update ball position and handle wall bouncing
void update_ball(void)
{
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Bounce off top and bottom walls
    if (ball.y <= 1 || ball.y >= FIELD_HEIGHT - 2)
    {
        ball.dy = -ball.dy;
    }

    // Check for scoring
    if (ball.x <= 0)
    {
        game_state.ai_score++;
        reset_ball();
    }
    else if (ball.x >= FIELD_WIDTH - 1)
    {
        game_state.player_score++;
        reset_ball();
    }
}

// Reset ball to center with random direction
void reset_ball(void)
{
    ball.x = FIELD_WIDTH / 2;
    ball.y = FIELD_HEIGHT / 2;
    ball.dx = (rand() % 2 == 0) ? 1 : -1;
    ball.dy = (rand() % 2 == 0) ? 1 : -1;

    // Check for game end
    if (game_state.player_score >= WINNING_SCORE ||
        game_state.ai_score >= WINNING_SCORE)
    {
        game_state.game_running = 0;
    }
}

// Handle player paddle movement
void update_player_paddle(void)
{
    if (cross_platform_kbhit())
    {
        char key = cross_platform_getch();
        switch (key)
        {
        case 'w':
        case 'W':
            if (player_paddle.y > 1)
            {
                player_paddle.y--;
            }
            break;
        case 's':
        case 'S':
            if (player_paddle.y + player_paddle.height < FIELD_HEIGHT - 2)
            {
                player_paddle.y++;
            }
            break;
        case 27: // ESC key
            game_state.game_running = 0;
            break;
        }
    }
}

// Simple AI for computer paddle
void update_ai_paddle(void)
{
    int paddle_center = ai_paddle.y + ai_paddle.height / 2;

    // Move towards ball with some delay for difficulty
    if (ball.y < paddle_center && ai_paddle.y > 1)
    {
        ai_paddle.y--;
    }
    else if (ball.y > paddle_center &&
             ai_paddle.y + ai_paddle.height < FIELD_HEIGHT - 2)
    {
        ai_paddle.y++;
    }
}

// Check collisions between ball and paddles
void check_collisions(void)
{
    // Check collision with player paddle
    if (ball.x == player_paddle.x + 1 &&
        ball.y >= player_paddle.y &&
        ball.y < player_paddle.y + player_paddle.height)
    {
        ball.dx = -ball.dx;

        // Add some angle based on where ball hits paddle
        int hit_pos = ball.y - player_paddle.y;
        if (hit_pos == 0 || hit_pos == player_paddle.height - 1)
        {
            ball.dy = -ball.dy;
        }
    }

    // Check collision with AI paddle
    if (ball.x == ai_paddle.x - 1 &&
        ball.y >= ai_paddle.y &&
        ball.y < ai_paddle.y + ai_paddle.height)
    {
        ball.dx = -ball.dx;

        // Add some angle based on where ball hits paddle
        int hit_pos = ball.y - ai_paddle.y;
        if (hit_pos == 0 || hit_pos == player_paddle.height - 1)
        {
            ball.dy = -ball.dy;
        }
    }
}

// Main game function
int main(void)
{
    // Setup terminal for cross-platform compatibility
    setup_terminal();
    
    printf("Welcome to Pong!\n");
    printf("Use W and S keys to control your paddle.\n");
    printf("First to %d points wins!\n", WINNING_SCORE);
    printf("Press any key to start...\n");
    cross_platform_getch();

    initialize_game();

    // Main game loop
    while (game_state.game_running)
    {
        clear_screen();
        draw_game();

        update_player_paddle();
        update_ai_paddle();
        update_ball();
        check_collisions();

        // Game speed control
        cross_platform_sleep(100);
    }

    // Game over screen
    clear_screen();
    printf("\n\n");
    printf("    GAME OVER!\n\n");
    if (game_state.player_score >= WINNING_SCORE)
    {
        printf("    You Win! Final Score: %d - %d\n",
               game_state.player_score, game_state.ai_score);
    }
    else
    {
        printf("    AI Wins! Final Score: %d - %d\n",
               game_state.ai_score, game_state.player_score);
    }
    printf("\n    Thanks for playing!\n");
    printf("    Press any key to exit...\n");
    cross_platform_getch();

    // Restore terminal settings
    restore_terminal();

    return 0;
}
