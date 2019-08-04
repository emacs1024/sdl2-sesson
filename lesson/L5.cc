#include "L5.h"

#include <iostream>

SDL_Surface *L5::load_surface(const char *path)
{
    // the final optimized image
    SDL_Surface *optimizedSurface = nullptr;

    // load image at specified path
    SDL_Surface *loadSurface = SDL_LoadBMP(path);
    if(nullptr == loadSurface)
    {
        std::cerr << "unable to load image " << path << " failed - " << SDL_GetError() << std::endl;
        return nullptr;
    }

    optimizedSurface = SDL_ConvertSurface( loadSurface, winSurface->format, 0);
    if(nullptr == optimizedSurface)
    {
        std::cerr << "unable to optimize image " << path << " failed - " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(loadSurface);
    return optimizedSurface;
}

const char *L5::title() const
{
    return "SDL2.demo - 5";
}

IBaseDisplay *L5::initialize()
{
    return new L5();
}

void L5::draw()
{
    if ( !load_media() )
    {
        std::cerr << "load media failed" << std::endl;
        return;
    }

    bool      quit = false;
    SDL_Event event;

    while ( !quit )
    {
        // user request quit
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // apply the image stretched
        SDL_Rect stretchRect;
        stretchRect.x = 0;
        stretchRect.y = 0;
        stretchRect.w = 640;
        stretchRect.h = 480;

        SDL_BlitScaled(stretchedSurface, nullptr, winSurface, &stretchRect);
        SDL_UpdateWindowSurface(win);
    }
}

bool L5::load_media()
{
    stretchedSurface = load_surface("pics/lesson_stretch.bmp");
    if(nullptr == stretchedSurface)
    {
        std::cerr << "load stretched surface failed" << std::endl;
        return false;
    }
    return true;
}

L5::L5(): IBaseDisplay(), stretchedSurface{nullptr}
{
    init(819, 460);
}

L5::~L5()
{
    SDL_FreeSurface( stretchedSurface );
    stretchedSurface = nullptr;
}
