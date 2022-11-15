#include "GameScreen.hpp"



GameScreen::GameScreen(sf::RenderWindow& window) : Scene("gameScreen"),window(window)
{
	font.loadFromFile("Lato-Regular.ttf");
	sf::Color darkColor = sf::Color(71, 82, 94, 255);

	
	
}


GameScreen::~GameScreen()
{
	delete scoreButton;
}
