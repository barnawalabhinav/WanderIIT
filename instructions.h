#ifndef instructions_hpp
#define instructions_hpp


#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH_instruct = 1004;
const int SCREEN_HEIGHT_instruct = 697;

class instructions
{
    public:
        instructions();
        ~instructions();
        int instructions_window(SDL_Window *window, SDL_Renderer *render);
};

#endif