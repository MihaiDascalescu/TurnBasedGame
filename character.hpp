#pragma once

#include <string>
#include "spriteObject.hpp"

class TurnManager;

class Character {
    private:
        std::string name;
        std::string spriteFile;
        int hp;
        int attack;
        int defense;	
		int lastSpriteIndex;


protected:
		SpriteObject spriteObject;

		
		std::vector<std::string> SpriteVector;
	
    public:
		enum class GameState {
			Attack,
			Defense,
			Rest,
			Heal
		};
		void SetRandomSprite();
		GameState gameState;
        Character(std::string name, std::string spriteFile, 
                    int hp, int attack, int defense,TurnManager& turnManager);
        ~Character();

        int attackCharacter(Character& character) const;
        bool takeDamage(int damage);
		bool isDead() { return hp <= 0; }

        int getAttack() const;
        void setAttack(int attack);

        int getDefense() const;
        void setDefense(int defense);

        int getHP() const;
        void setHP(int hp);
		void AddHp(int howMuchHp);

		void AddDefense(int howMuchDefense);

		TurnManager& turnManager;

		virtual void StartTurn()=0;
		void EndTurn();

        std::string getName() const;
		
		
        void setName(std::string name);

		void ResetStats();

		virtual void OnDead();

	    SpriteObject& GetSpriteObject();

        std::string getSpriteFile() const;

		std::string GetStatsString();
		
		int GetAmountAttack(int damageAmount) ;
};


