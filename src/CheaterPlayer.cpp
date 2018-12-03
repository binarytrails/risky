// @author Diana Zitting-Rioux

#include "CheaterPlayer.h"

void CheaterPlayer::reinforcement(Player * player, Hand & h, int cont)
{
	for (Country* country : player->getCountries()) { // loops through the vector
			int howManyToPlace = 2*country->getArmies(); // Adds up the player input and the existing armies in the country
			country->setArmies(howManyToPlace); // sets the amount of armies to the target country
			cout << country->getName() << " has " << country->getArmies() << " armies."<<endl;
	}
}

void CheaterPlayer::attack(Player * player)
{
	cout << "Taking over neighbor countries " << endl;
	// TODO automatically take over countries of neighbors 
	// Check for all enemy neighbors and add to player vector
}

void CheaterPlayer::fortify(Player * player)
{
	// TODO double armies of countries with enemy neighbors, for now doubles all the armies like in reinforcement
	for (Country* country : player->getCountries()) { // loops through the vector
		// TODO check if enemy neighbors, if yes, doubles armies 
		int howManyToPlace = 2 * country->getArmies(); // Adds up the player input and the existing armies in the country
		country->setArmies(howManyToPlace); // sets the amount of armies to the target country
		cout << country->getName() << " has " << country->getArmies() << " armies." << endl;
	}
}
