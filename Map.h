#ifndef Map_H
#define Map_H
#include <string>
#include <vector>
#include <map>
#include "Territory.h"

class Map
{

public:
	void addterrEdge(Territory &a, Territory &b);

	void printMap();

	std::string getName();


	int getSize();

	void setName(std::string newName);

	Map(std::string name, int size);

	~Map();

private:
	int terrNumber;
	int contNumber;
	int size;
	std::string name;
	std::vector<std::vector<Territory>> terrMap;
	std::vector<std::vector<int>> contMap;
	
	std::map<int, Territory> NtTtrans;
	std::map<Territory, int> TtNtrans;


	Map();

};


#endif