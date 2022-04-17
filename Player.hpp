#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "GameMap.h"

using namespace std;

class Player
{
    public :
        Player();
        ~Player();

        //id of player
        int id;
        //check if id is already set
        bool isready;
        //Surface of Player object
        SDL_Surface* surface = NULL;
        //Texture of Player object
        SDL_Texture* texture = NULL;
        //The position where Player is is to be placed
        SDL_Rect position;

        void setId(int i);
        int getId();
        bool isReady();
        bool move(SDL_Event event, const Uint8 *state, int curr_win_width, int curr_win_height, SDL_Rect map_pos, int Key_Reverse);
};

#endif /* PLAYER_HPP */