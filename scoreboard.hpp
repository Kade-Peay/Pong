#pragma once
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
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
