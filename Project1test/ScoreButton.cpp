  #include "ScoreButton.hpp"



ScoreButton::ScoreButton(std::string identifier, sf::Font& font, std::string buttonText,
	sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier,font,buttonText,size,color), window(window)
{
}

void ScoreButton::onClick() {
	
	
	
	
}

ScoreButton::~ScoreButton()
{
}
void ScoreButton::UpdateScore() {
	scoreS++;
}
