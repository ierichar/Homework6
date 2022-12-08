#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

#define PADDLE_SPEED 10.0f

namespace gm {
	const short PADDLE_WIDTH = 100;
	const short PADDLE_HEIGHT = 20;

	class Paddle :
		public GameObject
	{
	private:
		sf::RectangleShape* body;
	public:
		Paddle(const sf::Vector2f& position, const sf::Vector2f& size);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window);

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window);

		virtual void move(const sf::Vector2f& force);

		~Paddle();
	};
}

#endif // Paddle.h