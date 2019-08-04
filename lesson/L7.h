#ifndef _L7_H_INCLUDE
#define _L7_H_INCLUDE

#include "IBaseDisplay.h"

class L7 : public IBaseDisplay
{
public:
    L7();
    ~L7();

    void draw();

    [[nodiscard]]
    const char *title() const;

    static IBaseDisplay *initialize();

protected:
    bool surfaceAttachToWindow();

    SDL_Texture *load_texture(const char *path);

    bool load_media();

private:
    SDL_Renderer *renderer;
};


#endif //_L7_H_INCLUDE

