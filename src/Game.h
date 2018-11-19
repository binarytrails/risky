//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <spdlog/logger.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "MapReader.h"
#include "Deck.h"
#include "PhaseObserver.h"

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

        void play();
        bool addPlayer(Player *player);

        void attach(PhaseObserver* observer);
        void detach(PhaseObserver* obsrever);
        void notify();

    private:
        Game::UI ui;
        Game::State state;
        // Components
        Map* map;
        Deck* deck;
        Player *activePlayer;
        vector<Player*> players;
        list<PhaseObserver*> phaseObservers;
        // SDL2 UI
        Window* window;
        SDL_Event* windowEvent;
        // Logging
        const string logname;
        stringstream logbuf;
        std::shared_ptr<spdlog::logger> logger;

        // SDL2 UI
        bool sdl2_init();
        void sdl2_poll();
        // SHELL UI
        bool shell_init();
        bool shell_start();
};
