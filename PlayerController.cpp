#include "PlayerController.h"

using namespace sf;
using namespace gm;


gm::PlayerController::PlayerController(Paddle* paddle)
{
	this->paddle = paddle;
}

void gm::PlayerController::handleInput(Event event)
{
	if (event.type == Event::MouseMoved) {
		paddle->setPosition(Vector2f(paddle->getPosition().y, Mouse::getPosition().x));
	}
}

void gm::PlayerController::update()
{

}

PlayerController::~PlayerController()
{

}
