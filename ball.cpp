#include "ball.hpp"

Ball::Ball(int w, int r, int x, int y)
{
    this->w = w;
    this->r = r;
    this->x = x;
    this->y = y;
}

int Ball::getW()
{
    return this->w;
}

int Ball::getR()
{
    return this->r;
}

int Ball::getX()
{
    return this->x;
}

int Ball::getY()
{
    return this->y;
}

void Ball::drawBall(SDL_Renderer *renderer)
{
    // Set ball color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Draw the ball as a filled circle
    for (int w = 0; w < this->w; w++)
    {
        for (int h = 0; h < this->w; h++)
        {
            int dx = this->w / 2 - w; // horizontal offset
            int dy = this->w / 2 - h; // vertical offset
            if ((dx * dx + dy * dy) <= (this->r * this->r))
            {
                SDL_RenderDrawPoint(renderer, this->x + dx, this->y + dy);
            }
        }
    }
}

void Ball::updatePosition(int deltaX, int deltaY)
{
    this->x += deltaX;
    this->y += deltaY;
}
