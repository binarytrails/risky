//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>

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
