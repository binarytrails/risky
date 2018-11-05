/*
Assignment 1
Diana Zitting-Rioux
Deck.cpp
*/

#include "Deck.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Deck::Deck()
{
	deckSize = 42; // Sets the size of the deck to the standard 42 countries

	infantryInDeck =14;
	cavalryInDeck = 14;
	artilleryInDeck = 14;

	srand(time(0)); // set the seed for rng
}

Deck::Deck(int countriesOnTheMap)
{
	deckSize = countriesOnTheMap; // Set the deck to certain amount of countries on the map

	int countriesDividedByThree = deckSize / 3; // Divides country by three

												// Sets the deck depending on how countries are divisible by three
	if (deckSize % 3 == 0) {
		infantryInDeck = countriesDividedByThree + 1;
		cavalryInDeck = countriesDividedByThree + 1;
		artilleryInDeck = countriesDividedByThree + 1;
	}
	else if (deckSize % 3 == 1) {
		infantryInDeck = countriesDividedByThree + 1;
		cavalryInDeck = countriesDividedByThree;
		artilleryInDeck = countriesDividedByThree;
	}
	else {
		infantryInDeck = countriesDividedByThree + 1;
		cavalryInDeck = countriesDividedByThree + 1;
		artilleryInDeck = countriesDividedByThree;
	}

	srand(time(0)); // set the seed for rng
}

// Draws a card from the deck with random number generator and returns it to the deck
CardType Deck::draw()
{
	if (deckSize == 0) { // if there are no cards in the deck
		cout<< "Can't draw more cards as the deck is empty\n";
		return NoCardsLeft;
	}

	bool FoundInDeck = false;
	do {
	int RandomNum = rand() % 99; // random number generator for 98 numbers (equal chance to draw any card)

	if (RandomNum %3 ==0 && infantryInDeck > 0) { // if number is 3 mod 0, returns an Infantry card and removes it from the deck
		infantryInDeck--;
		deckSize --;
		cout << "You drew an Infantry card\n";
		return CardType::Infantry;
	}
	if (RandomNum % 3 == 1 && cavalryInDeck > 0) { // if number is 3 mod 1, returns a Cavalry card and removes it from the deck
		cavalryInDeck--;
		deckSize--;
		cout << "You drew a Cavalry card\n";
		return CardType::Cavalry;
	}
	if (RandomNum % 3 == 2 && artilleryInDeck > 0) { // if number is 3 mod 2, returns an Artillery card and removes it from the deck
		artilleryInDeck--;
		deckSize--;
		cout << "You drew an Artillery card\n";
		return CardType::Artillery;
	}
	} while (FoundInDeck == false); // loops it again in case there are no cards of that type left in the deck
	return NoCardsLeft;
}

// shows the contents of the deck for demo use
void Deck::showDeck() {
	cout << "Deck size =" << deckSize << ". Infantry in deck: " << infantryInDeck << ". Cavalry in Deck: " << cavalryInDeck << ". Artillery in deck: " << artilleryInDeck << endl;
}

void Deck::setDeck(int n)
{
	deckSize = n;
}

