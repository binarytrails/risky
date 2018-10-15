//! @file
//! @author Vsevolod Ivanov

#include "Continent.h"

Continent::Continent(const string name): name(name)
{
}

Continent::~Continent()
{
}

string Continent::getName() const
{
    return this->name;
}
