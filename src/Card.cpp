//! @file
//! @author ...

#include "Card.h"

using namespace std;

Card::Card(const Card::Type type): type(type)
{
}

Card::~Card()
{
}

Card::Type Card::getType() const
{
    return this->type;
}

string Card::getTypeName() const
{
    string typeName;

    switch (this->type)
    {
        case Card::Type::Infantry:
            typeName = "Infantry";
            break;

        case Card::Type::Cavalry:
            typeName = "Cavalry";
            break;

        case Card::Type::Artillery:
            typeName = "Artillery";
            break;
    }

    if (typeName.empty())
        throw -1;

    return typeName;
}
