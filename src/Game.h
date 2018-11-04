//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "MapReader.h"

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
        Map* map;
        vector<Player*> players;

        Window* window;
        SDL_Event* windowEvent;

        bool start();
};
