#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <utility>
#include <string>
#include "player.hpp"
#include "ball.hpp"
#include "scoreboard.hpp"

int main(int argc, char *args[])
{
    // Just print something to the screen so I know it is working
    std::cout << "Starting..." << std::endl;

    // Screen Size
    const int screenW = 640;
    const int screenH = 480;
    const int fontSize = 10;

    // A lot of initializing...
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Import font
    TTF_Font* font = TTF_OpenFont("Ithaca-LVB75.ttf", fontSize);
    if(!font) 
    {   
        std::cout << "No font found, brother." << std::endl;
    }
    SDL_Color textColor = {255, 255, 255, 255}; // White

    // Create Players
    Player player1(1, 20, 100, 40, 190);
    Player player2(2, 20, 100, 580, 190);

    // Create the Ball
    int ballStartingX = screenW / 2;
    int ballStartingY = screenH / 2;
    Ball ball(20, 5, ballStartingX, ballStartingY);

    // Update positions for X and Y
    std::pair<float, float> direction = {2.0f, 1.0f};

    // Create the scoreboard
    Scoreboard scoreboard("0", "0");

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
        if (ball.getY() < 0 || ball.getY() >= screenH)
        {
            direction.second *= -1.0f;
        }

        //
        // Update scores if making it past the paddle
        // Change direction of ball depending on who makes the point
        if (ball.getX() < 0) // Left side (Player 2 point)
        {
            player2.updateScore();
            if(player2.getScore() >= 5) 
            {
                std::cout << "Player 2 Wins!!" << std::endl;
                running = false;
                break;
            }
            else
            { 
                scoreboard.showScores(std::to_string(player1.getScore()), std::to_string(player2.getScore()));
            }

            // Reset Ball position
            ball.setX(ballStartingX);
            ball.setY(ballStartingY);
            direction.first = 2.0f;
            direction.second = 1.0f;
        }
        if (ball.getX() >= screenW) // Right side (Player 1 point)
        {
            player1.updateScore();
            if(player1.getScore() >= 5)
            {   
                std::cout << "Player 1 Wins!!" << std::endl;
                running = false;
                break;
            }
            else    
            {
                scoreboard.showScores(std::to_string(player1.getScore()), std::to_string(player2.getScore()));
            }

            // Reset Ball position
            ball.setX(ballStartingX);
            ball.setY(ballStartingY);
            direction.first = -2.0f;
            direction.second = 1.0f;
        }

        // Check for Paddle Collisions
        // TODO: Ball occasionally gets stuck behind paddle
        if (ball.getX() <= player1.getX() + player1.getW() &&
            ball.getY() + ball.getW() >= player1.getY() &&
            ball.getY() <= player1.getY() + player1.getH())
        {
            direction.first -= 0.2f;
            direction.second -= 0.01f;
            direction.first *= -1.0f;

            // std::cout << "New direction: " << std::to_string(direction.first) << ", " << std::to_string(direction.second) << std::endl;
        }
        if (ball.getX() + ball.getW() >= player2.getX() + player2.getW() && // Adjust by width for rendering
            ball.getY() + ball.getW() >= player2.getY() &&
            ball.getY() <= player2.getY() + player2.getH())
        {
            direction.first += 0.2f;
            direction.second += 0.01f;
            direction.first *= -1.0f;

            // std::cout << "New direction: " << std::to_string(direction.first) << ", " << std::to_string(direction.second) << std::endl;
        }

        // Update Ball position
        ball.updatePosition(direction.first, direction.second);

       
        // Show the new frame
        SDL_RenderPresent(renderer);


    } // End while

    return 0;
}
