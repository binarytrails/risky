// @author Diana Zitting-Rioux
// startAttack code by Keven Abellard (modified to not use user input)

#include "RandomPlayer.h"

void RandomPlayer::reinforcement(Player * player, Hand & h, int cont)
{
	int bonusArmies = Reinforcement::calculateTotalReinforcements(player, h, cont);
	Country* country = findRandom(player);
	country->setArmies(bonusArmies);
	cout << "Setting armies to " << country->getName() << endl;
}

void RandomPlayer::attack(Player * player)
{
	srand(time(0));
	int aA = rand() % 3+1;
	bool invalid1 = true;
	Country* aC = findRandom(player);
	while (invalid1) {
		if (aC->getArmies() >= 2)
			break;
		Country* aC = findRandom(player);
	}
	cout << "attacking " << aA << " times." << endl;
	for (int i = 0; i < aA; i++) {
		Country* aC = findRandom(player);
		while (invalid1) {
			if (aC->getArmies() >= 2)
				break;
			Country* aC = findRandom(player);
		}
		australia->setArmies(6);
		cout << "Attacking Australia" << endl;  // TODO find adjacent to attack from
		startAttack(player, australia, aC);	
	}
}

void RandomPlayer::fortify(Player * player)
{
	Country* rCountry = findRandom(player);
	Country* armiesFrom = findRandom(player); // TODO should be adjacent country to rCountry
	int RandomNum = rand() % armiesFrom->getArmies();
	cout << "Setting " << RandomNum << " armies to " << rCountry->getName() << " from " << armiesFrom->getName() << endl;
	armiesFrom->removeArmies(RandomNum);
	rCountry->setArmies(RandomNum);
}


Country * RandomPlayer::findRandom(Player * player)
{
	int RandomNum = rand() % player->getCountries().size();
	vector<Country*> countries = player->getCountries();
	Country* country = countries[RandomNum];
	return country;
}

void RandomPlayer::startAttack(Player * player, Country * dC, Country* aC)
{
	srand(time(0));
	int aA = rand() % 3 +1;
	cout << " Attacking with  " << aA << " dice." <<  endl;

	int dA = rand() % 2 +1; 
	cout << " Defending with " << dA << "dice." << endl;


	Dice attackingDice(aA);
	Dice defendingDice(dA);
	attackingDice.rolls();
	defendingDice.rolls();

	if (dA == 1) {
		if (attackingDice.values[aA - 1] > defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Defending country loose an army" << endl;
			dC->setArmies(dC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] < defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] == defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
	}

	if (dA == 2) {
		if (attackingDice.values[aA - 1] > defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Defending country loose an army" << endl;
			dC->setArmies(dC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] < defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] == defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}

		//battle 2

		if (attackingDice.values[aA - 2] > defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 2] << " Defending " << defendingDice.values[0] << endl;
			cout << " Defending country loose an army" << endl;
			dC->setArmies(dC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 2] < defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
		else if (attackingDice.values[aA - 2] == defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
	}

	if (dA == 2 && aA == 1) {
		if (attackingDice.values[0] > defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Defending country loose an army" << endl;
			dC->setArmies(dC->getArmies() - 1);
		}
		else if (attackingDice.values[0] < defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
		else if (attackingDice.values[0] == defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC->setArmies(aC->getArmies() - 1);
		}
	}

	if (dC->getArmies() <= 0) {
		cout << " Defending army has been defeated. The attacker can now choose how many armies to place on that field" << endl;
		dC->setArmies(5);
		player->addCountry(dC);
	}
}
