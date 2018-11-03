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

void Game::play()
{
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
