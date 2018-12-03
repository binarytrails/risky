#include "AttackPhase.h"


using namespace std;

bool AttackPhase::attack(Player &p, Map &m)
{
	cout << p.getName() << " turn to attack" << endl;

	if (canAttack(p) == false) {
		cout << p.getName() << " cannot attack " << endl;
		return 1;
	}

	bool invalid = true;
	string anw;

	while (invalid) {
		std::cout << "Do you want to attack? (answer y/n)" << std::endl;

		std::cin >> anw;


		if (anw == "y" || anw == "Y") {
			Country& a = countrySelect(p);
			std::vector<Country> def = getAdj(a, m);
			Country d = selectDefender(def);
			battle(a, d, p);

		}
		else if (anw == "n" || anw == "N") {
			break;
		}
	}

	if (anw == "n" || anw == "N") {
		cout << " end of " << p.getName() << "'s turn" << endl;
	}

	return 1;
}

bool AttackPhase::canAttack(Player &p) {
	int x = 0;
	bool can = false;

	while (x < p.getCountries().size()) {
		if (p.getCountries()[x]->getArmies() >= 2) {
			can = true;
		}
		x++;
	}

	return can;
}

Country& AttackPhase::countrySelect(Player &p) {
	int x = 0;
	std::vector<int> v;

	//putting a list of the country that the player can attack from in the vector v
	while (x < p.getCountries().size()) {
		if (p.getCountries()[x]->getArmies() >= 2) {
			v.push_back(x);
		}
		x++;
	}

	//displaying a list of the countries that the player can attack from
	cout << " Here is a list of the countries that you can attack from. Which one would you like to attack from? (the answer is case sensitive)" << endl;
	x = 0;
	while (x < v.size()) {
		cout << p.getCountries()[v[x]]->getName() << "armie(s) " << p.getCountries()[v[x]]->getArmies() << endl;
		x++;
	}

	bool invalid = true;
	string att;
	int choice;

	x = 0;
	while (invalid) {
		cin >> att;
		while (x < v.size()) {
			if (att == p.getCountries()[v[x]]->getName()) {
				choice = x;
				invalid = false;
				break;
			}
			x++;
		}
		if (invalid) {
			cout << "Input is invalid, please try again" << endl;
			x = 0;
		}
	}

	return *p.getCountries()[choice];
}


std::vector<Country> AttackPhase::getAdj(Country &c, Map &m) {

	vector<Country> adj = m.getAdj(c);
	

	return adj;
}

Country AttackPhase::selectDefender(std::vector<Country>& cV) {
	int x;
	cout << " Here is a list of the countries that you can attack. Which one would you like to attack? (the answer is case sensitive)" << endl;
	x = 0;
	while (x < cV.size()) {

		cout << cV[x].getName() << "armie(s) " << cV[x].getArmies() << endl;
		x++;
	}

	bool invalid = true;
	string att;
	int choice;

	x = 0;
	while (invalid) {
		cin >> att;
		while (x < cV.size()) {
			if (att == cV[x].getName()) {
				choice = x;
				invalid = false;
				break;
			}
			x++;
		}
		if (invalid) {
			cout << "Input is invalid, please try again" << endl;
			x = 0;
		}
	}

	return cV[choice];

}

void AttackPhase::battle(Country& aC, Country & dC, Player &p) {
	cout << " Attacking player, please choose the amount of dice that you would like to use " << endl;
	bool invalid = true;
	int aA;

	while (invalid) {

		std::cin >> aA;

		if (aA <= aC.getArmies() && aA >= 1) {
			break;
		}
		cout << " The answer is not valid, please try again" << endl;
	}

	cout << " Defending player, please choose the amount of dice that you would like to use " << endl;

	int dA;

	while (invalid) {

		std::cin >> dA;

		if (dA <= dC.getArmies() && dA >= 1) {
			break;
		}

		cout << " The answer is not valid, please try again" << endl;
	}

	Dice attackingDice(aA);
	Dice defendingDice(dA);
	attackingDice.rolls();
	defendingDice.rolls();

	if (dA == 1) {
		if (attackingDice.values[aA - 1] > defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Defending country loose an army" << endl;
			dC.setArmies(dC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] < defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] == defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
	}

	if (dA == 2) {
		if (attackingDice.values[aA - 1] > defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Defending country loose an army" << endl;
			dC.setArmies(dC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] < defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 1] == defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}

		//battle 2

		if (attackingDice.values[aA - 2] > defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 2] << " Defending " << defendingDice.values[0] << endl;
			cout << " Defending country loose an army" << endl;
			dC.setArmies(dC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 2] < defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
		else if (attackingDice.values[aA - 2] == defendingDice.values[0]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[0] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
	}

	if (dA == 2 && aA == 1) {
		if (attackingDice.values[0] > defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Defending country loose an army" << endl;
			dC.setArmies(dC.getArmies() - 1);
		}
		else if (attackingDice.values[0] < defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
		else if (attackingDice.values[0] == defendingDice.values[1]) {
			cout << " Attacking: " << attackingDice.values[aA - 1] << " Defending " << defendingDice.values[1] << endl;
			cout << " Attacking country loose an army" << endl;
			aC.setArmies(aC.getArmies() - 1);
		}
	}

	if (dC.getArmies() <= 0) {
		cout << " Defending army has been defeated. The attacker can now choose how many armies to place on that field" << endl;
		int x;
		cin >> x;
		dC.setArmies(x);
		p.addCountry(&dC);
	}

}