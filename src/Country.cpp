//! @file
//! @author Vsevolod Ivanov

#include "Country.h"

using namespace std;

Country::Country()
{
}

Country::Country(string name): name(name)
{
}

Country::~Country()
{
}

string Country::getName() const
{
    return this->name;
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
