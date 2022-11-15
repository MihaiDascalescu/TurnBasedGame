#pragma once
#include "character.hpp"
#include "Score.hpp"

class GameHUD;


class Enemy : public Character
{

public:

	Enemy(TurnManager& turnManager,Character& characterToAttack,Score& score);

	Character& characterToAttack;

	int randomChoice;

	Score& score;

	GameHUD* gameHud;
	

	void StartTurn() override;
	void OnDead() override;
	void SetHUD(GameHUD* gameHud);

	~Enemy();
};

