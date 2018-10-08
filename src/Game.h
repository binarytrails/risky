//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include "Window.h"

using namespace std;

class Game
{
    public:
        enum State {
            RUNNING, PAUSED, TERMINATED
        };

        Game();
        ~Game();

        bool init_ui();
        void play();

    private:
        Game::State state;

        Window* window;
        SDL_Event* windowEvent;
};
