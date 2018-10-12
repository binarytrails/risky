#ifndef MAPREADER_H
#define MAPREADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

std::vector<std::string> readTerritories(std::ifstream* territories);

std::vector<std::string> readContinents(std::ifstream* territories);

std::map<int, std::string> createTerritoriesTranslatorMapNtS(std::vector<std::string> const &terrVector);

std::map<std::string, int> createTerritoriesTranslatorMapStN(std::vector<std::string> const &terrVector);

void addEdge(std::vector<std::vector<int>> &adj, int u, int v);

void printGraph(std::vector<std::vector<int>> adj, int V, std::map<int, std::string> &mapNtS);

void graphmaker(std::vector<std::string>  &terrVector, std::map<std::string, int>  &mapStN, std::map<int, std::string> &mapNtS);

void reader(std::string mapFile);


#endif