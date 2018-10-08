//! @file
//! @author Vsevolod Ivanov

#include "Game.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
    for (Player* player: this->players)
        delete player;
    this->players.clear();
    delete this->windowEvent;
    delete this->window;
}

bool Game::init_ui()
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

void Game::play()
{
    this->state = Game::State::RUNNING;

    while (Game::state == Game::State::RUNNING)
    {
        if (this->window != NULL)
        {
            if (this->windowEvent->type == SDL_QUIT)
                this->state = Game::State::TERMINATED;

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
