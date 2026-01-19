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

public:
    Player(int playerNum, int w, int h, int x, int y);

    // Getters 
    int getW();
    int getH();
    int getX();
    int getY();

    void moveUp();
    void moveDown();
    void drawPlayer(SDL_Renderer *renderer);
};
