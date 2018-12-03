// @author Diana Zitting-Rioux
// Cheater player strategy

#pragma once

#include "Player.h"
#include "Country.h"
#include "Deck.h"
#include "Hand.h"
#include "Reinforcement.h"
#include "Strategy.h"

using namespace std;

// Aggressive player strategy which reinforces and fortifies the strongest country and attacks with it.
class CheaterPlayer : public Strategy {
public:
	void reinforcement(Player* player, Hand&h, int cont);
	void attack(Player* player);
	void fortify(Player* player);
};