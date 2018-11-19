//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include "Game.h"
#include "Player.h"

using namespace std;

class Game; // forward declaration

class PhaseObserver
{
    public:
        PhaseObserver(int id, Game *subject);
        ~PhaseObserver();

        int getId() const;
        void update();

    private:
        int id;
        Game *subject;
};
