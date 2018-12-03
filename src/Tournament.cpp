#include "Tournament.h"
#include <vector>

using namespace std;

Tournament::Tournament() {

}

int Tournament::startGame() {
	std::cout << "Welcome to the risk tournament game. Would you like to play a single game(1) or a full tournament(2)?" << endl;
	
	int anw;

	cin >> anw;

	if(anw == 1) {
		cout << "Have fun!" << endl;
		// code for single game goes here
		return 0;
	}

	if (anw == 2) {
		cout << "Welcome to the tournament" << endl;
	}

	cout << "How many player would you like to have participating in this tournament? (2 to 4)" << endl;
	cin >> this->players;
	int i = 0;
	vector<CPUplayers> PP;
	

	while (i < players) {
		cout << "What is the name of player number " << (i + 1) << endl;
		string n;
		cin >> n;
		cout << "What is the Strategy of player number " << i << "(1) Benevolent, (2) Random, (3) Cheater, (4) aggresive" << endl;
		int s; 
		cin >> s;
		CPUplayers p(s, n);
		PP.push_back(p);

		i++;
	}
	

	cout << "How many maps would you like to have in rotation during this tournament? (1 to 5)" << endl;
	cin >> this->numOfMaps;

	cout << "How many games would you like to have this tournament last? (1 to 5)" << endl;
	cin >> this->numOfGames;

	cout << "After how many turns is a game considered a draw? (3 to 50)" << endl;
	cin >> this->maxTurns;

	//Actual Tournament starts running
	string **results = new string*[numOfMaps];
	for (int i = 0; i < numOfMaps; ++i) {
		results[i] = new string[numOfGames];
	}

	i = 0;
	int y = 0;

	//creates game simulator
	simGame GS(PP, this->maxTurns);

	//Plays all the game
	while (i < numOfMaps) {
		while (y < numOfGames) {
			results[i][y] = GS.playGame();
			y++;
		}
		y = 0;
		i++;
	}
	i = 0;
	y = 0;
	//Display all the games
	while (i < numOfMaps) {
		while (y < numOfGames) {
			cout << "Map: " << (i + 1) << " Game: " << (y + 1) << " : " << results[i][y] << endl;
			y++;
		}
		y = 0;
		i++;
	}
	return 0;
}