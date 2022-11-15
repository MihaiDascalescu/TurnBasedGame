#pragma once
#include "../button.hpp"
#include "../sceneHandler.hpp"
#include "Project1test/Player.hpp"

class PlayButton : public Button
{
	private:
		sf::RenderWindow& window;
		SceneHandler& sceneHandler;
		Scene& sceneToUse;
	public:
		
		PlayButton(std::string identifier, sf::Font& font, std::string buttonText,
			sf::Vector2f size, sf::Color color,SceneHandler& sceneHandler, sf::RenderWindow& window,Scene& sceneToUse,Player& player);
		Player& player;
		~PlayButton();

		void onClick() override;
};
