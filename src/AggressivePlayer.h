#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "strategy.h"
//@author Diana Zitting-Rioux
//Aggressive player strategy controlled by the computer. Strengthens and attacks with the strongest country.

#include "Player.h"
#include "Country.h"
#include "Deck.h"
#include "Hand.h"
#include "Reinforcement.h"

using namespace std;

// Aggressive player strategy which reinforces and fortifies the strongest country and attacks with it.
class AggressivePlayer : public Strategy {
public:
	void reinforcement(Player* player, Hand&h, int cont);
	void attack(Player* player);
	void fortify(Player* player);
private:
	Country* findStrongest(Player* player);
};