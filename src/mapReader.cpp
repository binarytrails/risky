// 345MapLoader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

// Puts all the territories string in a vector
std::vector<std::string> readTerritories(std::ifstream* territories) {

	std::vector<std::string> territoriesVector;
	std::string s;

	while (std::getline(*territories, s)) {
		if (s != "") {
			territoriesVector.push_back(s);
		}
		else {
		}
	}

	return territoriesVector;
}

// Puts all the territories string in a vector
std::vector<std::string> readContinents(std::ifstream* territories) {

	std::vector<std::string> continentsVector;
	std::string s;

	while (std::getline(*territories, s)) {
		if (s != "") {
			continentsVector.push_back(s);
		}
		else {
			break;
		}
	}
	return continentsVector;
}

//This method creates a map data structure to be able to translate int (from the graph implementation) to their corresponding strings (territories)
std::map<int, std::string> createTerritoriesTranslatorMapNtS(std::vector<std::string> const &terrVector) {

	std::map<int, std::string> map1;


	int i = 0;
	int y = 0;
	std::string terr;

	while (i < terrVector.size()) {

		while (y < terrVector[i].size()) {
			if (terrVector[i][y] == ',') {
				break;
			}
			terr.push_back(terrVector[i][y]);
			y++;
		}
		map1.insert(std::pair<int, std::string>(i, terr));
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
std::map<std::string, int> createTerritoriesTranslatorMapStN(std::vector<std::string> const &terrVector) {

	std::map<std::string, int> map1;


	int i = 0;
	int y = 0;
	std::string terr;

	while (i < terrVector.size()) {

		while (y < terrVector[i].size()) {
			if (terrVector[i][y] == ',') {
				break;
			}
			terr.push_back(terrVector[i][y]);
			y++;
		}
		map1.insert(std::pair<std::string, int>(terr, i));
		y = 0;
		terr = "";
		i++;
	}

	return map1;
}

//This method add edges to the "graph" implementation
void addEdge(std::vector<std::vector<int>> &adj, int u, int v)
{
	adj[u].push_back(v);
}

//This methods prints the graph (which represent the map of the game) to the screen
void printGraph(std::vector<std::vector<int>> adj, int V, std::map<int, std::string> &mapNtS)
{
	int i = 0;
	for (int v = 0; v < V; ++v)
	{
		std::cout << "\n list of territories " << v << " : " << mapNtS[v] << "\n head ";
		while (i < adj[v].size()) {
			std::cout << "-> " << adj[v][i] << " : " << mapNtS[adj[v][i]] << std::endl;
			i++;
		}
		i = 0;

	}
}

//The method create a "map" (which is not the same implementation as part 1 of the assignement), which represent the actual board
void graphmaker(std::vector<std::string>  &terrVector, std::map<std::string, int>  &mapStN, std::map<int, std::string> &mapNtS) {
	int i = 0;
	int y = 0;
	int commaCounter = 0;
	std::string terr;

	std::vector<std::vector<int>> adj(terrVector.size() + 1);


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
void reader(std::string mapFile)
{
	std::ifstream input1(mapFile);
	std::string s;

	if (input1.is_open()) {
		std::cout << "File " << mapFile << " Oppened " << std::endl;
	}
	else {
		std::cout << "Error oppening the file";
		//write an exit here
	}

	//
	std::vector<std::string> inputMapVectors[2];

	std::ifstream *inputPt = &input1;
	int isValid = 0;

	while (std::getline(input1, s)) {


		if (s == "[Continents]") {
			isValid++;
			inputMapVectors[0] = readContinents(inputPt);
		}

		if (s == "[Territories]") {
			isValid++;
			inputMapVectors[1] = readTerritories(inputPt);

			break;
		}
	}

	//Check if the input is valid
	if (isValid != 2) {
		std::cout << "The inputed map is invalid " << std::endl;
		return;
	}


	std::map<int, std::string> mapNtS = createTerritoriesTranslatorMapNtS(inputMapVectors[1]);
	std::map<std::string, int> mapStN = createTerritoriesTranslatorMapStN(inputMapVectors[1]);

	graphmaker(inputMapVectors[1], mapStN, mapNtS);



}