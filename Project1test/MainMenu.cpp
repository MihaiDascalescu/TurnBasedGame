#include "MainMenu.hpp"

sf::Color randomColor = sf::Color(53, 82, 94, 255);
MainMenu::MainMenu(sf::RenderWindow& window, SceneHandler& sceneHandler,Scene& sceneToUse,Player& player,Score& score,sf::Font& font, sf::Color& color)
	: Scene("menuScreen"), window(window),score(score),HighscoresText("HighscoreText", font, ""), 
	replaceTxtFileContentButton("ReplaceTxtFileContentButton", font, "Replace Highscores", sf::Vector2f(400, 100), color)
{
	
	replaceTxtFileContentButton.setButtonAction([this] { OnReplaceClicked(); });
	replaceTxtFileContentButton.setPosition(sf::Vector2f(108.0f, 600));
	
	
	playButton = new PlayButton("playButton", font,"PLAY", sf::Vector2f(192.5f, 50.0f), darkColor, sceneHandler, window,sceneToUse,player);
	playButton->setPosition(sf::Vector2f(108.0f, 440.0f));

	quitButton  = new QuitButton ("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	quitButton->setPosition(sf::Vector2f(108.0f, 520.0f));
	
	
	
	HighscoresText.setPosition(sf::Vector2f(0, 0));
	HighscoresText.setCharacterSize(26);
	HighscoresText.setFillColor(darkColor);
	
	HighscoresText.setText(score.ReadFile());

	this->addGameObject(HighscoresText);
	this->addGameObject(*playButton);
	this->addGameObject(*quitButton);
	this->addGameObject(replaceTxtFileContentButton);
	
}


MainMenu::~MainMenu()
{
	delete playButton;
	delete quitButton;
	
}

void MainMenu::update()
{
	
	//score.WriteReadHighscores();
   HighscoresText.setText(score.ReadFile());
}

void MainMenu::OnReplaceClicked()
{
	score.ReplaceHighscoreFile();
}




