#include "Level.h"

using namespace gm;
using namespace sf;
using namespace std;

BrickType normal_brick = {
	1,
	Color::White,
	&normalBrickSound
};
BrickType tough_brick = {
	2,
	Color::Red,
	&tough_brick_sound
};

gm::Level::Level(vector<pair<BrickType, Vector2f>> v)
{
	short i = 0;
	numBricks = v.size();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		bricks[i] = new Brick(it->first, it->second, Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	}
}

void gm::Level::update(sf::RenderWindow& window)
{
}

void gm::Level::render(sf::RenderWindow& window)
{
}

Brick* gm::Level::getBricks()
{
	return nullptr;
}

void gm::Level::reset()
{
}

gm::Level::~Level()
{
}
