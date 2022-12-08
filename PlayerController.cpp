#include "PlayerController.h"

using namespace sf;
using namespace gm;


gm::PlayerController::PlayerController(Paddle* paddle)
{
	this->paddle = paddle;
}

void gm::PlayerController::handleInput(Event event)
{
	if (paddle->getPosition().x > Mouse::getPosition().x)
	{
		paddle->move(Vector2f(-1, 0));
	}
	else if (paddle->getPosition().x < Mouse::getPosition().x) {
		paddle->move(Vector2f(1, 0));
	}
}

void gm::PlayerController::update(RenderWindow& window)
{
	paddle->update(window);
}

PlayerController::~PlayerController()
{

}
