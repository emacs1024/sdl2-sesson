#ifndef _L2_H_INCLUDE
#define _L2_H_INCLUDE

#include "IBaseDisplay.h"

class L2 : public IBaseDisplay
{
public:
    L2();
    ~L2();

    void draw();

    [[nodiscard]]
    const char *title() const;

    static IBaseDisplay *initialize();

private:
    void load_media();

private:
    SDL_Surface *xOut;
};


#endif //_L2_H_INCLUDE
