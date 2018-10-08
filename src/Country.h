//! @file
//! @author Vsevolod Ivanov

#pragma once

#include <string>

using namespace std;

class Country
{
    public:
        Country(const string name);
        ~Country();

        const string getName();

    private:
        const string name;
};
