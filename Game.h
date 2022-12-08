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
	const short PADDING = 20;

	const short PADDLE_WIDTH = 100;
	const short PADDLE_HEIGHT = 20;

	const short BALL_RADIUS = 20;
	const short NUM_OF_BOXES = 112;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game 
	{
	private:
		sf::RenderWindow window;			// Game Window

		SoundManager sound_manager;			// Sound Manager
		UIManager ui_manager;				// UI Manager
		PlayerController player_controller;	// Player Controller
		Level* level;						// Level (ref)

		Paddle p1;
		Paddle leftWall, rightWall, ceiling, floor;

		Ball ball;

		bool isGameStart;
		int currentLevel;

		// BrickTypes
		BrickType normal_brick = {
			1,
			sf::Color::White,
		};

		BrickType tough_brick = {
			2,
			sf::Color::Red,
		};

		// SoundBuffers
		sf::SoundBuffer paddleBounce, wallBounce, brickDamage, brickDestroy, loseLife;
		sf::SoundBuffer normal_brick_sound, tough_brick_sound;

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