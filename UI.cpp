#include "UI.h"

using namespace gm;
using namespace sf;
using namespace std;

UI::UI() : position(Vector2f(GAME_WIDTH /2, GAME_HEIGHT / 2)),
	str_text("Left Click to START")
{
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

void UI::update(RenderWindow& window)
{
	text->setString(str_text);
	text->setPosition(this->position);
}

void UI::render(RenderWindow& window)
{
	window.draw(*text);
}

const string& UI::getString()
{
	return str_text;
}

void UI::setString(const std::string str_text)
{
	this->str_text = str_text;
}

const sf::Vector2f& UI::getPosition()
{
	return this->position;
}

void UI::setPosition(const sf::Vector2f& position)
{
	this->position = position;
}

gm::UI::~UI()
{
	// Clean up text objects
	delete text;
}