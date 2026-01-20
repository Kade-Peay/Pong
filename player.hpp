#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Player
{
private:
    int playerNum;
    int w;
    int h;
    int x;
    int y;
    int score;

public:
    Player(int playerNum, int w, int h, int x, int y); // Default to 0 score

    // Getters 
    int getW();
    int getH();
    int getX();
    int getY();
    int getScore();

    void moveUp();
    void moveDown();
    void drawPlayer(SDL_Renderer *renderer);
    void updateScore();
};
