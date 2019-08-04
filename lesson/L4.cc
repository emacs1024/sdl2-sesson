#include "L4.h"

#include <iostream>

static SDL_Surface *loadSurface(const char *path)
{
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (nullptr == surface)
    {
        std::cerr << "create sdl surface by image in " << path << " failed - " << SDL_GetError() << std::endl;
    }
    return surface;
}

IBaseDisplay *L4::initialize()
{
    return new L4();
}


L4::L4()
{
    init(819, 460);
}

L4::~L4()
{
    for(auto& surface : keyPressSurface)
    {
        SDL_FreeSurface( surface );
        surface = nullptr;
    }
}

const char *L4::title() const
{
    return "SDL2.demo - 4";
}

bool L4::load_media()
{
    // load default surface image
    keyPressSurface[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("pics/pic_lesson_bg.bmp");
    if(nullptr == keyPressSurface[KEY_PRESS_SURFACE_DEFAULT])
    {
        std::cerr << "failed to load default image - " << SDL_GetError() << std::endl;
        return false;
    }

    // load up surface
    keyPressSurface[KEY_PRESS_SURFACE_UP] = loadSurface("pics/lesson_key_up.bmp");
    if(nullptr == keyPressSurface[KEY_PRESS_SURFACE_UP])
    {
        std::cerr << "failed to load up image - " << SDL_GetError() << std::endl;
        return false;
    }

    // load down surface
    keyPressSurface[KEY_PRESS_SURFACE_DOWN] = loadSurface("pics/lesson_key_down.bmp");
    if(nullptr == keyPressSurface[KEY_PRESS_SURFACE_DOWN])
    {
        std::cerr << "failed to load down image - " << SDL_GetError() << std::endl;
        return false;
    }

    // load left surface
    keyPressSurface[KEY_PRESS_SURFACE_LEFT] = loadSurface("pics/lesson_key_left.bmp");
    if(nullptr == keyPressSurface[KEY_PRESS_SURFACE_LEFT])
    {
        std::cerr << "failed to load left image - " << SDL_GetError() << std::endl;
        return false;
    }

    // load right surface
    keyPressSurface[KEY_PRESS_SURFACE_RIGHT] = loadSurface("pics/lesson_key_right.bmp");
    if(nullptr == keyPressSurface[KEY_PRESS_SURFACE_RIGHT])
    {
        std::cerr << "failed to load right image - " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void L4::draw()
{
    if (win == nullptr)
    {
        std::cerr << "create window use sdl2 failed" << std::endl;
        return;
    }

    if ( !load_media() )
    {
        std::cerr << "load image failed" << std::endl;
        return;
    }

    bool         quit = false;
    SDL_Event    event;
    SDL_Surface *currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ];

    //Apply the current image
    SDL_BlitSurface( currentSurface, nullptr, winSurface, nullptr );

    //Update the surface
    SDL_UpdateWindowSurface( win );

    while ( !quit )
    {
        while ( SDL_PollEvent( &event ) != 0 )
        {
            // User requests quit
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
            // User presses a key
            else if( event.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
                        currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_UP ];
                        break;

                    case SDLK_DOWN:
                        currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_DOWN ];
                        break;

                    case SDLK_LEFT:
                        currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_LEFT ];
                        break;

                    case SDLK_RIGHT:
                        currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_RIGHT ];
                        break;

                    default:
                        currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ];
                        break;
                }
            }

            //Apply the current image
            SDL_BlitSurface( currentSurface, nullptr, winSurface, nullptr );

            //Update the surface
            SDL_UpdateWindowSurface( win );
        }
    }

}


