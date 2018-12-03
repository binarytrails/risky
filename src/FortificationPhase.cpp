#include "FortificationPhase.h"

using namespace std;

bool FortificationPhase::fortify(Player &p, Map &m) {
	cout << p.getName() << " turn to Fortify" << endl;


	bool invalid = true;
	string anw;

	while (invalid) {
		std::cout << "Do you want to fortify? (answer y/n)" << std::endl;

		std::cin >> anw;


		if (anw == "y" || anw == "Y") {
			Country& a = countrySelect(p);
			std::vector<Country> def = getAdj(a, m);
			Country d = selectReceiver(def);
			transfer(a, d);

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

Country& FortificationPhase::countrySelect(Player &p) {
	int x = 0;
	std::vector<int> v;

	//putting a list of the country that the player can fortify
	while (x < p.getCountries().size()) {
		if (p.getCountries()[x]->getArmies() >= 2) {
			v.push_back(x);
		}
		x++;
	}

	//displaying a list of the countries that the player can forty
	cout << " Here is a list of the countries that you can move your armies from. Which one would you like to attack from? (the answer is case sensitive)" << endl;
	x = 0;
	while (x < v.size()) {
		cout << p.getCountries()[v[x]]->getName() << " armie(s) " << p.getCountries()[v[x]]->getArmies() << endl;
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

std::vector<Country> FortificationPhase::getAdj(Country &c, Map &m) {

	vector<Country> adj = m.getAdj(c);


	return adj;
}

Country FortificationPhase::selectReceiver(std::vector<Country>& cV) {
	int x;
	cout << " Here is a list of the countries that you can fortify (the answer is case sensitive)" << endl;
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

void FortificationPhase::transfer(Country& aC, Country & dC) {
	cout << "You have " << aC.getArmies() << " in " << aC.getName() << endl;
	int a;
	bool b = true;

	if (aC.getArmies() == 1)
	{
		cout << "How many armies would you like to move from " << aC.getArmies() << endl;
		return;
	}

	while (b)
	{ 
		cout << " How many armies would you like to move" << endl;
		cin >> a;
		if (a >= aC.getArmies()) {
			cout << " Invalid number of armies moved (superior or equal as the amount possessed, please enter a valid number" << endl;
		}
		else {
			b = false;
		}
	}

	dC.setArmies(a);

	cout << a << " Armie(s) moved" << endl;

		
}