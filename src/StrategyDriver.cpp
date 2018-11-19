#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Reinforcement.h"
#include "Country.h"
#include "Strategy.h"
#include "PlayerStrategy.h"
#include "HumanPlayer.h"
#include "AggressivePlayer.h"
#include "BenevolentPlayer.h"

using namespace std;

Deck TestDeck; // creates a deck with default 42 countries
			   //Deck TestDeck2(int amountofcountries); //TODO add amount of countries
Hand TestHand; // creates a hand of cards

int main() {

	//create player, add 12 countries and 4 cards.
	Player* player1 = new Player("foo");
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

	usa->setArmies(6);
	canada->setArmies(6);
	mexico->setArmies(2);
	germany->setArmies(2);
	italy->setArmies(2);
	spain->setArmies(2);
	brazil->setArmies(2);
	sweden->setArmies(2);
	norway->setArmies(2);
	finland->setArmies(0);
	russia->setArmies(2);
	china->setArmies(2);



	for (int i = 0; i < 4; i++) {
		TestHand.drawACard(TestDeck);
	}

	cout << "\nStarting with human player" << endl;
	PlayerStrategy playerStrategy(new HumanPlayer); // Create PlayerStrategy with HumanPlayer
	cout << "Reinforcing with human player" << endl;
	playerStrategy.playerReinforcement(player1, TestHand, 0);
	cout << "\nChanging to Aggressive Player" << endl;
	playerStrategy.setStrategy(new AggressivePlayer); // Set PlayerStrategy to AggressivePlayer
	cout << "Reinforcing with Aggressive Player" << endl;
	playerStrategy.playerReinforcement(player1, TestHand, 0);
	cout << "Attacking with Aggressive Player" << endl;
	playerStrategy.playerAttack(player1);
	cout << "\nChanging to Benevolent Player" << endl;
	playerStrategy.setStrategy(new BenevolentPlayer); // Set Strategy to BenevolentPlayer
	cout << "Reinforcing with Benevolent Player" << endl;
	playerStrategy.playerReinforcement(player1, TestHand, 0);
	cout << "Attacking with Benevolent Player" << endl;
	playerStrategy.playerAttack(player1);
	cout << "Fortifying with Benevolent Player" << endl;
	playerStrategy.playerFortify(player1);

	cout << "\nProgram has finished" << endl; 

}
	