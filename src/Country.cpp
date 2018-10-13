//! @file
//! @author Vsevolod Ivanov

#include "Country.h"

using namespace std;

Country::Country()
{
}

Country::Country(const string name, Continent *continent):
    name(name), continent(continent)
{
}

Country::~Country()
{
}

string Country::getName() const
{
    return this->name;
}

Continent* Country::getContinent()
{
    return this->continent;
}

int Country::getArmies() const
{
    return this->armies;
}

void Country::setArmies(const int armies)
{
    if (armies < 0)
        throw -1;

    this->armies = armies;
}
