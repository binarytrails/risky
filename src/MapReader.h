#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <regex>
#include <boost/filesystem.hpp>
#include "Map.h"
#include "Continent.h"

using namespace std;

class MapReader
{
    public:
        bool read(string mapFile);
        int getNbOfNodes();
        void load(Map &map);
        void printMaps(string dirpath) const;

    private:
        vector<string> contLines;
        vector<string> terrLines;

        void readTerritories(ifstream &in);
        void readContinents(ifstream &in);
};
