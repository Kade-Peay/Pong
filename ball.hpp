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

    void drawBall(SDL_Renderer *renderer);
};