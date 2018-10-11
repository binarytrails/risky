/*
Assignment 1
Diana Zitting-Rioux
Hand.h
*/

#pragma once
#include "Deck.h"

class Hand {
public:
	Hand();

	void drawACard(Deck& d);
	void showHand();

	int exchange();

private:
	int infantryInHand;
	int cavalryInHand;
	int artilleryInHand;
	int handSize;

	int armiesGiven1;
	int armiesGiven2;
	int cardTradeTurns;
};