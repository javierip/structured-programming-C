// SDL based Pong Game in C

#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

// Game constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PADDLE_WIDTH = 15;
const int PADDLE_HEIGHT = 80;
const int BALL_SIZE = 15;
const float PADDLE_SPEED = 400.0f;
const float AI_PADDLE_SPEED = 320.0f;
const float BALL_SPEED = 300.0f;

struct GameObject
{
	float x, y;
	float w, h;
	float vx, vy;
};

struct GameState
{
	int leftScore;
	int rightScore;
	Uint64 lastTime;
	bool ballActive;
	bool wPressed;
	bool sPressed;
	bool upPressed;
	bool downPressed;
	float aiReactionDelay;
	Uint64 lastAIUpdate;
};

static GameObject leftPaddle;  // Human player
static GameObject rightPaddle; // AI player
static GameObject ball;		   // Single ball instance

// Global game state
static GameState gameState;

void update_ai_paddle(float deltaTime)
{
	// Calculate paddle center
	float paddle_center = rightPaddle.y + rightPaddle.h / 2.0f;
	float ball_center = ball.y + ball.h / 2.0f;

	// AI only reacts when ball is moving towards it (adds difficulty)
	if (ball.vx > 0)
	{
		// Calculate the difference
		float diff = ball_center - paddle_center;

		// Add some tolerance to make AI less perfect
		float tolerance = 15.0f;

		// Move towards ball with limited speed
		if (diff > tolerance && rightPaddle.y + rightPaddle.h < WINDOW_HEIGHT)
		{
			rightPaddle.vy = AI_PADDLE_SPEED;
		}
		else if (diff < -tolerance && rightPaddle.y > 0)
		{
			rightPaddle.vy = -AI_PADDLE_SPEED;
		}
		else
		{
			rightPaddle.vy = 0; // Stop moving when close enough
		}
	}
	else
	{
		// When ball is moving away, slowly return to center
		float center_position = WINDOW_HEIGHT / 2.0f - rightPaddle.h / 2.0f;
		float diff = center_position - rightPaddle.y;

		if (SDL_fabs(diff) > 5.0f)
		{
			rightPaddle.vy = (diff > 0) ? AI_PADDLE_SPEED * 0.3f : -AI_PADDLE_SPEED * 0.3f;
		}
		else
		{
			rightPaddle.vy = 0;
		}
	}
}

void ResetBall()
{
	// Reset the single ball instance to center position
	ball.x = WINDOW_WIDTH / 2.0f - BALL_SIZE / 2.0f;
	ball.y = WINDOW_HEIGHT / 2.0f - BALL_SIZE / 2.0f;

	// Random direction
	ball.vx = (SDL_GetTicks() % 2 == 0) ? BALL_SPEED : -BALL_SPEED;
	ball.vy = (SDL_GetTicks() % 200 - 100) * 2.0f; // Random Y velocity

	// Ensure ball is active (redundant but explicit)
	gameState.ballActive = true;
}

bool CheckCollision(const GameObject &a, const GameObject &b)
{
	return (a.x < b.x + b.w &&
			a.x + a.w > b.x &&
			a.y < b.y + b.h &&
			a.y + a.h > b.y);
}

void InitializeGame()
{
	// Initialize human paddle (left)
	leftPaddle.x = 50;
	leftPaddle.y = WINDOW_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f;
	leftPaddle.w = PADDLE_WIDTH;
	leftPaddle.h = PADDLE_HEIGHT;
	leftPaddle.vx = 0;
	leftPaddle.vy = 0;

	// Initialize AI paddle (right)
	rightPaddle.x = WINDOW_WIDTH - 50 - PADDLE_WIDTH;
	rightPaddle.y = WINDOW_HEIGHT / 2.0f - PADDLE_HEIGHT / 2.0f;
	rightPaddle.w = PADDLE_WIDTH;
	rightPaddle.h = PADDLE_HEIGHT;
	rightPaddle.vx = 0;
	rightPaddle.vy = 0;

	// Initialize the single ball instance
	ball.w = BALL_SIZE;
	ball.h = BALL_SIZE;

	// Initialize game state
	gameState.leftScore = 0;
	gameState.rightScore = 0;
	gameState.ballActive = true;
	gameState.wPressed = false;
	gameState.sPressed = false;
	gameState.upPressed = false;
	gameState.downPressed = false;
	gameState.aiReactionDelay = 0.05f;
	gameState.lastAIUpdate = SDL_GetTicks();
	gameState.lastTime = SDL_GetTicks();

	ResetBall();
}

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	/* Create the window */
	if (!SDL_CreateWindowAndRenderer("Simple Pong Game - Player vs AI", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
	{
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	InitializeGame();

	return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS; /* end the program, reporting success to the OS. */
	}

	if (event->type == SDL_EVENT_KEY_DOWN)
	{
		switch (event->key.scancode)
		{
		case SDL_SCANCODE_W:
			gameState.wPressed = true;
			break;
		case SDL_SCANCODE_S:
			gameState.sPressed = true;
			break;
		case SDL_SCANCODE_UP:
			gameState.upPressed = true;
			break;
		case SDL_SCANCODE_DOWN:
			gameState.downPressed = true;
			break;
		case SDL_SCANCODE_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDL_SCANCODE_R:
			// Reset game - reuses the single ball instance
			gameState.leftScore = 0;
			gameState.rightScore = 0;
			ResetBall();
			break;
		}
	}

	if (event->type == SDL_EVENT_KEY_UP)
	{
		switch (event->key.scancode)
		{
		case SDL_SCANCODE_W:
			gameState.wPressed = false;
			break;
		case SDL_SCANCODE_S:
			gameState.sPressed = false;
			break;
		case SDL_SCANCODE_UP:
			gameState.upPressed = false;
			break;
		case SDL_SCANCODE_DOWN:
			gameState.downPressed = false;
			break;
		}
	}

	return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
	Uint64 currentTime = SDL_GetTicks();
	float deltaTime = (currentTime - gameState.lastTime) / 1000.0f;
	gameState.lastTime = currentTime;

	// Update human paddle movement (left paddle) - supports both W/S and UP/DOWN keys
	leftPaddle.vy = 0;
	if (gameState.wPressed || gameState.upPressed)
		leftPaddle.vy = -PADDLE_SPEED;
	if (gameState.sPressed || gameState.downPressed)
		leftPaddle.vy = PADDLE_SPEED;

	// Update AI paddle (right paddle)
	update_ai_paddle(deltaTime);

	// Update positions
	leftPaddle.y += leftPaddle.vy * deltaTime;
	rightPaddle.y += rightPaddle.vy * deltaTime;

	// Update the single ball position only if active
	if (gameState.ballActive)
	{
		ball.x += ball.vx * deltaTime;
		ball.y += ball.vy * deltaTime;
	}

	// Keep paddles on screen
	if (leftPaddle.y < 0)
		leftPaddle.y = 0;
	if (leftPaddle.y + leftPaddle.h > WINDOW_HEIGHT)
		leftPaddle.y = WINDOW_HEIGHT - leftPaddle.h;
	if (rightPaddle.y < 0)
		rightPaddle.y = 0;
	if (rightPaddle.y + rightPaddle.h > WINDOW_HEIGHT)
		rightPaddle.y = WINDOW_HEIGHT - rightPaddle.h;

	// Ball physics - only for the single ball instance
	if (gameState.ballActive)
	{
		// Ball collision with top/bottom walls
		if (ball.y <= 0 || ball.y + ball.h >= WINDOW_HEIGHT)
		{
			ball.vy = -ball.vy;
			ball.y = (ball.y <= 0) ? 0 : WINDOW_HEIGHT - ball.h;
		}

		// Ball collision with paddles
		if (CheckCollision(ball, leftPaddle))
		{
			ball.vx = SDL_fabs(ball.vx); // Ensure ball goes right
			ball.x = leftPaddle.x + leftPaddle.w;
			// Add some angle based on where it hits the paddle
			float relativeIntersectY = (ball.y + ball.h / 2) - (leftPaddle.y + leftPaddle.h / 2);
			float normalizedIntersectY = relativeIntersectY / (leftPaddle.h / 2);
			ball.vy = normalizedIntersectY * BALL_SPEED * 0.75f;
		}

		if (CheckCollision(ball, rightPaddle))
		{
			ball.vx = -SDL_fabs(ball.vx); // Ensure ball goes left
			ball.x = rightPaddle.x - ball.w;
			// Add some angle based on where it hits the paddle
			float relativeIntersectY = (ball.y + ball.h / 2) - (rightPaddle.y + rightPaddle.h / 2);
			float normalizedIntersectY = relativeIntersectY / (rightPaddle.h / 2);
			ball.vy = normalizedIntersectY * BALL_SPEED * 0.75f;
		}

		// Ball out of bounds (scoring) - reset the same ball instance
		if (ball.x < 0)
		{
			gameState.rightScore++;
			ResetBall(); // Reuses the single ball instance
		}
		if (ball.x > WINDOW_WIDTH)
		{
			gameState.leftScore++;
			ResetBall(); // Reuses the single ball instance
		}
	}

	// Clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw center line
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int y = 0; y < WINDOW_HEIGHT; y += 20)
	{
		SDL_FRect centerLine = {WINDOW_WIDTH / 2.0f - 2, (float)y, 4, 10};
		SDL_RenderFillRect(renderer, &centerLine);
	}

	// Draw paddles
	SDL_FRect leftPaddleRect = {leftPaddle.x, leftPaddle.y, leftPaddle.w, leftPaddle.h};
	SDL_FRect rightPaddleRect = {rightPaddle.x, rightPaddle.y, rightPaddle.w, rightPaddle.h};
	SDL_RenderFillRect(renderer, &leftPaddleRect);
	SDL_RenderFillRect(renderer, &rightPaddleRect);

	// Draw the single ball instance only if active
	if (gameState.ballActive)
	{
		SDL_FRect ballRect = {ball.x, ball.y, ball.w, ball.h};
		SDL_RenderFillRect(renderer, &ballRect);
	}

	// Draw scores and updated instructions
	char scoreText[64];
	SDL_snprintf(scoreText, sizeof(scoreText), "Player: %d    AI: %d", gameState.leftScore, gameState.rightScore);
	SDL_RenderDebugText(renderer, 10, 10, scoreText);

	// Draw controls (updated for multiple key options)
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 60, "Player: W/S or UP/DOWN keys");
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 40, "AI controls right paddle");
	SDL_RenderDebugText(renderer, 10, WINDOW_HEIGHT - 20, "Press R to reset, ESC to quit");

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}
