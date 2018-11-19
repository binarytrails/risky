#pragma once

using namespace std;

#include <string>
#include <vector>
#include "Country.h"
#include "Card.h"
#include "Player.h"
#include "PlayerDice.h"
#include  "Dice.h"
#include "Map.h"

class AttackPhase
{
public:
//	AttackPhase(const string name);
//	~AttackPhase();

	static bool attack(Player &p, Map &m);

	string getName() const;

//	friend ostream& operator<<(ostream &output, const Player &player);

private:
	static bool canAttack(Player &p);
	static Country& countrySelect(Player &p);
	static std::vector<Country> getAdj(Country &c, Map &m);
	static Country selectDefender(std::vector<Country>& cV);
	static void battle(Country& aC, Country & dC, Player &p);

};