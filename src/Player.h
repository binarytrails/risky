//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // find
#include "Country.h"
#include "Card.h"
#include "PlayerDice.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"

using namespace std;

class Player
{
    public:
        enum Phase {
            REINFORCE, ATTACK, FORTIFY
        };

        Player(const string name);
        ~Player();

        string getName() const;

        void addCountry(Country* country);
        void removeCountry(Country* country);
        bool hasCountry(string name);
        Country* getCountry(string name);
        vector<Country*> getCountries() const;

        void addCard(Card* card);
        void removeCard(Card* card);
        vector<Card*> getCards() const;

        vector<int> rollDices(const int number);

        bool reinforce();
        bool attack(map *m);
        bool fortify(map *m);
        Player::Phase getActivePhase() const;

        friend ostream& operator<<(ostream &output, const Player &player);

    private:
        const string name;
        vector<Country*> countries;
        vector<Card*> cards;
        // Phase components
        Player::Phase activePhase;
        Country* sourceCountry;
        Country* targetCountry;
};

inline ostream& operator<<(ostream &output, const Player *player)
{
    output << "Player=" << player->getName() << ": ";
    output << "Cards={ ";
    for (Card* card: player->getCards())
        output << card->getTypeName() << " ";
    output << "} ";
    output << "Countries={ ";
    for (Country* country: player->getCountries())
        output << country->getName() << " ";
    output << "}";
    return output;
}
