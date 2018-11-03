//! @file
//! @author Vsevolod Ivanov

#include "Game.h"

using namespace std;

Game::Game(Game::UI ui): ui(ui)
{
    switch(ui)
    {
        case Game::UI::SDL2:
            this->init_sdl2();
            break;
        case Game::UI::SHELL:
        default:
            break;
    }
}

Game::~Game()
{
    for (Player* player: this->players)
        delete player;
    this->players.clear();
    delete this->windowEvent;
    delete this->window;
}

bool Game::init_sdl2()
{
    SDL_Init(SDL_INIT_VIDEO);
    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

    this->window = new Window(
        "Risky Business", flags, 800, 500, 100, 100
    );
    if (this->window->getWindow() == NULL)
    {
        cerr << "Failed to create SDL window" << endl;
        return false;
    }
    this->windowEvent = new SDL_Event();
    return true;
}

/* Part 1: Game start
 * You must deliver a driver that demonstrates:
 * 1. different valid maps can be loaded
 *    their validity is verified (i.e. it is a connected graph, etc)
 *    invalid maps are gracefully rejected
 * 2. the right number of players is created
 *    a deck with the right number of cards is created
 */
bool Game::start()
{
    cout << "Game::start()" << endl;
    // 1. select a map from a list of map files as stored in a directory
    // 2. select the number of players in the game (2-6 players)
    // 3. The code should then use the map loader to load the selected map
    // 4. create all the players
    // 5. assign dice rolling facilities to the players
    // 6. create a deck of cards
    // 7. assign an empty hand of cards to each player
    return true;
}

void Game::play()
{
    if (this->start())
        this->state = Game::State::RUN;

    while (Game::state == Game::State::RUN)
    {
        // SDL2
        if (this->window != NULL)
        {
            if (this->windowEvent->type == SDL_QUIT)
                this->state = Game::State::HALT;
            SDL_PollEvent(this->windowEvent);
            SDL_RenderClear(this->window->getRenderer());
            SDL_RenderPresent(this->window->getRenderer());
        }
    }
}

bool Game::addPlayer(Player *player)
{
    this->players.push_back(player);
    return true;
}
