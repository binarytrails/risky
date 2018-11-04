#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <regex>
#include "Map.h"

using namespace std;

class MapReader
{
    public:
        bool read(string mapFile);
        int getNbOfNodes();
        void load(Map &map);

    private:
        vector<string> continents;
        vector<string> territories;

        void readTerritories(ifstream* territories);
        void readContinents(ifstream* territories);
        map<int, string> createTerritoriesTranslatorMapNtS(vector<string> const &terrVector);
        map<string, int> createTerritoriesTranslatorMapStN(vector<string> const &terrVector);
        void addEdge(vector<vector<int>> &adj, int u, int v);
        void printGraph(vector<vector<int>> adj, int V, map<int, string> &mapNtS);
        void graphmaker(vector<string>  &terrVector, map<string, int>  &mapStN, map<int, string> &mapNtS);
};
