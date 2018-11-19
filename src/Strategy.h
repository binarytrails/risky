//@author Diana Zitting-Rioux
// Strategy abstract class for Human controlled player and computer controlled
// aggressive and benevolent player. Uses PlayerStrategy class as Context class.

#pragma once
#include "Player.h"
#include "Hand.h"

class Strategy {
public: 

	virtual void reinforcement(Player* player, Hand&h, int cont);
	virtual void attack(Player* player);
	virtual void fortify(Player* player);
};
