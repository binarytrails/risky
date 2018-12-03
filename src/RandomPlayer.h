#pragma once

#include <stdlib.h>  
#include <time.h>

#include "Player.h"
#include "Country.h"
#include "Deck.h"
#include "Hand.h"
#include "Reinforcement.h"
#include "Strategy.h"
#include "Dice.h"

using namespace std;

// Aggressive player strategy which reinforces and fortifies the strongest country and attacks with it.
class RandomPlayer : public Strategy {
public:
	void reinforcement(Player* player, Hand&h, int cont);
	void attack(Player* player);
	void fortify(Player* player);
private:
	Country* findRandom(Player* player);
	void startAttack(Player* player, Country* dC, Country* aC);
	Country* australia = new Country("Australia"); // only for demo
};