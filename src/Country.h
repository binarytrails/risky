//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>
#include <ostream>
#include "Continent.h"

using namespace std;

class Country
{
    public:
        Country(); // boost
        Country(const string name, Continent *continent);
        ~Country();

        Continent* getContinent();
        string getName() const;
        int getArmies() const;
        void setArmies(const int armies);

    private:
        Continent *continent;
        const string name;
        int armies;
};

inline ostream& operator<<(ostream &output, Country *country)
{
    output << "Country=" << country->getName() << ":";
    Continent* continent = country->getContinent();
    output << " Continent=" << continent->getName();
    output << " Armies=" << country->getArmies();
    return output;
}
