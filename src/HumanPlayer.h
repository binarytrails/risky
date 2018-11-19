//@author Diana Zitting-Rioux
//Human controlled game strategy class.

#pragma once
#include <iostream>
#include <string>
#include <vector>
 
#include "strategy.h"
#include "Player.h"
#include "Country.h"
#include "Deck.h"
#include "Hand.h"
#include "Reinforcement.h"

// Human player strategy class that takes input from the keyboard for game decisions.
class HumanPlayer : public Strategy {
public:
	void reinforcement(Player* player, Hand&h, int cont);
	void attack(Player* player);
	void fortify(Player* player);
};