#pragma once
#ifndef TERRITORY_H
#define TERRITORY_H
#include <string>
#include <Vector>

class Territory
{

public:
	std::string getName();

	int getTerrID();

	void setName(std::string newName);

	Territory(std::string name);

	~Territory();

private:
	int terrID;
	static int tracker;
	std::string name;


	Territory();

};


#endif