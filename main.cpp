#define GL_SILENCE_DEPRECATION 

#include <iostream>

#include "src/Engine/Core/CoreWindow.hpp"
#include "src/Engine/Window/GLFWWindow.hpp"

int main(void)
{

    UnderScore::Engine::Core::CoreWindow window = UnderScore::Engine::Window::GLFWWindow();
    window.Init();

    std::cout << "TEst" << std::endl;
    return 0;
}