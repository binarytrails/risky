//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

int main()
{
    cout << "Map Driver..." << endl;
    Map *map = new Map();

    delete map;
    return 0;
}
