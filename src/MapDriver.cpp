//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include <vector>
#include "Map.h"
#include "Country.h"

using namespace std;

int main()
{
    cout << "Map Driver..." << endl;
    Map *map = new Map();


    // 3. Country is owned by a player and contain a number of armies.
    Country* usa = new Country("USA");
    Country* canada = new Country("CA");

    usa->setArmies(2);
    cout << usa << endl;
    canada->setArmies(3);
    cout << canada << endl;

    delete map;
    return 0;
}
