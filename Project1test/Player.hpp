#pragma once

#include "spriteObject.hpp"
#include "character.hpp"
#include "textObject.hpp"

class Player : public Character
{
public:
	Player(TurnManager& turnManager);
	void StartTurn() override;
	
	
	~Player();

private:
	
};

