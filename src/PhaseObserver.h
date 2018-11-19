//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <iostream>
#include "Player.h"

using namespace std;

class PhaseObserver
{
    public:
        PhaseObserver(int id);
        ~PhaseObserver();

        int getId() const;
        void update(Player *player);

    private:
        int id;
};
