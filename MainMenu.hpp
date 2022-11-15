#pragma once

#include "scene.hpp"
#include "button.hpp"
#include "quitButton.hpp"
#include "PlayButton.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Project1test/Player.hpp"
#include "Score.hpp"
#include "textObject.hpp"

class MainMenu : Scene
{
private:
	sf::Font font;
	sf::RenderWindow& window;
	PlayButton* playButton;
	QuitButton* quitButton;
	Score& score;
	TextObject HighscoresText;
public:
	MainMenu(sf::RenderWindow& window, SceneHandler& sceneHandler, Scene& sceneToUse, Player& player, Score& score);
	~MainMenu();


	//Button nextSceneButton("exitMenu", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor);
	//nextSceneButton.setPosition(sf::Vector2f(108.0f, 470.0f));

};

