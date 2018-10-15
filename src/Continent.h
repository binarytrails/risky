//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>
#include "Country.h"

using namespace std;

class Continent
{
    public:
        Continent(const string name);
        ~Continent();

        string getName() const;

    private:
        const string name;
};
