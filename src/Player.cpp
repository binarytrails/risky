//! @file
//! @author Vsevolod Ivanov

#include "Player.h"

using namespace std;

Player::Player(const string name): name(name)
{
}

Player::~Player()
{
    for (Country* country: this->countries)
        delete country;
    this->countries.clear();

    for (Card* card: this->cards)
        delete card;
    this->cards.clear();
}

const string Player::getName() const
{
    return this->name;
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

vector<Country*> Player::getCountries() const
{
    return this->countries;
}

void Player::addCard(Card* card)
{
    this->cards.push_back(card);
}

void Player::removeCard(Card* card)
{
    auto it = find(this->cards.begin(), this->cards.end(), card);
    if (it != this->cards.end())
        this->cards.erase(it);
}

vector<Card*> Player::getCards() const
{
    return this->cards;
}
