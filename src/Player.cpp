//! @file
//! @author Vsevolod Ivanov

#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
    for (Country* country: this->countries)
        delete country;
    this->countries.clear();

    for (Card* card: this->cardsHand)
        delete card;
    this->cardsHand.clear();
}
