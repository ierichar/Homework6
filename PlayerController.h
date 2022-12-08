#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"

namespace gm {
	class PlayerController
	{
	private:
		Paddle* paddle;
		
		// Mouse position to update
		sf::Vector2f moveLeft, moveRight;
	public:
		PlayerController(Paddle* paddle);
		void handleInput(sf::Event event);
		void update(sf::RenderWindow& window);
		~PlayerController();
	};
}

#endif
