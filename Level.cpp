#include "Level.h"
#include <iostream>

using namespace gm;
using namespace sf;
using namespace std;

gm::Level::Level(vector<pair<BrickType*, Vector2f>> v)
{
	
	Brick* newBrick;
	size = v.size();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		newBrick = new Brick(it->first, it->second,
			Vector2f(BRICK_WIDTH, BRICK_HEIGHT));

		bricks.push_back(make_unique<Brick>(*newBrick));
		newBrick = nullptr;
	}
}

void gm::Level::update(sf::RenderWindow& window)
{
	for (auto& i : bricks)
	{
		//i->update(window);
	}
}

void gm::Level::render(sf::RenderWindow& window)
{
	for (auto& i : bricks)
	{
		i->render(window);
	}
}

 vector<unique_ptr<Brick>>& gm::Level::getBricks()
{
	 return bricks;
}

int Level::getSize() const
{
	return this->size;
}

void gm::Level::reset()
{
	for (auto& i : bricks)
	{
		i->reset();
	}
}

gm::Level::~Level()
{
	bricks.clear();
}
