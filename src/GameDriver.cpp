//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::info);
    Game *game = new Game(Game::UI::SHELL);
    game->play();
    delete game;
    return 0;
}
