//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include <vector>
#include "Map.h"
#include "Continent.h"
#include "Country.h"
#include "Player.h"

using namespace std;

int main()
{
    cout << "Map Driver..." << endl;

    // Country is owned by a player and contain a number of armies.
    Player* player1 = new Player("FooBar");
    Continent* america = new Continent("America");
    Country* usa = new Country("USA", america);
    Country* canada = new Country("CA", america);

    player1->addCountry(usa);
    cout << player1 << endl;
    player1->addCountry(canada);
    cout << player1 << endl;

    usa->setArmies(2);
    cout << usa << endl;
    canada->setArmies(3);
    cout << canada << endl;

    // Map is connected graph
    Map *map = new Map();


    // Continents are connected subgraph

    // Country belongs to one and only continent


    delete map;
    return 0;
}
