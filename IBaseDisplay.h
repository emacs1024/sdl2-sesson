#ifndef _I_BASE_DISPLAY_H_INCLUDE
#define _I_BASE_DISPLAY_H_INCLUDE

#include <SDL2/SDL.h>

class IBaseDisplay
{
public:
    IBaseDisplay();
    virtual ~IBaseDisplay();

    // the title of window
    virtual const char *title() const = 0;

    virtual void draw() = 0;

    virtual void init( int width, int height,
                       int posX = SDL_WINDOWPOS_UNDEFINED,
                       int posY = SDL_WINDOWPOS_UNDEFINED,
                       Uint32 initFlag = SDL_INIT_VIDEO,
                       Uint32 winFlag = SDL_WINDOW_SHOWN  );

protected:
    virtual bool surfaceAttachToWindow();

protected:
    SDL_Window  *win;
    SDL_Surface *winSurface;
};


#endif//_I_BASE_DISPLAY_H_INCLUDE
