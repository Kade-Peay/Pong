#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Ball
{
private:
    int w;
    int r;
    int x;
    int y;

public:
    Ball(int w, int r, int x, int y);

    // Getters
    int getW();
    int getR();
    int getX();
    int getY();

    // Setters
    int setX(int x);
    int setY(int y);

    void drawBall(SDL_Renderer *renderer);
    void updatePosition(int deltaX, int deltaY);
};
