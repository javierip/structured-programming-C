/* Program: Simple Pong (concept integration, weeks 9 to 13)
 * Description: A minimal console Pong game that combines:
 *   - while loop (main game loop and input polling)  (week 9)
 *   - for loops (drawing the playing field)          (week 10)
 *   - functions with prototypes                      (week 11)
 *   - recursion (start countdown)                    (week 12)
 *   - switch and integration of concepts             (week 13)
 *
 * No structures and no pointers are used: the game state is kept in
 * simple global variables. Windows console version.
 *
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   /* _kbhit, _getch */
#include <windows.h> /* Sleep          */
#include <time.h>

 /* Field and game settings. */
#define WIDTH 40
#define HEIGHT 20
#define PADDLE_HEIGHT 4
#define WINNING_SCORE 5

/* Global game state (no structures used). */
int ball_x, ball_y;      /* ball position           */
int ball_dx, ball_dy;    /* ball direction (-1 / +1) */
int left_paddle_y;       /* player paddle (top row)  */
int right_paddle_y;      /* computer paddle (top row)*/
int player_score;
int computer_score;
int game_running;

/* Function prototypes (week 11). */
void setup_game(void);
void countdown(int n);
void clear_screen(void);
void draw_field(void);
void handle_input(void);
void move_ball(void);
void move_computer(void);
void check_paddles(void);
void reset_ball(void);

int main(void)
{
	srand((unsigned)time(NULL));

	printf("=== SIMPLE PONG ===\n");
	printf("First to %d points wins.\n", WINNING_SCORE);
	printf("Move your paddle with W (up) and S (down). Press ESC to quit.\n\n");
	printf("Get ready...\n");
	countdown(3);

	setup_game();

	/* Main game loop (week 9). */
	while (game_running)
	{
		draw_field();
		handle_input();
		move_ball();
		move_computer();
		check_paddles();
		Sleep(120);
	}

	clear_screen();
	printf("\n=== GAME OVER ===\n");
	if (player_score > computer_score)
		printf("You win! %d - %d\n", player_score, computer_score);
	else
		printf("Computer wins! %d - %d\n", computer_score, player_score);
	printf("Thanks for playing.\n");

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
	if (n == 0)
	{
		printf("GO!\n");
		Sleep(500);
		return;
	}
	printf("%d...\n", n);
	Sleep(700);
	countdown(n - 1);
}

/* Clear the console screen. */
void clear_screen(void)
{
	system("cls");
}

/* Draw the border, paddles and ball using for loops (week 10). */
void draw_field(void)
{
	int row, col;

	clear_screen();

	/* Top border. */
	for (col = 0; col < WIDTH; col++)
		printf("#");
	printf("\n");

	/* Playing field, row by row. */
	for (row = 1; row < HEIGHT - 1; row++)
	{
		for (col = 0; col < WIDTH; col++)
		{
			if (col == 0 || col == WIDTH - 1)
				printf("#"); /* side walls */
			else if (col == 2 &&
				row >= left_paddle_y &&
				row < left_paddle_y + PADDLE_HEIGHT)
				printf("|"); /* player paddle */
			else if (col == WIDTH - 3 &&
				row >= right_paddle_y &&
				row < right_paddle_y + PADDLE_HEIGHT)
				printf("|"); /* computer paddle */
			else if (col == ball_x && row == ball_y)
				printf("O"); /* ball */
			else
				printf(" ");
		}
		printf("\n");
	}

	/* Bottom border. */
	for (col = 0; col < WIDTH; col++)
		printf("#");
	printf("\n");

	printf("Player: %d   Computer: %d   (W/S to move, ESC to quit)\n",
		player_score, computer_score);
}

/* Read the keyboard and move the player paddle (weeks 9 and 13). */
void handle_input(void)
{
	char key;

	while (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
			if (left_paddle_y > 1)
				left_paddle_y--;
			break;

		case 's':
		case 'S':
			if (left_paddle_y + PADDLE_HEIGHT < HEIGHT - 1)
				left_paddle_y++;
			break;

		case 27: /* ESC */
			game_running = 0;
			break;
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
