//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Player.h"

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
        bool addPlayer(Player *player);

    private:
        Game::State state;
        vector<Player*> players;

        Window* window;
        SDL_Event* windowEvent;
};
