//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // find
#include "Country.h"
#include "Card.h"
#include "Dice.h"

using namespace std;

class Player
{
    public:
        Player(const string name);
        ~Player();

        const string getName() const;

        void addCountry(Country* country);
        void removeCountry(Country* country);
        vector<Country*> getCountries() const;

        void addCard(Card* card);
        void removeCard(Card* card);
        vector<Card*> getCards() const;

        int rollDice();

        bool reinforce();
        bool attack();
        bool fortify();

        friend ostream& operator<<(ostream &output, const Player &player);

    private:
        const string name;
        vector<Country*> countries;
        vector<Card*> cards;
};

inline ostream& operator<<(ostream &output, const Player *player)
{
    output << player->getName() << ": ";
    output << "Cards={ ";
    for (Card* card: player->getCards())
        output << card->getName() << " ";
    output << "} ";
    output << "Countries={ ";
    for (Country* country: player->getCountries())
        output << country->getName() << " ";
    output << "}";
    return output;
}
