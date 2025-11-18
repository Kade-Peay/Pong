#include "ball.hpp"

Ball::Ball(int w, int r, int x, int y)
{
    this->w = w;
    this->r = r;
    this->x = x;
    this->y = y;
}

void Ball::drawBall(SDL_Renderer *renderer)
{
    int diameter = (this->r * 2);

    int x = (this->r - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (this->x >= this->y)
    {
        SDL_RenderDrawPoint(renderer, this->x + x, this->y - y);
        SDL_RenderDrawPoint(renderer, this->x + x, this->y + y);
        SDL_RenderDrawPoint(renderer, this->x - x, this->y - y);
        SDL_RenderDrawPoint(renderer, this->x - x, this->y + y);
        SDL_RenderDrawPoint(renderer, this->x + y, this->y - x);
        SDL_RenderDrawPoint(renderer, this->x + y, this->y + x);
        SDL_RenderDrawPoint(renderer, this->x - y, this->y - x);
        SDL_RenderDrawPoint(renderer, this->x - y, this->y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}