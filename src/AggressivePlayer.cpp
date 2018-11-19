#include "AggressivePlayer.h"

// Calculates reinforcements for the player, finds the strongest country and places armies on it.
void AggressivePlayer::reinforcement(Player * player, Hand & h, int cont)
{
	int bonusArmies = Reinforcement::calculateTotalReinforcements(player, h, cont);
	Country* strongestToReinforce = findStrongest(player);

	cout << "Reinforcing " << strongestToReinforce->getName() << " with " << bonusArmies << " armies." << endl;
	bonusArmies += strongestToReinforce->getArmies();
	strongestToReinforce->setArmies(bonusArmies);

}

// Attacks with the strongest country.
void AggressivePlayer::attack(Player * player)
{
	Country* attackingCountry = findStrongest(player);
	cout << "Attacking with " << attackingCountry << endl;
	// TODO attack with strongest country
}

// Fortifies the strongest country at the end of turn.
void AggressivePlayer::fortify(Player * player)
{
	Country* fortifiedCountry = findStrongest(player);
	cout << "Fortifying " << fortifiedCountry  << endl;
	// TODO fortify strongest
}

// Helper method to find players strongest country.
Country* AggressivePlayer::findStrongest(Player* player)
{
	Country* biggestArmy = NULL;

	// Compares each countries to the current biggestArmy and if bigger, sets it to that country.
	for (Country* country : player->getCountries()) {
		if (biggestArmy == NULL || country->getArmies() > biggestArmy->getArmies()) {
			biggestArmy = country;
		}
	}
	return biggestArmy;
}
