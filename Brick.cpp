#include "Brick.h"

using namespace gm;
using namespace sf;

Brick::Brick(BrickType* t, const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size)
{
	type = t;
	this->hp = t->hp;
	this->isAlive = true;

	body.setPosition(position);
	body.setSize(size);
	body.setFillColor(t->col);
}

void Brick::update(sf::RenderWindow& window)
{
	body.setPosition(position);
	this->setPosition(position);
}

void Brick::render(sf::RenderWindow& window)
{
	window.draw(body);
}

void Brick::setPosition(const sf::Vector2f& position)
{
	this->GameObject::setPosition(position);
}

void Brick::setAlive(const bool isAlive)
{
	this->isAlive = isAlive;
}

const bool Brick::getAlive()
{
	return this->isAlive;
}

void Brick::setHealth(const int hp)
{
	this->hp = hp;
}

const int Brick::getHealth()
{
	return this->hp;
}

void Brick::reset()
{
	this->isAlive = true;
	this->hp = type->hp;
}

Brick::~Brick()
{
	delete this;
}
