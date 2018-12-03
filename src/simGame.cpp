#include "simGame.h"

simGame::simGame(vector<CPUplayers> &p, int m) {
	this->players = p;
	this->maxTurns = m;
}

string simGame::playGame() {
	int turnsToEnd = rand() % (maxTurns + 5) + 3;
	int winnerIndex = rand() % (players.size()+1);

	if (turnsToEnd > maxTurns) {
		return "draw";
	}
	else {
		return(players[winnerIndex].name);
	}
}
