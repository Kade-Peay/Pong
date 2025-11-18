#include "player.hpp"

Player::Player(int playerNum, int w, int h, int x, int y)
{
    this->playerNum = playerNum;
    this->w = w;
    this->h = h;
    this->x = x;
    this->y = y;
}

void Player::moveUp()
{
    // Moving up should decrease the y coordinate in SDL's coordinate system
    this->y -= 20;
}

void Player::moveDown()
{
    // Moving down should increase the y coordinate
    this->y += 20;
}

void Player::drawPlayer(SDL_Renderer *renderer)
{
    SDL_Rect box;
    box.w = this->w;
    box.h = this->h;
    box.x = this->x;
    box.y = this->y;
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &box);
}