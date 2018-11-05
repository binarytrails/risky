#include "Reinforcement.h"

// reinforcement method that calls first a method to receive armies and then places armies
void Reinforcement::reinforcement(Player*p, Hand&h, int con) 
{
	int reinforcementsReceived =calculateTotalReinforcements(p, h, con);

	placeReinforcements(p, reinforcementsReceived);
}

// Calculates armies received by calling three methods to receive armies by countries, by card exchanges and by continents owned
int Reinforcement::calculateTotalReinforcements(Player*p, Hand&h, int con) 
{
	int byCountry = reinforcementsByCountry(p);
	cout << "Countries earned " << byCountry << " armies." << endl;
 	int byCards = reinforcementsByCards(h);
	cout << "Cards earned " << byCards << " armies." << endl;
	int byContinent = reinforcementsByContinent(con);
	cout << "Continents earned " << byContinent << " armies." << endl;
	int totalReinforcements = byCountry + byCards + byContinent;
	cout << "Total of reinforcements is " << totalReinforcements << ". " << endl;
	return totalReinforcements;
}

// Calculates the amount of countries owned by player and divides it by three and returns that value. If the divisor is 9 or less, returns 3
int Reinforcement::reinforcementsByCountry(Player*p)
{
	cout << p->getCountries().size() << " ";
	if (p->getCountries().size() <= 9) { // If the amount countries owned is 3 or less after division, returns 3 armies
		return 3;
	}
	else {
		int x = p->getCountries().size() / 3; // Divides Player countries by 3, uses truncation for rounding
		return x;
	}
		
}

// If player owns more than 5 cards, cards are exchanged for armies.
int Reinforcement::reinforcementsByCards(Hand&h)
{
	if (h.getHandSize() > 5) { // if hand has more than 5 cards, executes exchange from Hand and receives armies accordingly
		return h.exchange();
	}
	return 0;
}

// Gets the bonus armies from having a whole continent
int Reinforcement::reinforcementsByContinent(int con) 
{
	return con; // TODO compare every continent's countries with player's countries, add +1 if yes and give appropriate amount of armies accordingly
}

// Places received reinforcemnts on the map.
void Reinforcement::placeReinforcements(Player* p, int rr)
{
	cout << "Please place your " << rr << " armies on the map." << endl;
	bool checkAmount = true;
	while (rr > 0) { // while there are armies left to place
		string whereToPlace;
		int howManyToPlace;
		bool checkWhereToPlace = true;
		do {
			cout << "How many armies do you wish to place?" << endl;
			cin >> howManyToPlace;
			if (cin.fail()) { // if not an integer input, asks again for input
				cout << "Input was not an integer" << endl;
				cin.clear();
				cin.ignore();
				checkAmount = false;
			}
			else if (!(howManyToPlace <= rr && howManyToPlace > 0)) { // if amount is not within armis owned
				cout << "Invalid input, please enter an integer between 0 and " << rr << endl;
				checkAmount = false;
			}
			else {
				checkAmount = true;
			}
		} while (checkAmount == false);
		cin.get();
		do {
			cout << "Where do you wish to place your armies?" << endl;
			getline(cin, whereToPlace);
			for (Country* country : p->getCountries()) { // loops through the vector
				if (country->getName() == whereToPlace) { // checks if the country name matches with the player input
					howManyToPlace = howManyToPlace +country->getArmies(); // Adds up the player input and the existing armies in the country
					country->setArmies(howManyToPlace); // sets the amount of armies to the target country
					checkWhereToPlace = true;
					break;
				}
				else {
					checkWhereToPlace = false;
				}
			}
		} while (checkWhereToPlace == false); // keeps on looping if input is not found in player's owned countries

		rr -= howManyToPlace;
		if (rr > 0)
			cout << "You have " << rr << " armies still to place." << endl;
		else
			cout << "All your armies have been placed." << endl;
	}
}
