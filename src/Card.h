//! @file
//! @author ...

#pragma once

#include <string>

using namespace std;

class Card
{
    public:
        enum Type {
            Infantry, Cavalry, Artillery
        };

        Card(const Type type);
        ~Card();

        Type getType() const;
        string getTypeName() const;

    private:
        const Type type;
};
