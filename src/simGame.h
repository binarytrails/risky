#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CPUplayers.h"

using namespace std;

class simGame {
public:
	vector<CPUplayers> players;
	int maxTurns;

	simGame(vector<CPUplayers> &p, int m);
	string playGame();
};