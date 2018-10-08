//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include "Player.h"
#include "Country.h"
#include "Card.h"

using namespace std;

int main(int args, char* argv[])
{
    Player* player1 = new Player("FooBar");

    // 1. Player owns a collection of countries
    Country* usa = new Country("USA");
    Country* canada = new Country("CA");

    player1->addCountry(usa);
    cout << player1 << endl;

    player1->addCountry(canada);
    cout << player1 << endl;

    player1->removeCountry(usa);
    cout << player1 << endl;

    // 2. Player owns a hand of Risk cards
    Card* card1 = new Card("Infantry");
    Card* card2 = new Card("Cavalry");

    player1->addCard(card1);
    cout << player1 << endl;

    player1->addCard(card2);
    cout << player1 << endl;

    player1->removeCard(card1);
    cout << player1 << endl;

    // 3. Player has his own dice rolling facility object
    // 1-3 dices per roll

    // 4. Player must implement reinforce(), attack(), fortify()
    player1->reinforce();
    player1->attack();
    player1->fortify();

    delete player1;
    return 0;
}
