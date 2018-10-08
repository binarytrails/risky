//! @file
//! @author Vsevolod Ivanov

#include "Game.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Game *game = new Game();

    if (game->init_ui() == false)
        return 1;

    game->play();
    return 0;
}
