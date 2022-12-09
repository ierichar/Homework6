#include "UIManager.h"

using namespace gm;
using namespace sf;
using namespace std;

UIManager::UIManager()
{
	str_text = "Left Click to START";
	txt_position = Vector2f(825 / 2 - 100, 825 / 2);


	if (!font.loadFromFile("Assets/Fonts/clover-sans.ttf")) {
		// ERROR
	}

	game_text = new Text(str_text, font, TEXT_SIZE/2);
	game_text->setFillColor(Color::White);
	game_text->setPosition(this->txt_position);

	str_text = "";
	txt_position.x = 100;
	txt_position.y = 100;
	score_text = new Text(str_text, font, TEXT_SIZE);
	score_text->setFillColor(Color::White);
	score_text->setPosition(this->txt_position);

	txt_position.x = 700;
	txt_position.y = 100;
	lives_text = new Text(str_text, font, TEXT_SIZE);
	score_text->setFillColor(Color::White);
	score_text->setPosition(this->txt_position);

}

void UIManager::update(RenderWindow& window)
{	
	game_text->setPosition(this->txt_position);
}

void UIManager::render(RenderWindow& window)
{
	window.draw(*game_text);
	window.draw(*score_text);
	window.draw(*lives_text);
}

void UIManager::setGameText(const std::string str_text)
{
	game_text->setString(str_text);
}

void UIManager::setScoreText(const std::string str_text)
{
	score_text->setString(str_text);
}

void gm::UIManager::setLivesText(const std::string str_text)
{
	lives_text->setString(str_text);
}

UIManager::~UIManager()
{
	// Clean up text objects
	delete game_text;
	game_text = nullptr;
	delete score_text;
	score_text = nullptr;
	delete lives_text;
	lives_text = nullptr;

}