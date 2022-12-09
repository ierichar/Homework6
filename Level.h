#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Brick.h"

namespace gm {
	class Level 
	{
	private:
		int size;
		std::vector<Brick> bricks;
	public:
		// Constructor
		// Takes a 2d array of ints / Enums(indicating what type of brick and where
		// it should be on the "grid" representation of the level) and creates a 1d 
		// vector(i.e., object list) of all bricks in the level.Should create the 
		// brick objects with appropriate x / y position and BrickType and add them
		// to the object list
		Level(std::vector<std::pair<BrickType*, sf::Vector2f>> v);

		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);

		// Returns a reference or pointer to the object list of Bricks
		std::vector<Brick>& getBricks();
		int getSize() const;

		// Resets all bricks in the level back to their default 
		// state(alive again with full health)
		void reset();

		~Level();
	};
}

#endif // !LEVEL_H
