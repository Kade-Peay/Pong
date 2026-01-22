#include "scoreboard.hpp"

Scoreboard::Scoreboard(std::string player1Score, std::string player2Score)
{
    this->player1Score = player1Score;
    this->player2Score = player2Score;
}

void showScores(std::string player1Score, std::string player2Score) 
{
    std::cout << "Player 1: " << player1Score << std::endl << "Player 2: " << player2Score << std::endl;
}
