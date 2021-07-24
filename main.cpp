#define SDL_MAIN_HANDLED

#include <iostream>

#include "src/headers/GameWindow.h"

int main() 
{
    UnderScoreGame::Engine::GameWindow gameWindow = UnderScoreGame::Engine::GameWindow();
    
    std::cout << "Test" << std::endl;

    
    bool stillRunning = true;
    while (stillRunning) {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            switch (event.type) {

            case SDL_QUIT:
                stillRunning = false;
                break;

            default:
                // Do nothing.
                break;
            }


            SDL_GL_SwapWindow(gameWindow.window);
        }

        SDL_Delay(10);
    }

    // Clean up.
    SDL_DestroyWindow(gameWindow.window);
    SDL_Quit();
    
    return 0;
}