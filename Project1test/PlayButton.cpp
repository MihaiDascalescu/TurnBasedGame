#include "PlayButton.hpp"

PlayButton::PlayButton(std::string identifier, sf::Font& font, std::string buttonText,
	sf::Vector2f size, sf::Color color,SceneHandler& sceneHandler, sf::RenderWindow& window,Scene& sceneToUse,Player& player) 
	: Button(identifier, font, buttonText, size, color), window(window), sceneHandler(sceneHandler),sceneToUse(sceneToUse),player(player)
{ 
}

PlayButton::~PlayButton() { };

void PlayButton::onClick() 
{
	sceneHandler.stackScene(sceneToUse.getIdentifier());
	player.SetRandomSprite();
	player.ResetStats();
	
}

