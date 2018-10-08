//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include "Player.h"
#include "Country.h"
#include "Card.h"

using namespace std;

int main(int args, char* argv[])
{
    Player* player1 = new Player();

    // 1. Player owns a collection of countries
    Country* usa = new Country();
    Country* canada = new Country();
    player1->addCountry(usa);
    player1->addCountry(canada);
    //TODO cout

    // 2. Player owns a hand of Risk cards
    Card* card1 = new Card();
    Card* card2 = new Card();
    player1->addCard(card1);
    player1->addCard(card2);
    //TODO cout

    // 3. Player has his own dice rolling facility object
    // 1-3 dices per roll

    // 4. Player must implement reinforce(), attack(), fortify()

    delete player1;
    return 0;
}
