#include "UIManager.h"

using namespace gm;
using namespace sf;
using namespace std;

UIManager::UIManager()
{
	str_text = "Left Click to START";
	position = Vector2f(825 / 2, 825 / 2);

	text = new Text();
	if (!font.loadFromFile("Assets/clover-sans.ttf")) {
		//error
	}
	text->setCharacterSize(TEXT_SIZE);
	text->setFont(font);
	text->setFillColor(Color::White);
	text->setString(str_text);
	text->setPosition(this->position);
}

void UIManager::update(RenderWindow& window)
{
	text->setString(str_text);
	text->setPosition(this->position);
}

void UIManager::render(RenderWindow& window)
{
	window.draw(*text);
}

const string& UIManager::getString()
{
	return str_text;
}

void UIManager::setString(const std::string str_text)
{
	this->str_text = str_text;
}

const sf::Vector2f& UIManager::getPosition()
{
	return this->position;
}

void UIManager::setPosition(const sf::Vector2f& position)
{
	this->position = position;
}

UIManager::~UIManager()
{
	// Clean up text objects
	delete text;
	text = nullptr;

	delete this;
}