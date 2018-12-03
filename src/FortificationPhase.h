#pragma once

using namespace std;

#include <string>
#include <vector>
#include "Country.h"
#include "Card.h"
#include "Player.h"
#include "PlayerDice.h"
#include "Map.h"

class FortificationPhase
{
public:
	//	AttackPhase(const string name);
	//	~AttackPhase();

	static bool fortify(Player &p, Map &m);

	//	friend ostream& operator<<(ostream &output, const Player &player);

private:
	static Country& countrySelect(Player &p);

	static std::vector<Country> getAdj(Country &c, Map &m);
	static Country selectReceiver(std::vector<Country>& cV);
	static void transfer(Country& aC, Country & dC);

};