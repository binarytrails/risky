//! @file
//! @author Vsevolod Ivanov

#include <stdlib.h>
#include "PlayerDice.h"

using namespace std;

PlayerDice::PlayerDice()
{
}

PlayerDice::~PlayerDice()
{
}

int PlayerDice::roll()
{
    return (rand() % 6) + 1;
}
