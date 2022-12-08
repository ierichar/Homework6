#include "GameObject.h"

using namespace sf;
using namespace gm;

// Default constructor
GameObject::GameObject() {}

// Overloaded constructor that takes a position and size
// NOTE that we set the position using the initialization list and
// the collider with the position and size for sf::FloatRect
GameObject::GameObject(const Vector2f& position, const Vector2f& size)
	: position(position), collider(position, size) {}


// Our position getter, NOTE the const reference return and marking the method itself const
const Vector2f& GameObject::getPosition() const {
	return position;
}

// Our position setter, takes a Vector2f by const reference
// Also, reset collider position
void GameObject::setPosition(const Vector2f& position) {
	this->position = position;
	collider.left = position.x;
	collider.top = position.y;
}

void GameObject::move(const Vector2f& force)
{
	this->position.x += force.x;
	this->position.y += force.y;
}

// Our collider getter
const FloatRect& gm::GameObject::getCollider() const
{
	return collider;
}

bool GameObject::collide(const Vector2f& point) const
{
	return collider.contains(point);
}

bool GameObject::collide(const Vector2i& point) const
{
	Vector2f newVec = Vector2f(point);
	return collider.contains(newVec);
}

bool GameObject::collide(const FloatRect& point) const
{
	return collider.intersects(point);
}

gm::GameObject::~GameObject()
{
	// TODO: free data
}


