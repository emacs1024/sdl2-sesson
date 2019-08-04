#include "IBaseDisplay.h"

#include <iostream>

IBaseDisplay::IBaseDisplay() :
    win{nullptr},
    winSurface{nullptr}
{
}

void IBaseDisplay::init( int width, int height, int posX, int posY, Uint32 initFlag, Uint32 winFlag )
{
    if (SDL_Init(initFlag) < 0)
    {
        std::cerr << "sdl init failed - " << SDL_GetError() << std::endl;
        return;
    }

    win = SDL_CreateWindow(title(), posX, posY, width, height, winFlag );
    if (nullptr == win)
    {
        std::cerr << "create SDL main window failed - " << SDL_GetError() << std::endl;
        return;
    }

    if( surfaceAttachToWindow() )
    {
        winSurface = SDL_GetWindowSurface(win);
    }
}

bool IBaseDisplay::surfaceAttachToWindow()
{
    return true;
}

IBaseDisplay::~IBaseDisplay()
{
    SDL_FreeSurface(winSurface);
    winSurface = nullptr;

    SDL_DestroyWindow(win);
    win = nullptr;

    SDL_Quit();
}
