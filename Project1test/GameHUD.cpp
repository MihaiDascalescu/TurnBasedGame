#include "GameHUD.hpp"
#include <iostream>
#include <random>
#include "Project1test/TurnManager.hpp"

GameHUD::GameHUD(Player& player, Enemy& enemy, sf::Font& font, SceneHandler& sceneHandler, Score& score,sf::Color& darkColor) : GameObject("HUD"),
AttackButton("Attack Button", font, "Attack", sf::Vector2f(100, 100), darkColor),
DefenseButton("Defense Button", font, "Defend", sf::Vector2f(100, 100), darkColor),
HealButton("Heal Button", font, "Heal", sf::Vector2f(100, 100), darkColor),
BackToMenuButton("Back To Menu Button", font, "Quit", sf::Vector2f(100, 100), darkColor),
player(player),
enemy(enemy),
sceneHandler(sceneHandler),
HasPlayerDiedLastFrame(false),
playerStats("playerText", font, ""),
enemyStats("enemyText", font, ""),
PlayerTurnResultText("playerTurnResultText", font, ""),
EnemyTurnResultText("enemyTurnResultText", font, ""),

score(score)

{
	AttackButton.setPosition(sf::Vector2f(600, 300));
	DefenseButton.setPosition(sf::Vector2f(600, 400));
	HealButton.setPosition(sf::Vector2f(600, 500));
	BackToMenuButton.setPosition(sf::Vector2f(1000, 600));

	AttackButton.setButtonAction([this] {  onAttackClicked(); });
	DefenseButton.setButtonAction([this] { onDefenseClicked(); });
	HealButton.setButtonAction([this] { onHealClicked(); });
	BackToMenuButton.setButtonAction([this] { onBackToMenuClicked(); });

	playerStats.setPosition(sf::Vector2f(148.0f, 290.0f));
	playerStats.setCharacterSize(26);
	playerStats.setFillColor(darkColor);

	enemyStats.setPosition(sf::Vector2f(1050.0f, 290.0f));
	enemyStats.setCharacterSize(26);
	enemyStats.setFillColor(darkColor);

	PlayerTurnResultText.setPosition(sf::Vector2f(0, 0));
	PlayerTurnResultText.setCharacterSize(26);
	PlayerTurnResultText.setFillColor(darkColor);


	EnemyTurnResultText.setPosition(sf::Vector2f(800, 0));
	EnemyTurnResultText.setCharacterSize(26);
	EnemyTurnResultText.setFillColor(darkColor);

	enemy.SetHUD(this);


}

void GameHUD::update()
{
	if (player.isDead())
	{
		if(!HasPlayerDiedLastFrame)
		{
			
			HasPlayerDiedLastFrame = true;
			onPlayerDied();
		}

		return;
	}

	updateText();
	
	
	bool isPlayerTurn = player.turnManager.currentCharacter == &player;

	AttackButton.setInteractable(isPlayerTurn);
	DefenseButton.setInteractable(isPlayerTurn);
	HealButton.setInteractable(isPlayerTurn);
}

void GameHUD::render(sf::RenderWindow & window)
{
	AttackButton.render(window);
	DefenseButton.render(window);
	HealButton.render(window);
	
}

void GameHUD::AddUIToScene(Scene & scene)
{
	scene.addGameObject(AttackButton);
	scene.addGameObject(DefenseButton);
	scene.addGameObject(HealButton);
	scene.addGameObject(playerStats);
	scene.addGameObject(enemyStats);
	scene.addGameObject(PlayerTurnResultText);
	scene.addGameObject(EnemyTurnResultText);
	
}

TextObject & GameHUD::getTurnResultText()
{
	return EnemyTurnResultText;
}


void GameHUD::onAttackClicked()
{
	int damageDealt = player.attackCharacter(enemy);
	
	
	PlayerTurnResultText.setText("You attacked enemy for " + std::to_string(damageDealt));
	
	
	// Update damage dealt text object
	
	player.turnManager.EndTurn();
	enemy.turnManager.StartTurn(); //enemy start its turn as soon as the player ends its turn
	
	
}

void GameHUD::onDefenseClicked()
{
	int defenseAdded = rand() % 10 + 1;
	player.AddDefense(defenseAdded);
	PlayerTurnResultText.setText("You increased your defense by " + std::to_string(defenseAdded));
	
	player.turnManager.EndTurn();
	enemy.turnManager.StartTurn();

}

void GameHUD::onHealClicked()
{
	int healAdded = rand() % 10 + 1;
	player.AddHp(healAdded);
	PlayerTurnResultText.setText("You increased your health by " + std::to_string(healAdded));
	
	player.turnManager.EndTurn();
	enemy.turnManager.StartTurn();
	
}
void GameHUD::onBackToMenuClicked()
{
	reset();
	
	// There is no way to set the current scene explicitly.
	// The top scene when the hud is running is the game screen, and right under it is the menu screen, so we pop the game screen to go back.
	sceneHandler.popScene();
}

void GameHUD::displayActions()
{
	
}

void GameHUD::updateText()
{
	playerStats.setText(player.GetStatsString());
	enemyStats.setText(enemy.GetStatsString());
	
}

void GameHUD::onPlayerDied()
{
	updateText();
	AttackButton.setInteractable(false);
	DefenseButton.setInteractable(false);
	HealButton.setInteractable(false);
	
	sceneHandler.getCurrentScene()->addGameObject(BackToMenuButton);
}

void GameHUD::reset()
{
	
	player.ResetStats();
	enemy.ResetStats();
	PlayerTurnResultText.setText("");
	EnemyTurnResultText.setText("");
	sceneHandler.getCurrentScene()->removeGameObject(BackToMenuButton);
	HasPlayerDiedLastFrame = false;
	score.WriteReadHighscores();
	score.score = 0;
}

