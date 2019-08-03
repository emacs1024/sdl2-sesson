
#include <iostream>

#include "L1.h"

L1::L1(): IBaseDisplay(), helloSurface{nullptr}
{
    init(819, 460);
}

L1::~L1()
{
    SDL_FreeSurface( helloSurface );
    helloSurface = nullptr;
}

const char *L1::title() const
{
    return "SDL2.demo - 1";
}

void L1::load_media()
{
    helloSurface = SDL_LoadBMP("pics/pic_lesson_bg.bmp");
    if (nullptr == helloSurface)
    {
        std::cerr << "use SDL load bmp image failed - " << SDL_GetError() << std::endl;
    }
}

void L1::draw()
{
    load_media();
    if (nullptr == helloSurface)
    {
        return;
    }

    // apply the image
    SDL_BlitSurface(helloSurface, nullptr, winSurface, nullptr);

    // update the surface
    SDL_UpdateWindowSurface( win );

    // wait 5 seconds
    SDL_Delay( 5000 );
}

IBaseDisplay *L1::initialize()
{
    return new L1();
}

