// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game"),
	p1(Vector2f(0 + PADDLE_WIDTH + 2*PADDING, GAME_HEIGHT - 10*PADDLE_HEIGHT), Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
	
	leftWall(Vector2f(0, 0), Vector2f(PADDING, GAME_HEIGHT)),
	rightWall(Vector2f(GAME_WIDTH - PADDING, 0), Vector2f(PADDING, GAME_HEIGHT)),
	ceiling(Vector2f(0, 0), Vector2f(GAME_WIDTH, PADDING)),
	floor(Vector2f(0, GAME_HEIGHT - PADDING), Vector2f(GAME_WIDTH, PADDING)),

	ball(Vector2f(p1.getPosition().x, p1.getPosition().y - 2*BALL_RADIUS), BALL_RADIUS),
	
	isGameStart(false), 
	sound_manager(), ui_manager(), player_controller(&p1), level(nullptr) {

	// Set our fps to 60
	window.setFramerateLimit(60);
	currentLevel = 1;

	// Load the sounds
	if (!paddleBounce.loadFromFile("Assets/Sounds/paddle_bounce.wav")) {
		// ERROR
	}	
	if (!wallBounce.loadFromFile("Assets/Sounds/wall_bounce.wav")) {
		// ERROR
	}	
	if (!brickDamage.loadFromFile("Assets/Sounds/break.wav")) {
		// ERROR
	}	
	if (!brickDestroy.loadFromFile("Assets/Sounds/shatter.wav")) {
		// ERROR
	}	
	if (!loseLife.loadFromFile("Assets/Sounds/ball_lost.wav")) {
		// ERROR
	}
	if (!levelComplete.loadFromFile("Assets/Sounds/level_complete.wav")) {
		// ERROR
	}
	if (!gameOver.loadFromFile("Assets/Sounds/gameover.wav")) {
		// ERROR
	}
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

		if (event.type == Event::MouseButtonPressed && !isGameStart) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				// Reset Game
				isGameStart = true;

				startLevel(currentLevel);
				ui_manager.setGameText("LEVEL " + currentLevel);

				ball.move(Vector2f(Random::Range(-0.5f, 0.5f), -1.f));
			}
		}

		player_controller.handleInput(event);
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	player_controller.update(window);

	if (level != nullptr) {
		level->update(window);
		update_state();
	}

	if (ball.collide(p1.getCollider())) {
		sound_manager.playSFX(&paddleBounce);	// Play sound
		ball.bounce(Vector2f(0, -1));
	}

	if (ball.collide(ceiling.getCollider())) {
		sound_manager.playSFX(&wallBounce);	// Play sound
		ball.bounce(Vector2f(0, 1));
	}
	if (ball.collide(leftWall.getCollider())) {
		sound_manager.playSFX(&wallBounce);	// Play sound
		ball.bounce(Vector2f(1, 0));
	}
	if (ball.collide(rightWall.getCollider())) {
		sound_manager.playSFX(&wallBounce);	// Play sound
		ball.bounce(Vector2f(-1, 0));
	}
	if (ball.collide(floor.getCollider())) {
		sound_manager.playSFX(&loseLife);
		++p1Lives;
		ui_manager.setLivesText("" + p1Lives);
		if (p1Lives == 4)
		{
			isGameStart = false;
			ui_manager.setGameText("GAME OVER");
		}
	}

	//p1.update(window);
	if (isGameStart) {
		ball.update(window);
	}
	else {
		ball.setPosition(Vector2f(p1.getPosition().x, p1.getPosition().y - BALL_RADIUS * 2));
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	ui_manager.render(window);

	p1.render(window);
	ball.render(window);

	if (level != nullptr) {
		//level->render(window);
		render_state();
	}

	leftWall.render(window);
	rightWall.render(window);
	ceiling.render(window);
	floor.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	if (level != nullptr)
	{
		delete level;
		level = nullptr;
	}
}

void Game::startLevel(const short lvl_num)
{
	if (level != nullptr)
	{
		delete level;
		level = nullptr;
	}

	// TODO: start level based on number input
	if (lvl_num == 1)
	{
		// Set 2D array of bricktypes and position
		vector<pair<BrickType*, Vector2f>> newLevel;
		Vector2f startPos = Vector2f(
			ceiling.getPosition().y + PADDING,
			leftWall.getPosition().x + PADDING);
		BrickType* brickType = &tough_brick;

		// LEVEL 1 - 2 rows of tough, 2 of normal then repeat again
		for (short i = 1; i <= NUM_OF_BRICKS; i++)
		{
			if (i == NUM_OF_BRICKS / 4 + 1) {
				// switch to normal brick type
				brickType = &normal_brick;
			}
			else if (i == NUM_OF_BRICKS / 2 + 1) {
				brickType = &tough_brick;
			}
			else if (i == NUM_OF_BRICKS * 3 / 4 + 1) {
				brickType = &normal_brick;
			}
			
			// Create pair
			pair<BrickType*, Vector2f> newPair = make_pair(brickType, startPos);
			newLevel.push_back(newPair);

			// Set new pos
			if (i % COLUMNS == 0) {
				// New row
				startPos.x = leftWall.getPosition().x + PADDING;
				startPos.y += BRICK_HEIGHT + PADDING;
			}
			else {
				startPos.x += BRICK_WIDTH + PADDING;
			}
		}
		level = new Level(newLevel);
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

	bricks = move(level->getBricks());
}

void Game::render_state()
{
	for (size_t i = 0; i < bricks.size(); i++)
	{
		bricks[i]->render(window);
	}
}

void Game::update_state()
{
	for (size_t i = 0; i < bricks.size(); )
	{
		Brick* b = bricks[i].get();
		
		if (ball.collide(b->getCollider()))
		{
			cout << "bounce ball" << endl;
			if (ball.getPosition().y > b->getPosition().y - BRICK_HEIGHT / 2) {
				ball.bounce(Vector2f(0, 1));
			}
			else if (ball.getPosition().y < b->getPosition().y + BRICK_HEIGHT / 2) {
				ball.bounce(Vector2f(0, -1));
			}
			// ball.bounce(Vector2f(0, 1));		// Bounce ball
			b->setHealth(b->getHealth() - 1); // Update ball health
			ui_manager.setScoreText("" + p1Score);

			if (!(b->getAlive())) {
				sound_manager.playSFX(&brickDestroy);
				bricks.erase(bricks.begin() + i);
				continue;
			}
			else {
				sound_manager.playSFX(&brickDamage); // Play sound
			}
		}
		++i;
	}

	if (bricks.empty())
	{
		ui_manager.setGameText("LEVEL COMPLETE");
		currentLevel++;

		isGameStart = false;
	}
}