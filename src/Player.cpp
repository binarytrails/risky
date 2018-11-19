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

string Player::getName() const
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

bool Player::hasCountry(string name)
{
    for (Country* country: this->countries)
    {
        if (country->getName() == name)
            return true;
    }
    return false;
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
vector<int> Player::rollDices(const int number)
{
    if ((number < 1) or (number > 3))
        throw -1;

    PlayerDice dice;
    vector<int> results;

    for (int i = 0; i < number; ++i)
        results.push_back(dice.roll());

    return results;
}

bool Player::reinforce()
{
    cout << "Player::reinforce()" << endl;
    this->activePhase = Player::REINFORCE;
    return false;
}

bool Player::attack()
{
    cout << "Player::attack()" << endl;
    this->activePhase = Player::ATTACK;
    return false;
}

bool Player::fortify()
{
    cout << "Player::fortify()" << endl;
    this->activePhase = Player::FORTIFY;
    return false;
}

Player::Phase Player::getActivePhase() const
{
    return this->activePhase;
}
