#include "../headers/GameWindow.h"

#define GameTITLE "Game"
#define GameWIDTH 1920
#define GameHEIGHT 1080

namespace UnderScoreGame::Engine
{
    GameWindow::GameWindow() 
    {
		// Create an SDL window that supports Vulkan rendering.
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			throw; //TODO: Fix that
		}

        Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE; //TODO load this from File

        this->window = SDL_CreateWindow(GameTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GameWIDTH, GameHEIGHT, windowFlags);
		if (this->window == NULL) {
			throw; //TODO: Fix that
		}

        this->glContext = SDL_GL_CreateContext(this->window);
    }
}