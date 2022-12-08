#include "PlayerController.h"

using namespace sf;
using namespace gm;


gm::PlayerController::PlayerController(Paddle* paddle)
{
	this->paddle = paddle;

	moveLeft = Vector2f(-1.f, 0);
	moveRight = Vector2f(1.f, 0);
}

void gm::PlayerController::handleInput(Event event)
{
	
}

void gm::PlayerController::update(RenderWindow& window)
{
	if (paddle->getPosition().x + PADDLE_WIDTH / 2 > float(Mouse::getPosition(window).x))
	{
		paddle->move(moveLeft);
	}
	else if (paddle->getPosition().x + PADDLE_WIDTH / 2 < float(Mouse::getPosition(window).x)) {
		paddle->move(moveRight);
	}
	paddle->update(window);
}

PlayerController::~PlayerController()
{
	paddle = nullptr;
}
