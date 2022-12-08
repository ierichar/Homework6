#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "Game.h"

namespace gm {
	// Constants
	const short TEXT_SIZE = 40;
	const short MAX_LIVES = 4;

	class UIManager
	{
	protected:

		// Game Values
		short p1Score = 0;

		// Position
		sf::Vector2f position;

		// Text
		sf::Font font;
		sf::Text* text;
		std::string str_text;

	public:
		UIManager();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		const std::string& getString();
		void setString(const std::string str_text);
		const sf::Vector2f& getPosition();
		void setPosition(const sf::Vector2f& position);
		~UIManager();

	};
}

#endif
