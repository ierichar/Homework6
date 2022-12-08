#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	// Constants
	const short TEXT_SIZE = 40;
	const short MAX_LIVES = 4;

	class UIManager
	{
	protected:

		// Position
		sf::Vector2f position;

		// Text
		sf::Font font;
		sf::Text* text;
		std::string str_text, score_text, lives_text;

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
