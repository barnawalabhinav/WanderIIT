#ifndef buttons_hpp
#define buttons_hpp

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 722;
const int SCREEN_HEIGHT = 480;

class buttons
{
    public:
        buttons();
        ~buttons();
        int buttons_window(SDL_Window *window, SDL_Renderer *render);
};

#endif