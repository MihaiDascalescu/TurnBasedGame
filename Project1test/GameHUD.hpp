#pragma once
#include "gameObject.hpp"
#include "button.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "sceneHandler.hpp"
#include "textObject.hpp"
#include "Score.hpp"

class GameHUD : public GameObject
{
public:
	GameHUD(Player& player, Enemy& enemy, sf::Font& font,SceneHandler& sceneHandler,Score& score,sf::Color& darkColor);

	Button AttackButton;
	Button DefenseButton;
	Button HealButton;
	Button BackToMenuButton;

	Player& player;
	Enemy& enemy;

	SceneHandler& sceneHandler;

	TextObject playerStats;
	TextObject enemyStats;
	
	TextObject PlayerTurnResultText;
	TextObject EnemyTurnResultText;
	


	Score& score;

	void update() override;
	void render(sf::RenderWindow& window) override;

	void AddUIToScene(Scene& scene);

	TextObject& getTurnResultText();

private:
	bool HasPlayerDiedLastFrame;

	void onAttackClicked();
	void onDefenseClicked();
	void onHealClicked();
	void onBackToMenuClicked();

	void displayActions();

	void updateText();

	void onPlayerDied();

	void reset();
};

