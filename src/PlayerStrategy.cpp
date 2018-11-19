#include "PlayerStrategy.h"

PlayerStrategy::PlayerStrategy(Strategy * startStrategy)
{
	this->strategy = startStrategy;
}

PlayerStrategy::~PlayerStrategy()
{
	delete this->strategy;
}

void PlayerStrategy::setStrategy(Strategy * newStrategy)
{
	this->strategy = newStrategy;
}

void PlayerStrategy::playerReinforcement(Player * player, Hand & h, int cont)
{
	return this->strategy->reinforcement(player, h, cont);
}

void PlayerStrategy::playerAttack(Player *player)
{
	return this->strategy->attack(player);
}

void PlayerStrategy::playerFortify(Player *player)
{
	return this->strategy->fortify(player);
}

