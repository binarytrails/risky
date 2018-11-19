//@author Diana Zitting-Rioux
//Benevolent player strategy controlled by the computer. Does not attack, only strengthens weakest country.

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Strategy.h"
#include "Player.h"
#include "Country.h"
#include "Deck.h"
#include "Hand.h"
#include "Reinforcement.h"

using namespace std;

// Benevolent player class which reinforces and fortifies the weakest country and never attacks.
class BenevolentPlayer : public Strategy {
public:
	void reinforcement(Player* player, Hand&h, int cont);
	void attack(Player* player);
	void fortify(Player* player);
private:
	Country* findWeakest(Player* player);
};