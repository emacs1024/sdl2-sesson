#include <SDL2/SDL_image.h>
#include <iostream>

#include "L7.h"

IBaseDisplay *L7::initialize()
{
    return new L7();
}

L7::L7(): IBaseDisplay(), renderer{nullptr}
{
    init(640, 480);
}

L7::~L7()
{
}

const char *L7::title() const
{
    return "SDL2.demo - 7";
}

bool L7::surfaceAttachToWindow()
{
    return false;
}

SDL_Texture *L7::load_texture(const char *path)
{
    // the final texture
    SDL_Texture *nextTexture = nullptr;

    // load image at specified path
    SDL_Surface *loadSurface = IMG_Load(path);
    if (nullptr == loadSurface)
    {
        std::cerr << "image in path " << path << " failed - " << SDL_GetError() << std::endl;
        return nullptr;
    }

    nextTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
    if (nullptr == nextTexture)
    {
        std::cerr << "unable to create surface from " << path << " - " <<  SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(loadSurface);

    return nextTexture;
}

bool L7::load_media()
{
    return true;
}

void L7::draw()
{
}


