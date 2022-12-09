#include "Ball.h"

#include <iostream>

using namespace gm;
using namespace sf;
using namespace std;

Ball::Ball(const Vector2f& position, const float radius)
	: GameObject(position, Vector2f(radius, radius)) {
	body.setPosition(position);
	body.setRadius(radius);

	velocity = Vector2f(0, 0);
	speed_multiplier = 1.f;
}

void Ball::update(sf::RenderWindow& window) {
	position.x += velocity.x * BALL_SPEED * speed_multiplier;
	position.y += velocity.y * BALL_SPEED * speed_multiplier;

	body.setPosition(position);
	this->setPosition(position);
}

void Ball::render(sf::RenderWindow& window) {
	window.draw(body);
}

// Position Accessor & Mutator
const sf::Vector2f& gm::Ball::getPosition() const
{
	return this->GameObject::getPosition();
}

void gm::Ball::setPosition(const sf::Vector2f& position)
{
	this->GameObject::setPosition(position);
}

// Apply force by calling base class move
void gm::Ball::move(const sf::Vector2f& force)
{
	velocity += force;
}

// Velocity Accessor & Mutator
const sf::Vector2f& gm::Ball::getVelocity() const
{
	return this->velocity;
}

void gm::Ball::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

void gm::Ball::bounce(const sf::Vector2f& normalVector)
{
	if (velocity != Vector2f(0, 0) && normalVector != Vector2f(0, 0)) {
		// Projection of Vi onto n
		// Vf = Vi - 2 * (Vi * n / mag(n)**2) * n
		Vector2f projVector, fVector;
		projVector = vScalarProduct(dotProduct(velocity, normalVector), normalVector);
		//cout << "1: " << projVector.x << ", " << projVector.y << endl;
		projVector = vScalarProduct(1/calcMagnitude(normalVector), projVector);
		//cout << "2: " << projVector.x << ", " << projVector.y << endl;
		projVector = vScalarProduct(2.0f, projVector);
		//cout << "3: " << projVector.x << ", " << projVector.y << endl;
		fVector = velocity - projVector;
		//cout << "4: " << fVector.x << ", " << fVector.y << endl;
		
		this->setVelocity(fVector);
	}
	return;
}

const float gm::Ball::calcMagnitude(const sf::Vector2f& vector) 
{
	float magnitude = float(pow(pow(vector.x, 2) + pow(vector.y, 2), 2));
	return magnitude;
}

Vector2f gm::Ball::vScalarProduct(const float c, const Vector2f& vector)
{
	// vector * c = (v.x * c , v.y * c)
	Vector2f sVector = Vector2f(vector.x * c, vector.y * c);
	return sVector;
}


const float gm::Ball::dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	// Dot Product Formula
	// x1 * x2 + y1 * y2
	return ((v1.x * v2.x) + (v1.y * v2.y));
}

void Ball::increaseSpeed()
{
	speed_multiplier += 0.15f;
}