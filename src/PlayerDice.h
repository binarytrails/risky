//! @file
//! @author Vsevolod Ivanov

#pragma once

class PlayerDice
{
    public:
        PlayerDice();
        ~PlayerDice();

        int roll();

        const int numberOfSides = 6;
};
