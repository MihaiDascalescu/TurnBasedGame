#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>

#include "scene.hpp"
#include "textObject.hpp"
#include "spriteObject.hpp"
#include "character.hpp"
#include "Project1test/GameHUD.hpp"
#include "Project1test/TurnManager.hpp"
#include "button.hpp"
#include "quitButton.hpp"
#include "sceneHandler.hpp"
#include "Project1test/MainMenu.hpp"
#include "Project1test/GameScreen.hpp"
#include "Project1test/ScoreButton.hpp"
#include "Project1test/Player.hpp"
#include "Project1test/Score.hpp"
#include "Project1test/Enemy.hpp"


int main() {
	// Make sure we have a random seed every time the game launches.
	srand(time(nullptr));

	sf::Font font;
	font.loadFromFile("Lato-Regular.ttf");
	sf::Color darkColor = sf::Color(71, 82, 94, 255);
	sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
	sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML with Scenes!",sf::Style::Close);
	
	SceneHandler sceneHandler;

	TurnManager turnManager;

	Player player(turnManager);

	Score score;

	GameScreen gameScreen(window);

	MainMenu menuScreen(window, sceneHandler,gameScreen, player,score,font,darkColor);

	sceneHandler.addScene(menuScreen);
	sceneHandler.addScene(gameScreen);

	Enemy enemyCharacter(turnManager, player, score);

	GameHUD hud(player, enemyCharacter, font, sceneHandler, score,darkColor);

	gameScreen.addGameObject(player.GetSpriteObject());
	gameScreen.addGameObject(enemyCharacter.GetSpriteObject());

	turnManager.AddCharacterToTurnList(player);
	turnManager.AddCharacterToTurnList(enemyCharacter);
	turnManager.StartTurn();

	gameScreen.addGameObject(hud);
	hud.AddUIToScene(gameScreen);


    while (window.isOpen()) {
		
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
				sceneHandler.eventHandler(event, window);
				
            }
        }

        window.clear(sf::Color::White);
		sceneHandler.update();
		sceneHandler.render(window);
		
		
        window.display();
    }
	
    return 0;
}





