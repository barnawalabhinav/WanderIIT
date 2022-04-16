#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }
    window = SDL_CreateWindow("C++ SDL2 Window", 20, 20, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (TTF_Init() == -1)
    {
        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL2_ttf system ready to go!" << std::endl;
    }
    TTF_Font *ourFont = TTF_OpenFont("./fonts/8bitOperatorPlus8-Regular.ttf", 32);
    if (ourFont == nullptr)
    {
        std::cout << "Could not load font" << std::endl;
        exit(1);
    }
    SDL_Surface *surfaceText = TTF_RenderText_Blended_Wrapped(ourFont, "Instructions \n nomber 1", {255, 255, 255}, 300);
    SDL_Texture *textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_FreeSurface(surfaceText);
    SDL_Rect rectangle;
    rectangle.x = 20;
    rectangle.y = 20;
    rectangle.w = 800;
    rectangle.h = 200;
    bool gameIsRunning = true;
    while (gameIsRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameIsRunning = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textureText, NULL, &rectangle);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(textureText);
    SDL_DestroyWindow(window);
    TTF_CloseFont(ourFont);
    SDL_Quit();
    return 0;
}