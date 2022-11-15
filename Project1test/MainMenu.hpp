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
#include "ScoreButton.hpp"

class MainMenu : public Scene
{
	private:
		
		sf::RenderWindow& window;

		PlayButton* playButton;

		Button replaceTxtFileContentButton;

		sf::Color darkColor = sf::Color(71, 82, 94, 255);

		QuitButton* quitButton;
		
		Score& score;

		TextObject HighscoresText;

	public:
		MainMenu(sf::RenderWindow& window, SceneHandler& sceneHandler, Scene& sceneToUse, Player& player,Score& score,sf::Font& font,sf::Color& color);
		~MainMenu();
		void update() override;
		void OnReplaceClicked();



};

