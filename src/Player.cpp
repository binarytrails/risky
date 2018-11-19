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

Country* Player::getCountry(string name)
{
    for (Country* country: this->countries)
    {
        if (country->getName() == name)
            return country;
    }
    return NULL;
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
    cout << "Reinforcement phase!" << endl;
    this->activePhase = Player::REINFORCE;

    // NOTE placeholder code until team members merge
    int armies = 0;
    string countryName;

    cout << "How many armies? "; cin >> armies;
    cout << "Destination country: "; cin >> countryName;

    Country *country = this->getCountry(countryName);
    this->targetCountry = country;
    country->addArmies(armies);
    cout << countryName << " has now " <<
            country->getArmies() << " armies" << endl;

    return true;
}

bool Player::attack()
{
    cout << "Attack phase!" << endl;
    this->activePhase = Player::ATTACK;

    // NOTE placeholder code until team members merge
    int armies = 0;
    string sCountryName;
    string dCountryName;

    cout << "How many armies? "; cin >> armies;
    cout << "Source country: "; cin >> sCountryName;
    cout << "Destination country: "; cin >> dCountryName;

    Country *sCountry = this->getCountry(sCountryName);
    Country *dCountry = this->getCountry(dCountryName);

    this->sourceCountry = sCountry;
    this->targetCountry = dCountry;

    return true;
}

bool Player::fortify()
{
    cout << "Fortification phase!" << endl;
    this->activePhase = Player::FORTIFY;

    // NOTE placeholder code until team members merge
    int armies = 0;
    string countryName;

    cout << "How many armies? "; cin >> armies;
    cout << "Destination country: "; cin >> countryName;

    Country *country = this->getCountry(countryName);
    this->targetCountry = country;
    country->addArmies(armies);
    cout << countryName << " has now " <<
            country->getArmies() << " armies" << endl;

    return true;
}

Player::Phase Player::getActivePhase() const
{
    return this->activePhase;
}
