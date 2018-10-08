//! @file
//! @author Vsevolod Ivanov

#include "Window.h"

Window::Window(const char* title, const Uint32 sdl_flags,
               const int width, const int height,
               const int x_pos, const int y_pos)
{
    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, sdl_flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_UpdateWindowSurface(window);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
