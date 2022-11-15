#include "character.hpp"

#include <algorithm>
#include <random>
#include "Project1test/TurnManager.hpp"
#include <iostream>

Character::Character(std::string name, std::string spriteFile, int hp, int attack, int defense,TurnManager& turnManager) :
	name(name), spriteFile(spriteFile), hp(hp), attack(attack), defense(defense),turnManager(turnManager),spriteObject(name,spriteFile), lastSpriteIndex(-1)
{ 
	
}

Character::~Character() {
	
}

int Character::attackCharacter(Character& character) const {
	//Just a random function

	//attack + 0~3 
	int attackPower = attack + std::rand() % 4 + 7; 
	// defense + -1~1
	int defensePower = character.getDefense() + (-1 + std::rand() % 3);

	int damageToDeal = std::max(attackPower - defensePower, 0);
	

	character.takeDamage(damageToDeal);

	return damageToDeal;
}

bool Character::takeDamage(int damage) {
	hp = std::max(hp - damage, 0);
	if (isDead()) 
	{
		OnDead();
	}
	return isDead();
}

int Character::getAttack() const {
	return this->attack;
}

void Character::setAttack(int attack) {
	this->attack = attack;
}

int Character::getDefense() const {
	return this->defense;
}

int Character::getHP() const {
	return this->hp;
}

std::string Character::getName() const {
	return this->name;
}

std::string Character::getSpriteFile() const {
	return this->spriteFile;
}

std::string Character::GetStatsString()
{
	return 
		"Attack: " + std::to_string(getAttack()) + '\n' +
		"Defense: " + std::to_string(getDefense()) + '\n' +
		"Health: " + std::to_string(getHP()) + '\n';
}



int Character::GetAmountAttack(int damageAmount) 
{
	return damageAmount;
}



void Character::setDefense(int defense) {
	this->defense = defense;
}

void Character::setHP(int hp) {
	this->hp = hp;
}
void Character::AddHp(int howMuchHp) {
	hp += howMuchHp;
}
void Character::AddDefense(int howMuchDefense) {
	defense += howMuchDefense;
}
void Character::setName(std::string name) {
	this->name = name;
}
void Character::ResetStats()
{
	hp = rand() % 10 + 1;
	defense = rand() % 10 + 1;
	attack = rand() % 10 + 1;

	std::cout << hp << "\n";
	std::cout << defense << "\n";
	std::cout << attack << "\n";
}

SpriteObject& Character::GetSpriteObject() {
	return spriteObject;
}

void Character::EndTurn() 
{
	turnManager.EndTurn();
}
void Character::OnDead() {}

void Character::SetRandomSprite() 
{
	int spriteIndex = -1;

	do 
	{
		spriteIndex = rand() % SpriteVector.size();
	} while (spriteIndex == lastSpriteIndex);

	spriteObject.SetSpriteFile(SpriteVector[spriteIndex]);
	lastSpriteIndex = spriteIndex;
}

