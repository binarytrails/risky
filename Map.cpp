#include <string>
#include <iostream>
#include"Map.h"
#include"Territory.h"


void Map::printMap() {
	int i = 0;
	for (int v = 0; v < size; ++v)
	{
		std::cout << "\n list of territories " << v << " : " << NtTtrans[v].getName() << "\n head ";
		while (i < size) {
			std::cout << "-> " << terrMap[v][i].getName() << std::endl;
			i++;
		}
		i = 0;

	}
}

std::string Map::getName() {
	return name;

}

void Map::addterrEdge(Territory &a, Territory &b) {

	terrMap[a.getTerrID()].push_back(b);

	NtTtrans.insert(std::pair<int, Territory>(a.getTerrID(), b));
	TtNtrans.insert(std::pair<Territory, int>(b, a.getTerrID()));
	
}

int Map::getSize() {
	return size;
}

void Map::setName(std::string newName) {
	name = newName;
}

Map::Map(std::string newName, int size) {
	name = newName;
	std::vector<std::vector<Territory>> terrMap(size);
}

Map::~Map() {
	std::cout << "map destroyed" << std::endl;
}