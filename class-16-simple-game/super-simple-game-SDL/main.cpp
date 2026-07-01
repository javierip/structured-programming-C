/* Program: Simple Pong (SDL3 version)
 * Description: The graphical version of the console "Simple Pong" example.
 *   It keeps the SAME structure and ideas as the console game so the two can
 *   be compared side by side:
 *     - while loop (main game loop)                    (week 9)
 *     - for loops (drawing the playing field)          (week 10)
 *     - functions with prototypes                      (week 11)
 *     - recursion (start countdown)                    (week 12)
 *     - switch and integration of concepts             (week 13)
 *
 *   The game logic still works on a simple grid of WIDTH x HEIGHT cells and
 *   uses only plain global variables (no structures, no pointers). SDL is
 *   used to draw each cell as a colored rectangle instead of printing a
 *   character. The only pointers are the SDL window/renderer handles and the
 *   address of the event we read; the only structure is SDL_FRect, which SDL
 *   needs to draw a rectangle.
 *
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu.ar
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time        */

 /* Field and game settings (same grid as the console version). */
#define WIDTH 40
#define HEIGHT 20
#define PADDLE_HEIGHT 4
#define WINNING_SCORE 5
#define CELL_SIZE 20 /* pixels per grid cell */

/* Window size derived from the grid. */
#define WINDOW_WIDTH  (WIDTH * CELL_SIZE)
#define WINDOW_HEIGHT (HEIGHT * CELL_SIZE)

/* SDL handles (the only pointers we cannot avoid). */
static SDL_Window   *window   = NULL;
static SDL_Renderer *renderer = NULL;

/* Global game state (no structures used, just like the console version). */
int ball_x, ball_y;      /* ball position            */
int ball_dx, ball_dy;    /* ball direction (-1 / +1) */
int left_paddle_y;       /* player paddle (top row)  */
int right_paddle_y;      /* computer paddle (top row)*/
int player_score;
int computer_score;
int game_running;

/* Function prototypes (week 11). */
void setup_game(void);
void countdown(int n);
void draw_cell(int col, int row);
void draw_big_text(const char *msg, float scale);
void draw_field(void);
void handle_input(void);
void move_ball(void);
void move_computer(void);
void check_paddles(void);
void reset_ball(void);
void game_over_screen(void);

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return 1;
	}

	if (!SDL_CreateWindowAndRenderer("Simple Pong (SDL)",
			WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
	{
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
		return 1;
	}

	countdown(3);
	setup_game();

	/* Main game loop (week 9). Same order and timing as the console version. */
	while (game_running)
	{
		draw_field();
		handle_input();
		move_ball();
		move_computer();
		check_paddles();
		SDL_Delay(120);
	}

	game_over_screen();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

/* Place the ball and paddles at their starting positions. */
void setup_game(void)
{
	left_paddle_y = HEIGHT / 2 - PADDLE_HEIGHT / 2;
	right_paddle_y = HEIGHT / 2 - PADDLE_HEIGHT / 2;
	player_score = 0;
	computer_score = 0;
	game_running = 1;
	reset_ball();
}

/* Recursive countdown before the game starts (week 12). */
void countdown(int n)
{
	char buf[16];

	/* Clear to black and choose white for the text. */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	if (n == 0)
	{
		draw_big_text("GO!", 6.0f);
		SDL_RenderPresent(renderer);
		SDL_PumpEvents(); /* keep the window responsive */
		SDL_Delay(500);
		return;
	}

	SDL_snprintf(buf, sizeof(buf), "%d", n);
	draw_big_text(buf, 6.0f);
	SDL_RenderPresent(renderer);
	SDL_PumpEvents();
	SDL_Delay(700);

	countdown(n - 1);
}

/* Fill one grid cell with the current draw color. */
void draw_cell(int col, int row)
{
	SDL_FRect rect;
	rect.x = (float)(col * CELL_SIZE);
	rect.y = (float)(row * CELL_SIZE);
	rect.w = (float)CELL_SIZE;
	rect.h = (float)CELL_SIZE;
	SDL_RenderFillRect(renderer, &rect);
}

/* Draw a line of text centered on the screen, enlarged by 'scale'. */
void draw_big_text(const char *msg, float scale)
{
	float text_w, x, y;

	SDL_SetRenderScale(renderer, scale, scale);

	/* Each debug-text character is 8 pixels wide (in unscaled units). */
	text_w = (float)SDL_strlen(msg) * 8.0f;
	x = (WINDOW_WIDTH / scale - text_w) / 2.0f;
	y = (WINDOW_HEIGHT / scale) / 2.0f - 4.0f;
	SDL_RenderDebugText(renderer, x, y, msg);

	SDL_SetRenderScale(renderer, 1.0f, 1.0f);
}

/* Draw the border, paddles and ball using for loops (week 10). */
void draw_field(void)
{
	int row, col;
	char score_text[64];

	/* Clear the screen to black. */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	/* Walk every cell of the grid, exactly like the console draw_field. */
	for (row = 0; row < HEIGHT; row++)
	{
		for (col = 0; col < WIDTH; col++)
		{
			if (row == 0 || row == HEIGHT - 1 ||
				col == 0 || col == WIDTH - 1)
			{
				/* border walls (gray) */
				SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
				draw_cell(col, row);
			}
			else if (col == 2 &&
				row >= left_paddle_y &&
				row < left_paddle_y + PADDLE_HEIGHT)
			{
				/* player paddle (green) */
				SDL_SetRenderDrawColor(renderer, 80, 220, 120, 255);
				draw_cell(col, row);
			}
			else if (col == WIDTH - 3 &&
				row >= right_paddle_y &&
				row < right_paddle_y + PADDLE_HEIGHT)
			{
				/* computer paddle (red) */
				SDL_SetRenderDrawColor(renderer, 220, 90, 90, 255);
				draw_cell(col, row);
			}
			else if (col == ball_x && row == ball_y)
			{
				/* ball (yellow) */
				SDL_SetRenderDrawColor(renderer, 240, 210, 60, 255);
				draw_cell(col, row);
			}
		}
	}

	/* Scores and controls, drawn as white text over the field. */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_snprintf(score_text, sizeof(score_text),
		"Player: %d   Computer: %d", player_score, computer_score);
	SDL_RenderDebugText(renderer, CELL_SIZE + 4, CELL_SIZE / 2.0f, score_text);
	SDL_RenderDebugText(renderer, CELL_SIZE + 4,
		WINDOW_HEIGHT - CELL_SIZE, "W/S to move, ESC to quit");

	SDL_RenderPresent(renderer);
}

/* Read the keyboard and move the player paddle (weeks 9 and 13). */
void handle_input(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			game_running = 0;
		}
		else if (event.type == SDL_EVENT_KEY_DOWN)
		{
			switch (event.key.scancode)
			{
			case SDL_SCANCODE_W:
				if (left_paddle_y > 1)
					left_paddle_y--;
				break;

			case SDL_SCANCODE_S:
				if (left_paddle_y + PADDLE_HEIGHT < HEIGHT - 1)
					left_paddle_y++;
				break;

			case SDL_SCANCODE_ESCAPE:
				game_running = 0;
				break;

			default:
				break;
			}
		}
	}
}

/* Advance the ball and bounce it off the top and bottom walls. */
void move_ball(void)
{
	ball_x = ball_x + ball_dx;
	ball_y = ball_y + ball_dy;

	if (ball_y <= 1)
		ball_dy = 1;
	if (ball_y >= HEIGHT - 2)
		ball_dy = -1;

	if (ball_x <= 0)
	{
		computer_score++;
		reset_ball();
	}
	else if (ball_x >= WIDTH - 1)
	{
		player_score++;
		reset_ball();
	}
}

/* Simple computer opponent: follow the ball. */
void move_computer(void)
{
	int center = right_paddle_y + PADDLE_HEIGHT / 2;

	if (ball_y < center && right_paddle_y > 1)
		right_paddle_y--;
	else if (ball_y > center &&
		right_paddle_y + PADDLE_HEIGHT < HEIGHT - 1)
		right_paddle_y++;
}

/* Bounce the ball when it touches a paddle. */
void check_paddles(void)
{
	if (ball_x == 3 &&
		ball_y >= left_paddle_y &&
		ball_y < left_paddle_y + PADDLE_HEIGHT)
		ball_dx = 1;

	if (ball_x == WIDTH - 4 &&
		ball_y >= right_paddle_y &&
		ball_y < right_paddle_y + PADDLE_HEIGHT)
		ball_dx = -1;
}

/* Send the ball back to the center with a random direction. */
void reset_ball(void)
{
	ball_x = WIDTH / 2;
	ball_y = HEIGHT / 2;

	if (rand() % 2 == 0)
		ball_dx = 1;
	else
		ball_dx = -1;

	if (rand() % 2 == 0)
		ball_dy = 1;
	else
		ball_dy = -1;

	if (player_score >= WINNING_SCORE || computer_score >= WINNING_SCORE)
		game_running = 0;
}

/* Show the final result and wait for a key press or the window to close. */
void game_over_screen(void)
{
	SDL_Event event;
	int waiting = 1;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	if (player_score > computer_score)
		draw_big_text("YOU WIN!", 4.0f);
	else
		draw_big_text("COMPUTER WINS", 4.0f);

	SDL_RenderPresent(renderer);

	/* Small wait loop so the window stays responsive until the user leaves. */
	while (waiting)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT ||
				event.type == SDL_EVENT_KEY_DOWN)
				waiting = 0;
		}
		SDL_Delay(16);
	}
}
