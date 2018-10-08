//! @file
//! @author ...

#include "Card.h"

using namespace std;

Card::Card(const string name): name(name)
{
}

Card::~Card()
{
}

const string Card::getName()
{
    return this->name;
}
