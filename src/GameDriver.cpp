//! @file
//! @author Vsevolod Ivanov

#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game *game = new Game(Game::UI::SHELL);

    Player *player1 = new Player("Player1");
    game->addPlayer(player1);

    game->play();

    delete game;
    return 0;
}
