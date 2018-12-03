#pragma once

#include <string>
#include <iostream>
#include "CPUplayers.h"
#include "simGame.h"

class Tournament
{
public:
	Tournament();
	int startGame();
	int players;
	int maxTurns;
	int numOfGames;
	int numOfMaps;
};

	