#include "Score.hpp"

Score::Score()
{
	this->score = 0;
}
void Score::UpdateScore() {
	this->score = score+1;
}
std::string Score::ReadFile()
{
	int num = 1;
	std::string result;
	std::ifstream myfileRead("Highscore.cmgt");
	std::string line;
	while (std::getline(myfileRead, line)) {
		
		result.append("#" + std::to_string(num) + ": " + line + '\n'); num++;
	}
	myfileRead.close();
	return result;
}
void Score::ReplaceHighscoreFile()
{

	for (short int i = 0; i < 10; i++)
	{
		 highscores[i]=0;
	}

	std::ofstream outputFile("Highscore.cmgt", std::ios::trunc);
	for (short int i = 9; i >= 0; i--)
	{
		outputFile << highscores[i] << std::endl;
	}
	outputFile.close();
}

int Score::GetScore() {
	return score;
}
void Score::WriteReadHighscores() 
{
	
	std::fstream inputFile("Highscore.cmgt") ;
	for (short int i = 0; i < 10; i++)
	{	
		inputFile >> highscores[i];
	}
	inputFile.close();
	highscores[9] = score;
	std::sort(highscores, highscores + 11);

	std::ofstream outputFile("Highscore.cmgt",std::ios::trunc);
	for (short int i = 9; i >= 0; i--)
	{
		outputFile << highscores[i] << std::endl;
	}
	outputFile.close();
	
}
Score::~Score()
{

}

