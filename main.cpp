#define GL_SILENCE_DEPRECATION 
#define SDL_MAIN_HANDLED

#include <iostream>

#include "src/Engine/Core/CoreRender.hpp"

#include "src/Engine/Window/SDLWindow.hpp"

#include "src/Game/Game.hpp"

int main(void)
{
    UnderScore::Engine::Window::SDLWindow window =  UnderScore::Engine::Window::SDLWindow();
    UnderScore::Engine::Core::CoreRender *game = new UnderScore::Game::Game();

    window.SetCoreRender(game);

    window.Init();
    return 0;
}