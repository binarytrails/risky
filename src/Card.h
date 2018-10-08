//! @file
//! @author ...

#pragma once

#include <string>

using namespace std;

class Card
{
    public:
        Card(const string name);
        ~Card();

        const string getName();

    private:
        const string name;
};
