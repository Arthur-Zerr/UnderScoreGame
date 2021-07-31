#include "../Core/CoreWindow.hpp"
#include "../Logger/Logger.hpp"

#include <iostream>

#include "../../thirdparty/include/SDL2/SDL.h"
#include "../../thirdparty/include/SDL2/SDL_opengl.h"

#define TITLE "GameEngine"
#define WIDTH 1920
#define HEIGHT 1080

#ifndef __SDLWINDOW_H__
#define __SDLWINDOW_H__


namespace UnderScore::Engine::Window 
{
    class SDLWindow : public UnderScore::Engine::Core::CoreWindow 
    {
        public:
        SDL_Window* window;
		SDL_GLContext glContext;
        UnderScore::Engine::Core::CoreRender render;

        void SetCoreRender(UnderScore::Engine::Core::CoreRender& render) override
        {
            this->render = render;
        }

        void InitSDLWindow() 
        {
            std::cout << "Init" << std::endl;
            if(SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                UnderScore::Engine::Logger::Logger::GetInstance().logError("Failed to initialize the SDL2 library");
                throw;
            }

            Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE; //TODO load this from File

            SDL_Window* window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, windowFlags);
            if (window == NULL) {
                UnderScore::Engine::Logger::Logger::GetInstance().logError("Could not create SDL window.");
                throw; //TODO: Fix that
            }
            SDL_GL_SetSwapInterval(1);  



            glContext = SDL_GL_CreateContext(window);
        }

        void Init(void) override
        {
            UnderScore::Engine::Logger::Logger::GetInstance().logDebug("Using SDL");
            InitSDLWindow();
            UnderScore::Engine::Logger::Logger::GetInstance().logDebug("Init Renderer");
            this->render.Init();

            Uint64 NOW = SDL_GetPerformanceCounter();
            Uint64 LAST = 0;
            double deltaTime = 0;
            bool stillRunning = true;
            while (stillRunning) 
            {
                LAST = NOW;
                NOW = SDL_GetPerformanceCounter();

                deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

                SDL_Event event;
                while (SDL_PollEvent(&event)) 
                {
                    switch (event.type) {
                        case SDL_QUIT:
                            stillRunning = false;
                            break;

                        default:
                            // Do nothing.
                            break;
                    }
                }
                Render();
                Update(deltaTime);
                SDL_GL_SwapWindow(window);
            }
            Dispose();
        }

        void Render(void) override
        {
            this->render.Render();
        }

        void Update(double delta) override 
        {
            this->render.Update(delta);
        }

        void Dispose(void) override 
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    };
}
#endif // __SDLWINDOW_H__