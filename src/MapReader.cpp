// 345MapLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MapReader.h"

// Puts all the territories string in a vector
void MapReader::readTerritories(ifstream* territories) {

	string s;
	while (getline(*territories, s)) {
		if (s.empty())
            break;
	    this->territories.push_back(s);
	}
}

// Puts all the territories string in a vector
void MapReader::readContinents(ifstream* territories) {

	string s;
	while (getline(*territories, s)) {
		if (s.empty())
            break;
	    this->continents.push_back(s);
	}
}

//This method creates a map data structure to be able to translate int (from the graph implementation) to their corresponding strings (territories)
map<int, string> MapReader::createTerritoriesTranslatorMapNtS(vector<string> const &terrVector) {

	map<int, string> map1;


	int i = 0;
	int y = 0;
	string terr;

	while (i < terrVector.size()) {

		while (y < terrVector[i].size()) {
			if (terrVector[i][y] == ',') {
				break;
			}
			terr.push_back(terrVector[i][y]);
			y++;
		}
		map1.insert(pair<int, string>(i, terr));
		y = 0;
		terr = "";
		i++;
	}

	i = 0;
	while (i < terrVector.size()) {
		i++;
	}

	return map1;
}

//this methods creates a map data structure that translate String(terrories) to int, to store them in the graph implementation
map<string, int> MapReader::createTerritoriesTranslatorMapStN(vector<string> const &terrVector) {

	map<string, int> map1;


	int i = 0;
	int y = 0;
	string terr;

	while (i < terrVector.size()) {

		while (y < terrVector[i].size()) {
			if (terrVector[i][y] == ',') {
				break;
			}
			terr.push_back(terrVector[i][y]);
			y++;
		}
		map1.insert(pair<string, int>(terr, i));
		y = 0;
		terr = "";
		i++;
	}

	return map1;
}

//This method add edges to the "graph" implementation
void MapReader::addEdge(vector<vector<int>> &adj, int u, int v)
{
	adj[u].push_back(v);
}

//This methods prints the graph (which represent the map of the game) to the screen
void MapReader::printGraph(vector<vector<int>> adj, int V, map<int, string> &mapNtS)
{
	int i = 0;
	for (int v = 0; v < V; ++v)
	{
		cout << "\n list of territories " << v << " : " << mapNtS[v] << "\n head ";
		while (i < adj[v].size()) {
			cout << "-> " << adj[v][i] << " : " << mapNtS[adj[v][i]] << endl;
			i++;
		}
		i = 0;

	}
}

//The method create a "map" (which is not the same implementation as part 1 of the assignement), which represent the actual board
void MapReader::graphmaker(vector<string>  &terrVector, map<string, int>  &mapStN, map<int, string> &mapNtS) {
	int i = 0;
	int y = 0;
	int commaCounter = 0;
	string terr;

	vector<vector<int>> adj(terrVector.size() + 1);


	while (i < terrVector.size()) {

		while (y < terrVector[i].size() + 1) {
			if (terrVector[i][y] == ',') {
				commaCounter++;
			}
			if (terrVector[i][y] != ',' && commaCounter >= 4) {
				terr.push_back(terrVector[i][y]);
			}
			if ((terrVector[i][y] == ',' || y == terrVector[i].size() - 1) && commaCounter >= 5) {
				if (terr[terr.size()] == ' ') {
					terr.pop_back();
				}

				addEdge(adj, i, mapStN[terr]);

				terr = "";
			}
			y++;
		}
		commaCounter = 0;
		y = 0;
		terr = "";
		i++;
	}
	printGraph(adj, terrVector.size(), mapNtS);
}

//The methods that calls all the accessory methods in order to create the game map
bool MapReader::read(string mapFile)
{
    cout << "Reading map " << mapFile << " ..." << endl;
	ifstream input1(mapFile);
	string s;

	if (input1.is_open() == false) {
		cerr << "Error opening the file" << endl;
        return false;
	}

	ifstream *inputPt = &input1;
	while (getline(input1, s)) {
		if (s == "[Continents]")
			readContinents(inputPt);
		if (s == "[Territories]")
			readTerritories(inputPt);
	}

	//Check if the input is valid
	if (this->continents.empty() or this->territories.empty()) {
		cerr << "The map is invalid " << endl;
		return false;
	}
    /*
	map<int, string> mapNtS = createTerritoriesTranslatorMapNtS(inputMapVectors[1]);
	map<string, int> mapStN = createTerritoriesTranslatorMapStN(inputMapVectors[1]);
	graphmaker(inputMapVectors[1], mapStN, mapNtS);
    */
    return true;
}

int MapReader::getNbOfNodes()
{
    int count = 0;
    for (string line: this->continents)
    {
        int nbOfCountries = stoi(line.substr(line.find("=") + 1));
        count += nbOfCountries;
    }
    return count;
}

void MapReader::load(Map &map)
{
    regex regKey ("^\\[", regex_constants::icase);
    cout << "WIP" << endl;
}
