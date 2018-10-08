//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <vector>
#include "Country.h"
#include "Card.h"
#include "Dice.h"

using namespace std;

class Player
{
    public:
        Player();
        ~Player();

        int rollDice();

        bool reinforce();
        bool attack();
        bool fortify();

    private:
        vector<Country*> countries;
        vector<Card*> cardsHand;
};
