//! @file
//! @author Vsevolod (Seva) Ivanov

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include "Window.h"

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    Window* window = new Window(
        "Risky Business", flags, 800, 500, 100, 100
    );

    if (window->getWindow() == NULL)
    {
        cerr << "Failed to create SDL window" << endl;
        return 1;
    }

    bool quit = false;
    SDL_Event* sdlEvent = new SDL_Event();

    while (!quit && sdlEvent->type != SDL_QUIT)
    {
        SDL_PollEvent(sdlEvent);
        SDL_RenderClear(window->getRenderer());
        SDL_RenderPresent(window->getRenderer());
    }

    delete sdlEvent;
    delete window;
    return 0;
}
