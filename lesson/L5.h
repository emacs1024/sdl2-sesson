#ifndef _L5_H_INCLUDE
#define _L5_H_INCLUDE

#include "IBaseDisplay.h"

class L5: public IBaseDisplay
{
public:
    L5();
    ~L5();

    [[nodiscard]]
    const char *title() const;

    void draw();

    static IBaseDisplay *initialize();

private:
    bool load_media();

    SDL_Surface *load_surface(const char *);

private:
    SDL_Surface *stretchedSurface;
};


#endif //_L5_H_INCLUDE

