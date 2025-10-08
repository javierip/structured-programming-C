/*
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

// Game constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PADDLE_WIDTH = 15;
const int PADDLE_HEIGHT = 80;
const int BALL_SIZE = 15;
const float PADDLE_SPEED = 400.0f;
const float BALL_SPEED = 300.0f;

// Game objects
struct GameObject {
	float x, y;
	float w, h;
	float vx, vy;  // velocity
};

static GameObject leftPaddle;
static GameObject rightPaddle;
static GameObject ball;

// Game state
static int leftScore = 0;
static int rightScore = 0;
static Uint64 lastTime = 0;

// Input state
static bool upPressed = false;
static bool downPressed = false;
static bool wPressed = false;
static bool sPressed = false;

void ResetBall() {
	ball.x = WINDOW_WIDTH / 2.0f - BALL_SIZE / 2.0f;
	ball.y = WINDOW_HEIGHT / 2.0f - BALL_SIZE / 2.0f;

	// Random direction
	ball.vx = (SDL_GetTicks() % 2 == 0) ? BALL_SPEED : -BALL_SPEED;
	ball.vy = (SDL_GetTicks() % 200 - 100) * 2.0f;  // Random Y velocity
}

bool CheckCollision(const GameObject& a, const GameObject& b) {
	return (a.x < b.x + b.w &&
		a.x + a.w > b.x &&
		a.y < b.y + b.h &&
		a.y + a.h > b.y);
}

void InitializeGame() {
	// Initialize paddles
	leftPaddle.x = 50;
	leftPaddle.y = WINDOW_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f;
	leftPaddle.w = PADDLE_WIDTH;
	leftPaddle.h = PADDLE_HEIGHT;
	leftPaddle.vx = 0;
	leftPaddle.vy = 0;

	rightPaddle.x = WINDOW_WIDTH - 50 - PADDLE_WIDTH;
	rightPaddle.y = WINDOW_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f;
	rightPaddle.w = PADDLE_WIDTH;
	rightPaddle.h = PADDLE_HEIGHT;
	rightPaddle.vx = 0;
	rightPaddle.vy = 0;

	// Initialize ball
	ball.w = BALL_SIZE;
	ball.h = BALL_SIZE;
	ResetBall();
}

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	/* Create the window */
	if (!SDL_CreateWindowAndRenderer("Simple Pong Game", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	InitializeGame();
	lastTime = SDL_GetTicks();

	return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
	}

	if (event->type == SDL_EVENT_KEY_DOWN) {
		switch (event->key.scancode) {
		case SDL_SCANCODE_UP:
			upPressed = true;
			break;
		case SDL_SCANCODE_DOWN:
			downPressed = true;
			break;
		case SDL_SCANCODE_W:
			wPressed = true;
			break;
		case SDL_SCANCODE_S:
			sPressed = true;
			break;
		case SDL_SCANCODE_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDL_SCANCODE_R:
			// Reset game
			leftScore = 0;
			rightScore = 0;
			ResetBall();
			break;
		}
	}

	if (event->type == SDL_EVENT_KEY_UP) {
		switch (event->key.scancode) {
		case SDL_SCANCODE_UP:
			upPressed = false;
			break;
		case SDL_SCANCODE_DOWN:
			downPressed = false;
			break;
		case SDL_SCANCODE_W:
			wPressed = false;
			break;
		case SDL_SCANCODE_S:
			sPressed = false;
			break;
		}
	}

	return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
	Uint64 currentTime = SDL_GetTicks();
	float deltaTime = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;

	// Update paddle movement
	leftPaddle.vy = 0;
	if (wPressed) leftPaddle.vy = -PADDLE_SPEED;
	if (sPressed) leftPaddle.vy = PADDLE_SPEED;

	rightPaddle.vy = 0;
	if (upPressed) rightPaddle.vy = -PADDLE_SPEED;
	if (downPressed) rightPaddle.vy = PADDLE_SPEED;

	// Update positions
	leftPaddle.y += leftPaddle.vy * deltaTime;
	rightPaddle.y += rightPaddle.vy * deltaTime;
	ball.x += ball.vx * deltaTime;
	ball.y += ball.vy * deltaTime;

	// Keep paddles on screen
	if (leftPaddle.y < 0) leftPaddle.y = 0;
	if (leftPaddle.y + leftPaddle.h > WINDOW_HEIGHT) leftPaddle.y = WINDOW_HEIGHT - leftPaddle.h;
	if (rightPaddle.y < 0) rightPaddle.y = 0;
	if (rightPaddle.y + rightPaddle.h > WINDOW_HEIGHT) rightPaddle.y = WINDOW_HEIGHT - rightPaddle.h;

	// Ball collision with top/bottom walls
	if (ball.y <= 0 || ball.y + ball.h >= WINDOW_HEIGHT) {
		ball.vy = -ball.vy;
		ball.y = (ball.y <= 0) ? 0 : WINDOW_HEIGHT - ball.h;
	}

	// Ball collision with paddles
	if (CheckCollision(ball, leftPaddle)) {
		ball.vx = SDL_fabs(ball.vx);  // Ensure ball goes right
		ball.x = leftPaddle.x + leftPaddle.w;
		// Add some angle based on where it hits the paddle
		float relativeIntersectY = (ball.y + ball.h / 2) - (leftPaddle.y + leftPaddle.h / 2);
		float normalizedIntersectY = relativeIntersectY / (leftPaddle.h / 2);
		ball.vy = normalizedIntersectY * BALL_SPEED * 0.75f;
	}

	if (CheckCollision(ball, rightPaddle)) {
		ball.vx = -SDL_fabs(ball.vx);  // Ensure ball goes left
		ball.x = rightPaddle.x - ball.w;
		// Add some angle based on where it hits the paddle
		float relativeIntersectY = (ball.y + ball.h / 2) - (rightPaddle.y + rightPaddle.h / 2);
		float normalizedIntersectY = relativeIntersectY / (rightPaddle.h / 2);
		ball.vy = normalizedIntersectY * BALL_SPEED * 0.75f;
	}

	// Ball out of bounds (scoring)
	if (ball.x < 0) {
		rightScore++;
		ResetBall();
	}
	if (ball.x > WINDOW_WIDTH) {
		leftScore++;
		ResetBall();
	}

	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw center line
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int y = 0; y < WINDOW_HEIGHT; y += 20) {
		SDL_FRect centerLine = { WINDOW_WIDTH / 2.0f - 2, (float)y, 4, 10 };
		SDL_RenderFillRect(renderer, &centerLine);
	}

	// Draw paddles
	SDL_FRect leftPaddleRect = { leftPaddle.x, leftPaddle.y, leftPaddle.w, leftPaddle.h };
	SDL_FRect rightPaddleRect = { rightPaddle.x, rightPaddle.y, rightPaddle.w, rightPaddle.h };
	SDL_RenderFillRect(renderer, &leftPaddleRect);
	SDL_RenderFillRect(renderer, &rightPaddleRect);

	// Draw ball
	SDL_FRect ballRect = { ball.x, ball.y, ball.w, ball.h };
	SDL_RenderFillRect(renderer, &ballRect);

	// Draw scores (simple text representation)
	char scoreText[64];
	SDL_snprintf(scoreText, sizeof(scoreText), "Player 1: %d    Player 2: %d", leftScore, rightScore);
	SDL_RenderDebugText(renderer, 10, 10, scoreText);

	// Draw controls
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 60, "Player 1: W/S keys");
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 40, "Player 2: UP/DOWN keys");
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 20, "Press R to reset, ESC to quit");

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
}
