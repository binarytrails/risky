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
        enum UI {
            SHELL, SDL2
        };
        enum State {
            RUN, PAUSE, HALT
        };

        Game(UI ui);
        ~Game();

        bool init_sdl2();
        void play();
        bool addPlayer(Player *player);

    private:
        Game::UI ui;
        Game::State state;
        vector<Player*> players;

        Window* window;
        SDL_Event* windowEvent;

        bool start();
};
