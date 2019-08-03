#ifndef _L4_H_INCLUDE
#define _L4_H_INCLUDE

#include "IBaseDisplay.h"

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};


class L4 : public IBaseDisplay
{
public:
    L4();
    ~L4();

    [[nodiscard]]
    const char *title() const;

    void draw();

    static IBaseDisplay *initialize();

private:
    bool load_media();

private:
    SDL_Surface *keyPressSurface[KEY_PRESS_SURFACE_TOTAL];
};


#endif //_L4_H_INCLUDE
