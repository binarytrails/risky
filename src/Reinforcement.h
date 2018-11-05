#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Hand.h"
#include "Player.h"
#include "Country.h"

using namespace std;

class Reinforcement {
public:
	static void reinforcement(Player*p, Hand&h, int con); // main loop takes in Player's countries, hand and continent
private:
	static int calculateTotalReinforcements(Player*, Hand&h, int con); // Calculates how many armies received
	static int reinforcementsByCountry(Player* p); 
	static int reinforcementsByCards(Hand &h); // Calculates how many received from cards in Hand
	static int reinforcementsByContinent(int con); // TODO get continents
	static void placeReinforcements(Player*p, int rr); 
};
