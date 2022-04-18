#ifndef Hurdles_h
#define Hurdles_h

#include "Player.h"

using namespace std;

class Dog
{
    public :
        Dog();
        ~Dog();

        //Surface of Dog_object
        SDL_Surface* surface = NULL;
        //Texture of Dog object
        SDL_Texture* texture = NULL;
        //The position where Dog is is to be placed
        SDL_Rect position;
        //The randomised movement of Dogs
        void move(int curr_win_width, int curr_win_height, SDL_Rect map_pos, time_t timer);
};

class Prof
{
    public :
        Prof();
        ~Prof();

        //Surface of Dog_object
        SDL_Surface* surface = NULL;
        //Texture of Dog object
        SDL_Texture* texture = NULL;
        //The position where Dog is is to be placed
        SDL_Rect position;
        //The randomised movement of Dogs
        void move(int curr_win_width, int curr_win_height, SDL_Rect map_pos, time_t timer);
};

#endif /* Hurdles_hpp */