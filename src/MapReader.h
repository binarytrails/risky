#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <regex>
#include "Map.h"
#include "Continent.h"

using namespace std;

class MapReader
{
    public:
        bool read(string mapFile);
        int getNbOfNodes();
        void load(Map &map);

    private:
        vector<string> contLines;
        vector<string> terrLines;

        void readTerritories(ifstream* territories);
        void readContinents(ifstream* territories);
};
