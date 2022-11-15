#include "TurnManager.hpp"
#include "character.hpp"


TurnManager::TurnManager() 
{
	
}
void TurnManager::StartTurn() 
{
	currentCharacter->StartTurn();
}
void TurnManager::EndTurn()
{
	currentCharacterIndex = (currentCharacterIndex + 1) % characterList.size();
	currentCharacter = characterList[currentCharacterIndex];
}
void TurnManager::AddCharacterToTurnList(Character& character) 
{
	this->characterList.push_back(&character);
	
	if (currentCharacter == nullptr)
	{
		currentCharacter = &character;
	}
}

TurnManager::~TurnManager()
{
}
