//! @file
//! @author Vsevolod (Seva) Ivanov

#pragma once

#include "SDL2/SDL.h"

class Window
{
    public:
        Window(const char* title, const Uint32 sdl_flags,
               const int width, const int height,
               const int x_pos, const int y_pos);
        ~Window();

        inline SDL_Window* getWindow() { return window; }
        inline SDL_Renderer* getRenderer() { return renderer; }

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
