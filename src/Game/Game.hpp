#include <iostream>
#include <SDL2/SDL_opengl.h>

#include "../Engine/Core/CoreRender.hpp"
#include "../Engine/Logger/Logger.hpp"

namespace UnderScore::Game 
{
    class Game : public UnderScore::Engine::Core::CoreRender
    {
        void Init() override 
        {
            UnderScore::Engine::Logger::Logger::GetInstance().logInfo("Init Game Renderer");
            std::cout << "Init Game Renderer" << std::endl;;
        }

        void Render() override 
        {
            glClearColor(0.f, 1.f, 0.f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT);

            glBegin(GL_TRIANGLES);
            glColor3f(0.1f, 0.2f, 0.3f);
            glVertex3f(-0.5f, -0.5f, 0);
            glVertex3f(0.5f, -0.5f, 0);
            glVertex3f(0, 0.5f, 0);
            glEnd();
        }

        void Update(double delta) override 
        {

        }
    };
}

