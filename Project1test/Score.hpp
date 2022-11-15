#pragma once
#include "Project1test/ScoreButton.hpp"
#include <stdio.h>
#include <fstream>
#include <string>
class Score 
{

	
public:

	
	Score();
	~Score();

	unsigned int score;
	unsigned int highscores[10];
	
	//std::fstream inputFile(std::string);

	void UpdateScore();
	int GetScore();

	void WriteReadHighscores();

	std::string ReadFile();

	void ReplaceHighscoreFile();

};

