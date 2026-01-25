#pragma once
#include <iostream>
#include <string>

class Scoreboard
{
private:
    std::string player1Score;
    std::string player2Score;

public:
    Scoreboard(std::string player1Score, std::string player2Score);

    void showScores(std::string player1Score, std::string player2Score);
};
