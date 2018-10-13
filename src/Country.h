//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>
#include <ostream>

using namespace std;

class Country
{
    public:
        Country(const string name);
        ~Country();

        string getName() const;
        int getArmies() const;
        void setArmies(const int armies);

    private:
        const string name;
        int armies;
};

inline ostream& operator<<(ostream &output, const Country *country)
{
    output << "Country=" << country->getName() << ": ";
    output << "Armies=" << country->getArmies();
    return output;
}
