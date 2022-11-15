#include "Player.hpp"
#include "Project1test/TurnManager.hpp"

Player::Player(TurnManager& turnManager) : Character("My DUde", "", 0, 0, 0, turnManager)

{
	SpriteVector = std::vector<std::string>{ "head.png", "enemy2.png", "enemy3.png" };
	ResetStats();
	SetRandomSprite();

	spriteObject.setPosition(sf::Vector2f(300, 300));
	spriteObject.setScale(sf::Vector2f(3, 3));

	 
}

void Player::StartTurn()
{
}


Player::~Player()
{

}
