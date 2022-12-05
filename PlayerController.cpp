#include "PlayerController.h"
#include <iostream>

using namespace sf;
using namespace gm;
using namespace std;	// debug


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
