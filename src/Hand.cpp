/*
Assignment 1 
Diana Zitting-Rioux
Hand.cpp
*/

#include "Hand.h"
#include <iostream>
using namespace std;

Hand::Hand()
{
	handSize = 0;

	infantryInHand = 0;
	cavalryInHand = 0;
	artilleryInHand = 0;

	armiesGiven1 = 4;
	armiesGiven2 = 15;
	cardTradeTurns = 1;
}

// Calls draw() from Deck to receive a random card to be put in the hand
void Hand::drawACard(Deck& d)
{
	int b = d.draw();

	switch (b) {
	case 0: {
		cout << "Can't receive anymore cards." << endl; 
		break; 
	}
	case 1: {
		infantryInHand++;
		handSize++;
		break;
	}
	case 2: {
		cavalryInHand++;
		handSize++;
		break;
	}
	case 3: {
		artilleryInHand++;
		handSize++;
		break;
	}
	}
}

// Shows the contents of the hand
void Hand::showHand()
{
	cout << "Cards in hand: " << handSize << ". Infantry in hand :" << infantryInHand << ". Cavalry in hand : " << cavalryInHand << ". Artillery in hand: " << artilleryInHand << endl;
}

// Exchanges cards in the hand for an integer value of armies according to the rules 
int Hand::exchange()
{
	int armiesGivenToPlayer = 0;
	bool isThereMoreToExchange = false;
	do {
		if (artilleryInHand >= 1 && cavalryInHand >= 1 && infantryInHand >= 1) { // exchanges if there is at least one of each card type
			if (cardTradeTurns < 6) {
				armiesGivenToPlayer += armiesGiven1;
				armiesGiven1 += 2;
			}
			else {
				armiesGivenToPlayer += armiesGiven2;
				armiesGiven2 += 5;
			}
			artilleryInHand--;
			cavalryInHand--;
			infantryInHand--;
			handSize -= 3;
			cardTradeTurns++;
		}
		else if (artilleryInHand >= 3) { // exchanges if there are 3 artillery cards in the hand
			if (cardTradeTurns < 6) {
				armiesGivenToPlayer += armiesGiven1;
				armiesGiven1 += 2;
			}
			else {
				armiesGivenToPlayer += armiesGiven2;
				armiesGiven2 += 5;
			}
			artilleryInHand -= 3;
			handSize -= 3;
			cardTradeTurns++;
		}
		else if (cavalryInHand >= 3) { // exchanges if there are 3 cavalry cards in the hand 
			if (cardTradeTurns < 6) {
				armiesGivenToPlayer += armiesGiven1;
				armiesGiven1 += 2;
			}
			else {
				armiesGivenToPlayer += armiesGiven2;
				armiesGiven2 += 5;
			}
			cavalryInHand -= 3;
			handSize -= 3;
			cardTradeTurns++;
		}
		else if (infantryInHand >= 3) { // exchanges if there are 3 infantry cards in the hand
			if (cardTradeTurns < 6) {
				armiesGivenToPlayer += armiesGiven1;
				armiesGiven1 += 2;
			}
			else {
				armiesGivenToPlayer += armiesGiven2;
				armiesGiven2 += 5;
			}
			infantryInHand -= 3;
			handSize -= 3;
			cardTradeTurns++;
		}
		else  {
			return armiesGivenToPlayer;
		}
	} while (isThereMoreToExchange == false); // loops until all suitable card combinations are consumed
	return 0;
}

