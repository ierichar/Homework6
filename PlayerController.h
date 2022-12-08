#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"

namespace gm {
	class PlayerController
	{
	private:
		Paddle* paddle;
		// include key codes for multiple players
	public:
		PlayerController(Paddle* paddle);
		void handleInput(sf::Event event);
		void update();
		~PlayerController();
	};
}

#endif
