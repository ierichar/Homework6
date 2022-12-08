// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game"),
	p1(Vector2f(0 + PADDLE_WIDTH + 2*PADDING, GAME_HEIGHT/2 - PADDLE_HEIGHT/2), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	
	leftWall(Vector2f(0, 0), Vector2f(PADDING, GAME_HEIGHT)),
	rightWall(Vector2f(GAME_WIDTH - PADDING, 0), Vector2f(PADDING, GAME_HEIGHT)),
	ceiling(Vector2f(0, 0), Vector2f(GAME_WIDTH, PADDING)),
	floor(Vector2f(0, GAME_HEIGHT - PADDING), Vector2f(GAME_WIDTH, PADDING)),

	ball(Vector2f(GAME_WIDTH/2 - BALL_RADIUS, GAME_HEIGHT/6 - BALL_RADIUS),  BALL_RADIUS),
	
	// Initialize the number of boxes

	isGameStart(false), 
	sound_manager(), ui_manager(), player_controller(&p1), level(nullptr) {

	// Set our fps to 60
	window.setFramerateLimit(60);
	currentLevel = 0;
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		//std::cout << "Debug here" << std::endl;
		if (event.type == Event::Closed)
			window.close();

		if (event.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				// Reset Game
				isGameStart = true;

				// Ball, p1, p2 positions
				p1.setPosition(Vector2f(
					GAME_WIDTH / 2 - PADDLE_WIDTH / 2, GAME_HEIGHT - PADDLE_HEIGHT * 2));
				ball.setPosition(Vector2f(
					p1.getPosition().x, p1.getPosition().y - BALL_RADIUS));
			}
		}

		if (event.type == Event::MouseMoved) {
			player_controller.handleInput(event);
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	if (ball.collide(p1.getCollider())) {
		//sound.setBuffer(paddleBounce);
		sound_manager.play("paddleBounce");
		ball.bounce(Vector2f(0, -1));
	}

	p1.update(window);
	if (isGameStart) {
		ball.update(window);
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	ui_manager.render(window);

	p1.render(window);
	ball.render(window);

	leftWall.render(window);
	rightWall.render(window);
	ceiling.render(window);
	floor.render(window);

	// Display the window buffer for this frame
	window.display();
}

void Game::startLevel(const short lvl_num)
{
	if (level != nullptr)
	{
		delete level;
	}

	// TODO: start level based on number input
	if (lvl_num == 1)
	{
		// Set 2D array as
	}
	if (lvl_num == 2)
	{

	}
	if (lvl_num == 3)
	{

	}
	
	// Reposition ball, paddle, score, bricks
	isGameStart = true;

	// Ball, p1, p2 positions
	p1.setPosition(Vector2f(
		GAME_WIDTH / 2 - PADDLE_WIDTH / 2, GAME_HEIGHT - PADDLE_HEIGHT * 2));
	ball.setPosition(Vector2f(
		p1.getPosition().x, p1.getPosition().y - BALL_RADIUS));
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	if (level != nullptr)
	{
		delete level;
	}
}