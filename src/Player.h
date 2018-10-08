//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <vector>
#include <algorithm> // find
#include "Country.h"
#include "Card.h"
#include "Dice.h"

using namespace std;

class Player
{
    public:
        Player();
        ~Player();

        void addCountry(Country* country);
        void removeCountry(Country* country);
        void addCard(Card* card);
        void removeCard(Card* card);

        int rollDice();

        bool reinforce();
        bool attack();
        bool fortify();

    private:
        vector<Country*> countries;
        vector<Card*> cardsHand;
};
