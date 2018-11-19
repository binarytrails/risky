#pragma once

#include "Strategy.h"
#include "Player.h"
#include "Hand.h"
//@author Diana Zitting-Rioux
//Context class for player strategy classes. Can be used to create a strategy and change strategy on the go.

class PlayerStrategy {
private:
	Strategy *strategy;
public:
	PlayerStrategy() {};
	PlayerStrategy(Strategy *startStrategy);
	~PlayerStrategy();

	void setStrategy(Strategy *newStrategy);

	void playerReinforcement(Player* player, Hand&h, int cont);
	void playerAttack(Player* player);
	void playerFortify(Player* player);

};
