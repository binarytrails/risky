#include <string>
#include"Territory.h"

int Territory::tracker = 0;

Territory::Territory(std::string newName) {
	terrID = tracker;
	name = newName;
	tracker++; 
}

std::string Territory::getName() {
	return name;
}


int Territory::getTerrID() {
	return terrID;
}


void Territory::setName(std::string newName) {
	name = newName;

}