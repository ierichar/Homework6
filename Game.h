// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "UIManager.h"
#include "SoundManager.h"
#include "PlayerController.h"
#include "Level.h"

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

#include "Random.h"


// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	// Game Settings
	const short GAME_WIDTH = 825;
	const short GAME_HEIGHT = 825;
	const short PADDING = 5;

	const short ROWS = 8;
	const short COLUMNS = 14;
	const short NUM_OF_BRICKS = ROWS * COLUMNS;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game 
	{
	private:
		sf::RenderWindow window;			// Game Window

		SoundManager sound_manager;			// Sound Manager
		// SoundBuffers
		sf::SoundBuffer paddleBounce, wallBounce, brickDamage, brickDestroy, loseLife;
		sf::SoundBuffer normal_brick_sound, tough_brick_sound;

		UIManager ui_manager;				// UI Manager
		PlayerController player_controller;	// Player Controller

		// BrickTypes
		BrickType normal_brick = {
			1,
			sf::Color::White,
		};

		BrickType tough_brick = {
			2,
			sf::Color::Red,
		};

		std::vector<std::unique_ptr<Brick>> bricks;
		Level* level;						// Level (ref)

		Paddle p1;
		Paddle leftWall, rightWall, ceiling, floor;

		Ball ball;

		// Game Values
		int currentLevel;
		short p1Score = 0;
		short p1Lives = 0;	// Classic game rules: reach 4 lives = game over

		bool isGameStart;

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();

		// Helper functions
		void startLevel(const short level);
		
	};
}

#endif