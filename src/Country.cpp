//! @file
//! @author Vsevolod Ivanov

#include "Country.h"

using namespace std;

Country::Country(const string name): name(name)
{
}

Country::~Country()
{
}

const string Country::getName()
{
    return this->name;
}
