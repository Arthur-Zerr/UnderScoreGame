#define GL_SILENCE_DEPRECATION 
#define SDL_MAIN_HANDLED
#include <iostream>

#include "src/Engine/Core/CoreWindow.hpp"
#include "src/Engine/Core/CoreRender.hpp"
#include "src/Engine/Window/GLFWWindow.hpp"
#include "src/Engine/Window/SDLWindow.hpp"

#include "src/Game/Game.hpp"

int main(void)
{
    #ifdef __APPLE__

    UnderScore::Engine::Window::GLFWWindow test =  UnderScore::Engine::Window::GLFWWindow();
    #elif _WIN32
    UnderScore::Engine::Window::SDLWindow test =  UnderScore::Engine::Window::SDLWindow();

    #endif


    UnderScore::Engine::Core::CoreWindow& window = test;
    UnderScore::Game::Game game();


    window.Init();
    window.SetCoreRender(&game);
    return 0;
}