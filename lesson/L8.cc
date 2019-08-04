#include "L8.h"

#include <iostream>
#include <SDL2/SDL_image.h>

static const int WIDTH{640};
static const int HEIGHT{480};

IBaseDisplay *L8::initialize()
{
    return new L8();
}

L8::L8(): IBaseDisplay(), renderer{nullptr}
{
    init(WIDTH, HEIGHT);
}

const char *L8::title() const
{
    return "SDL2.demo - 8";
}

L8::~L8()
{
    SDL_DestroyRenderer( renderer );
    renderer = nullptr;

    IMG_Quit();
}

void L8::init( int width, int height, int posX, int posY, Uint32 initFlag, Uint32 winFlag )
{
    if (SDL_Init(initFlag) < 0)
    {
        std::cerr << "sdl init failed - " << SDL_GetError() << std::endl;
        return;
    }
    // Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
    }

    win = SDL_CreateWindow(title(), posX, posY, width, height, winFlag );
    if (nullptr == win)
    {
        std::cerr << "create SDL main window failed - " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED );
    if (nullptr == renderer)
    {
        std::cerr << "create renderer failed - " << SDL_GetError() << std::endl;
        return;
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    int imageFlags = IMG_INIT_PNG;
    if ( !( IMG_Init( imageFlags ) & imageFlags ) )
    {
        std::cerr << "SDL_image could not initialize failed - " << SDL_GetError() << std::endl;
        return;
    }
}

SDL_Texture *L8::load_texture(const char *path)
{
    // the final texture
    SDL_Texture *nextTexture = nullptr;

    // load image at specified path
    SDL_Surface *loadSurface = IMG_Load(path);
    if (nullptr == loadSurface)
    {
        std::cerr << "unable to load image in " << path << " failed - " << SDL_GetError() << std::endl;
        return nullptr;
    }

    nextTexture = SDL_CreateTextureFromSurface( renderer, loadSurface );
    if (nullptr == nextTexture )
    {
        std::cerr << "Unable to create texture from " << path << " failed - " <<  SDL_GetError() << std::endl;
    }
    SDL_FreeSurface( loadSurface );
    return nextTexture;
}

void L8::draw()
{
    bool      quit = false;
    SDL_Event event;

    while (!quit)
    {
        // Handle events on queue
        while( SDL_PollEvent( &event ) != 0 )
        {
            //User requests quit
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );

        //Render red filled quad
        SDL_Rect fillRect = { WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2 };
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( renderer, &fillRect );

        //Render green outlined quad
        SDL_Rect outlineRect = { WIDTH / 6, HEIGHT / 6, WIDTH * 2 / 3, HEIGHT * 2 / 3 };
        SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );
        SDL_RenderDrawRect( renderer, &outlineRect );

        //Draw blue horizontal line
        SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine( renderer, 0, HEIGHT / 2, WIDTH, HEIGHT / 2 );

        //Draw vertical line of yellow dots
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
        for( int i = 0; i < HEIGHT; i += 4 )
        {
            SDL_RenderDrawPoint( renderer, WIDTH / 2, i );
        }

        //Update screen
        SDL_RenderPresent( renderer );
    }
}
