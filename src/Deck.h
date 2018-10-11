/*
Assignment 1
Diana Zitting-Rioux
*/

#pragma once

enum CardType {
	Infantry,
	Cavalry,
	Artillery,
	NoCardsLeft
};

class Deck {
public:
	Deck(); // constructor with default 42 countries
	Deck(int countriesOnTheMap); // constructor with set amount of countries on the map

	int draw(); // Draws a random card from the deck and gives it to the hand
	void showDeck(); // Shows the contents of the deck
	void setDeck(int n);

private:
	int infantryInDeck; 
	int cavalryInDeck;
	int artilleryInDeck;
	int deckSize;
};
