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
        vector<Country*> getCountries() const;

        void addCard(Card* card);
        void removeCard(Card* card);
        vector<Card*> getCards() const;

        vector<int> rollDices(const int number);

        bool reinforce();
        bool attack();
        bool fortify();
        Player::Phase getActivePhase() const;

        friend ostream& operator<<(ostream &output, const Player &player);

    private:
        const string name;
        vector<Country*> countries;
        vector<Card*> cards;
        //map<Country*, nbOfArmies...
        Player::Phase activePhase;
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
