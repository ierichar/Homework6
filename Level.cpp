#include "Level.h"

using namespace gm;
using namespace sf;
using namespace std;

gm::Level::Level(vector<pair<BrickType*, Vector2f>> v)
{
	Brick* newBrick;
	short i = 0;
	numBricks = v.size();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		newBrick = new Brick(it->first, it->second,
			Vector2f(BRICK_WIDTH, BRICK_HEIGHT));

		bricks.push_back(*newBrick);
	}
}

void gm::Level::update(sf::RenderWindow& window)
{
	for (auto it = bricks.begin(); it != bricks.end(); ++it)
	{
		it->update(window);
	}
}

void gm::Level::render(sf::RenderWindow& window)
{
	for (auto it = bricks.begin(); it != bricks.end(); ++it)
	{
		it->render(window);
	}
}

vector<Brick>& gm::Level::getBricks()
{
	return bricks;
}

void gm::Level::reset()
{
	for (auto it = bricks.begin(); it != bricks.end(); ++it)
	{
		it->reset();
	}
}

gm::Level::~Level()
{
	for (auto it = bricks.begin(); it != bricks.end(); ++it)
	{
		delete &it;
		bricks.erase(it);
	}
}
