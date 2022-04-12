#include "WanderIIT.hpp"

WanderIIT::WanderIIT()
{}
WanderIIT::~WanderIIT()
{}

void WanderIIT::init (const char *name, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if( fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
    {
        printf( "Subsystems Initialised!\n" );

        window = SDL_CreateWindow( name, xpos, ypos, width, height, flags );
        if( window )
        {
            printf( "Window Created!\n" );
        }

        renderer = SDL_CreateRenderer( window, -1, 0);
        if( renderer )
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf( "Renderer Created!\n" );
        }

        isRunning = true;
    }
    else {
        isRunning = false;
    }
}

void WanderIIT::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type) {
        case SDL_QUIT :
            isRunning = false;
            break;
        default :
            break;
    }
}

void WanderIIT::update()
{

}

void WanderIIT::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void WanderIIT::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf( "Game Cleaned!\n" );
}