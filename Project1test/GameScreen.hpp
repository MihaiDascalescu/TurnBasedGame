#pragma once

#include "scene.hpp"
#include "ScoreButton.hpp"
#include "button.hpp"
#include <SFML/Graphics.hpp>
#include <memory> 

class GameScreen : public Scene
{
	private:
		sf::Font font;
		sf::RenderWindow& window;
		ScoreButton* scoreButton;
		
		
	public:
		GameScreen(sf::RenderWindow& window);
		~GameScreen();
};

