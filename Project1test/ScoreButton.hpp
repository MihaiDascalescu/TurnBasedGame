#pragma once
#include "../button.hpp"
#include "../sceneHandler.hpp"
#include "Score.hpp"


class ScoreButton : public Button
{
private:
	sf::RenderWindow& window;
	
	
	
public:
 unsigned int scoreS = 0;
	ScoreButton(std::string identifier, sf::Font& font, std::string buttonText,
		sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
	~ScoreButton();

	void onClick() override;

	void UpdateScore();
};