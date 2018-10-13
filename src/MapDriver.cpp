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
    Continent* america = new Continent("America");
    Country* usa = new Country("USA", america);
    Country* canada = new Country("CA", america);
    Country* mexico = new Country("MX", america);
    Player* player1 = new Player("FooBar");

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
    Map::Node v1 = map->addNode(*usa);
    Map::Node v2 = map->addNode(*canada);
    Map::Node v3 = map->addNode(*mexico);
    map->addEdge(v1, v2, Map::Edge(*usa, *canada));
    map->addEdge(v1, v3, Map::Edge(*usa, *mexico));
    map->print();

    // Continents are connected subgraph

    // Country belongs to one and only continent


    delete america;
    delete usa;
    delete canada;
    delete mexico;
    delete player1;
    delete map;
    return 0;
}
