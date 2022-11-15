#pragma once
#include <vector>

class Character;

class TurnManager 
{
private:
	std::vector<Character*> characterList;
	unsigned int currentCharacterIndex;
public:
	TurnManager();
	
	Character* currentCharacter;

	void StartTurn();
	void AddCharacterToTurnList(Character& character); 
	void EndTurn();

	~TurnManager();

};

