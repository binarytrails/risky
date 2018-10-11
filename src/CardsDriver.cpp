#include <iostream>
#include "Deck.h"
#include "Hand.h"
using namespace std;

Deck TestDeck; // creates a deck with default 42 countries
//Deck TestDeck2(int amountofcountries); //TODO add amount of countries
Hand TestHand; // creates a hand of cards

int main()
{
	TestHand.showHand(); // shows an empty hand
	TestDeck.showDeck(); // shows a deck with 42 cards

	for (int i=0; i<43;i++) { // draws all the cards from the deck and tries to draw one more than exists in the deck
		TestHand.drawACard(TestDeck);
	}
	TestDeck.showDeck(); // Shows an empty deck

	TestHand.showHand(); // shows a full hand

	cout << "Armies received for given cards: " << TestHand.exchange() << endl; // Shows the amount of armies received for exchanging cards

	TestHand.showHand(); // shows an empty hand

	//TestDeck.showDeck(); // Shows contents of the deck with map values

	return 0;
}