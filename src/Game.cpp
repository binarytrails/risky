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
    if (this->map != NULL)
        delete map;
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
    cout << "Welcome to Risk!" << endl;
    int nbOfPlayers;

    // 1. select a map from a list of map files as stored in a directory
    string mapName;
    MapReader mapReader;
    stringstream mapFpath; mapFpath << "./assets/maps/";
    cout << "Enter the map name (./assets/maps/): "; cin >> mapName;
    mapFpath << mapName << ".map";
    if (mapReader.read(mapFpath.str()) == false)
        return false;

    // 3. The code should then use the map loader to load the selected map
    this->map = new Map(mapReader.getNbOfNodes());
    mapReader.load(*this->map);

    // 2. select the number of players in the game (2-6 players)
    cout << "Enter the number of players: "; cin >> nbOfPlayers;
    cout << "Creating " << nbOfPlayers << " players..." << endl;
    // 4. create all the players
    for (int i = 1; i <= nbOfPlayers; ++i)
    {
        Player *player = new Player("Player" + to_string(i));
        // 5. assign dice rolling facilities to the players
        player->rollDices(1);
        // 7. assign an empty hand of cards to each player
        cout << player->getName() << " has " <<
                player->getCards().size() << " cards" << endl;
        this->addPlayer(player);
    }

    // 6. create a deck of cards

    return true;
}

void Game::play()
{
    if (this->start() == false)
        return;
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
