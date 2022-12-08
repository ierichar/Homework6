#include "Paddle.h"

using namespace sf;
using namespace gm;

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size) {
	body = new RectangleShape();
	body->setPosition(position);
	body->setSize(size);
}

void Paddle::update(sf::RenderWindow& window)
{
	this->GameObject::setPosition(position);
	body->setPosition(position);
}

void Paddle::render(sf::RenderWindow& window)
{
	window.draw(*body);
}

void Paddle::move(const Vector2f& force)
{
	this->GameObject::setPosition(getPosition() +
		Vector2f(force.x * PADDLE_SPEED, force.y * PADDLE_SPEED));
}

Paddle::~Paddle()
{
	delete body;
	body = nullptr;
}