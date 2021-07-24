#include <SDL2/SDL.h>

#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

namespace UnderScoreGame::Engine
{
    class GameWindow
    {
        public: 
            SDL_Window* window;
            SDL_GLContext glContext;

            GameWindow();
	};
}

#endif // __GAMEWINDOW_H__