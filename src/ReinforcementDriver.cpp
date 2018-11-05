#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Reinforcement.h"
#include "Country.h"
using namespace std;

Deck TestDeck; // creates a deck with default 42 countries
			   //Deck TestDeck2(int amountofcountries); //TODO add amount of countries
Hand TestHand; // creates a hand of cards
Hand TestHand2;

int main() {

	//create player1, add 12 countries and 4 cards.
	Player* player1 = new Player("Player1");
	Country* usa = new Country("USA");
	Country* canada = new Country("CA");
	Country* mexico = new Country("Mexico");
	Country* germany = new Country("Germany");
	Country* italy = new Country("Italy");
	Country* spain = new Country("Spain");
	Country* brazil = new Country("Brazil");
	Country* sweden = new Country("Sweden");
	Country* norway = new Country("Norway");
	Country* finland = new Country("Finland");
	Country* russia = new Country("Russia");
	Country* china = new Country("China");

	player1->addCountry(usa);
	player1->addCountry(canada);
	player1->addCountry(mexico);
	player1->addCountry(germany);
	player1->addCountry(italy);
	player1->addCountry(spain);
	player1->addCountry(brazil);
	player1->addCountry(sweden);
	player1->addCountry(norway);
	player1->addCountry(finland);
	player1->addCountry(russia);
	player1->addCountry(china);

	usa->setArmies(0);
	canada->setArmies(0);
	mexico->setArmies(0);
	germany->setArmies(0);
	italy->setArmies(0);
	spain->setArmies(0);
	brazil->setArmies(0);
	sweden->setArmies(0);
	norway->setArmies(0);
	finland->setArmies(0);
	russia->setArmies(0);
	china->setArmies(0);



	for (int i = 0; i<4; i++) { 
		TestHand.drawACard(TestDeck);
	}

	Reinforcement::reinforcement(player1, TestHand, 3);

	Player* player2 = new Player("Player2");
	Country* japan = new Country("Japan");

	player2->addCountry(japan);
	japan->setArmies(0);

	for (int i = 0; i<10; i++) {
		TestHand2.drawACard(TestDeck);
	}

	Reinforcement::reinforcement(player2, TestHand2, 0);
	cout << "Japan has " << japan->getArmies() << " armies.";

}
