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

    Continent* america = new Continent("America");
    Continent* southAmerica = new Continent("South America");
    Country* usa = new Country("USA");
    Country* canada = new Country("CA");
    Player* player1 = new Player("FooBar");

    // 0. Country is owned by a player
    player1->addCountry(usa);
    cout << player1 << endl;
    player1->addCountry(canada);
    cout << player1 << endl;

    // 0. Country contain a number of armies.
    usa->setArmies(2);
    cout << usa << endl;
    canada->setArmies(3);
    cout << canada << endl;

    // 1. Map is connected graph
    cout << "Testing a valid map..." << endl;
    int nbOfNodes = 2;
    // contains g0 as Graph* map
    Map* map = new Map(nbOfNodes);

    // 2. Continents are connected subgraph
    //    Returns g1 for Graph* continent (subgraph of g0)
    Map::Graph& g1 = map->addContinent(america);
    // node1 of subgraph g1
    const int node1 = map->addCountry(canada, g1);
    // node2 of subgraph g1
    const int node2 = map->addCountry(usa, g1);
    cout << "Nodes: Canada=" << node1 << " USA=" << node2 << endl;
    // connect node1 to node2
    map->connectCountries(node1, node2, g1);
    map->print();

    // 3. Each country belongs to one and only one continent
    cout << "Trying to add Canada to South America..." << endl;
    // Country belongs to one and only continent
    Map::Graph& g2 = map->addContinent(southAmerica);
    map->addCountry(canada, g2);
    map->print();

    return 0;
}
