#include "BenevolentPlayer.h"

// Calculates extra reinforcements, finds the weakest country and sets the received reinforcements to the country.
void BenevolentPlayer::reinforcement(Player * player, Hand & h, int cont)
{
	int bonusArmies = Reinforcement::calculateTotalReinforcements(player, h, cont);
	Country* weakestToReinforce = findWeakest(player);
	bonusArmies += weakestToReinforce->getArmies();

	cout << "Reinforcing " << weakestToReinforce->getName() << " with " << bonusArmies << " armies." << endl;
	weakestToReinforce->setArmies(bonusArmies);
}

// Benevolent player never attacks so only a message is displayed.
void BenevolentPlayer::attack(Player * player)
{
	cout << "Player decides not to attack." << endl;
}

void BenevolentPlayer::fortify(Player * player)
{
	Country* fortifiedCountry = findWeakest(player);
	cout << "Fortifying the weakest country " << fortifiedCountry->getName();
	//TODO fortify the weakest country.

}

//Helper method to find players weakest country.
Country * BenevolentPlayer::findWeakest(Player * player)
{
	Country* smallestArmy = NULL;

	// Compare armies in each country and if amount smaller than the current smallestCountry, sets it to that country.
	for (Country* country : player->getCountries()) { 
		if (smallestArmy == NULL || country->getArmies() < smallestArmy->getArmies()) {
			smallestArmy = country;
		}
	}
	return smallestArmy;
}
