//! @file
//! @author Vsevolod Ivanov

#include "Player.h"

using namespace std;

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

void Player::addCountry(Country* country)
{
    this->countries.push_back(country);
}
void Player::removeCountry(Country* country)
{
    auto it = find(this->countries.begin(), this->countries.end(), country);
    if (it != this->countries.end())
        this->countries.erase(it);
}

void Player::addCard(Card* card)
{
    this->cardsHand.push_back(card);
}

void Player::removeCard(Card* card)
{
    auto it = find(this->cardsHand.begin(), this->cardsHand.end(), card);
    if (it != this->cardsHand.end())
        this->cardsHand.erase(it);
}
