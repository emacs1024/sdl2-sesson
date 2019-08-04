#ifndef _L8_H_INCLUDE
#define _L8_H_INCLUDE

#include "IBaseDisplay.h"

class L8: public IBaseDisplay
{
public:
    L8();
    ~L8();

    void init( int width, int height,
               int posX = SDL_WINDOWPOS_UNDEFINED,
               int posY = SDL_WINDOWPOS_UNDEFINED,
               Uint32 initFlag = SDL_INIT_VIDEO,
               Uint32 winFlag = SDL_WINDOW_SHOWN  );

    void draw();

    [[nodiscard]]
    const char *title() const;

    static IBaseDisplay *initialize();

private:
    SDL_Texture *load_texture(const char *path);

private:
    SDL_Renderer *renderer;

};


#endif //_L8_H_INCLUDE

