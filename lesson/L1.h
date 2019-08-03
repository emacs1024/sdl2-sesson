
#ifndef _L1_H_INCLUDE
#define _L1_H_INCLUDE

#include "IBaseDisplay.h"

class L1 : public IBaseDisplay
{
public:
    L1();
    ~L1();

    void draw();

    [[nodiscard]]
    const char *title() const;

    static IBaseDisplay *initialize();

private:
    void load_media();

private:
    SDL_Surface *helloSurface;
};


#endif //_L1_H_INCLUDE
