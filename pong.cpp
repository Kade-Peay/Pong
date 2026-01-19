#include <iostream>
#include <SDL2/SDL.h>
#include "player.hpp"
#include "ball.hpp"

int main(int argc, char *args[])
{
    // Just print something to the screen so I know it is working
    std::cout << "Starting..." << std::endl;

    // A lot of initializing...
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Create Players
    Player player1(1, 20, 100, 40, 190);
    Player player2(2, 20, 100, 580, 190);

    // Create the Ball
    Ball ball(20, 5, 320, 240);

    // Update positions for X and Y
    int dX = 2; // Start with moving to the right
    int dY = 1; // Small downward angle as well

    // Start the main loop
    bool running = true;
    while (running)
    {

        // Clear the screen with black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Handle events
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (SDL_QUIT == ev.type)
            {
                running = false;
                break;
            }
            else if (ev.type == SDL_KEYDOWN)
            {
                switch (ev.key.keysym.sym)
                {
                case SDLK_w:
                    player1.moveUp();
                    break;
                case SDLK_s:
                    player1.moveDown();
                    break;
                case SDLK_i:
                    player2.moveUp();
                    break;
                case SDLK_k:
                    player2.moveDown();
                    break;
                default:
                    break;
                }
            }
        }

        // Draw the ball
        ball.drawBall(renderer);

        // Draw at end of frame
        player1.drawPlayer(renderer);
        player2.drawPlayer(renderer);

        // Check for wall collisions
        if (ball.getX() < 0 || ball.getX() >= 640)
        { // Horizontal
            dX *= -1;
        }
        if (ball.getY() < 0 || ball.getY() >= 480)
        { // Vertical
            dY *= -1;
        }

        // Check for Paddle Collisions
        if (ball.getX() <= player1.getX() + player1.getW() &&
            ball.getY() + ball.getW() >= player1.getY() &&
            ball.getY() <= player1.getY() + player1.getH())
        {
            dX *= -1;
        }
        if (ball.getX() + ball.getW() >= player2.getX() + player2.getW() && // Adjust by width for rendering
            ball.getY() + ball.getW() >= player2.getY() &&
            ball.getY() <= player2.getY() + player2.getH())
        {
            dX *= -1;
        }

        // Update Ball position
        ball.updatePosition(dX, dY);

        // Show the new frame
        SDL_RenderPresent(renderer);

    } // End while

    return 0;
}
