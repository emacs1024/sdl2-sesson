
#include <iostream>

#include "L2.h"

L2::L2(): IBaseDisplay(), xOut{nullptr}
{
    init(819, 460);
}

L2::~L2()
{
    SDL_FreeSurface( xOut );
    xOut = nullptr;
}

const char *L2::title() const
{
    return "SDL2.demo - 2";
}

void L2::load_media()
{
    xOut = SDL_LoadBMP("pics/pic_lesson_bg.bmp");
    if (nullptr == xOut)
    {
        std::cerr << "use SDL load bmp image failed - " << SDL_GetError() << std::endl;
    }
}

void L2::draw()
{
    if(nullptr == win)
    {
        std::cerr << "can not create sdl window." << std::endl;
        return;
    }

    load_media();
    if (nullptr == xOut)
    {
        std::cerr << "can't create surface by image" << std::endl;
        return;
    }

    bool      quit{false};
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent( &event ) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_BlitSurface(xOut, nullptr, winSurface, nullptr);

        SDL_UpdateWindowSurface(win);
    }
}

IBaseDisplay *L2::initialize()
{
    return new L2();
}
