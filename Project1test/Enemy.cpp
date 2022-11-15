#include "Enemy.hpp"
#include "TurnManager.hpp"
#include <iostream>
#include <random>

#include "GameHUD.hpp"

Enemy::Enemy(TurnManager& turnManager,Character& characterToAttack,Score& score) : Character("Enemy","head.png",0,0,0,turnManager),
characterToAttack(characterToAttack),score(score)
{
	SpriteVector = std::vector<std::string>{ "head.png", "enemy2.png", "enemy3.png"};
	ResetStats();
	SetRandomSprite();
	spriteObject.setPosition(sf::Vector2f(800, 300));
	spriteObject.setScale(sf::Vector2f(3, 3));

}

void Enemy::StartTurn()
{
	
	randomChoice = rand() % 10 + 1;
	if (randomChoice > 0 && randomChoice < 4) {
		int damageDealt = attackCharacter(characterToAttack);
		gameHud->getTurnResultText().setText("Attacked player for " + std::to_string(damageDealt));
	}
	else if(randomChoice >= 4 && randomChoice < 7){
		int healedFor = rand() % 10 + 1;
		AddHp(healedFor);
		gameHud->getTurnResultText().setText("Enemy increased health by " + std::to_string(healedFor));
	}
	else if(randomChoice > 7 && randomChoice < 9)
	{
		int defendedFor = rand() % 10 + 1;
		AddDefense(defendedFor);
		gameHud->getTurnResultText().setText("Enemy increased its defense by " + std::to_string(defendedFor));
	}
	else {
		gameHud->getTurnResultText().setText("Enemy rested this turn");
	}
	turnManager.EndTurn();
	
}
void Enemy::OnDead()
{
	score.UpdateScore();

	ResetStats();

	SetRandomSprite();

	std::cout << "Enemy dead!\n";
}

void Enemy::SetHUD(GameHUD* gameHud)
{
	this->gameHud = gameHud;
}

Enemy::~Enemy()
{
}
