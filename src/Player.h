#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>
#include "GameMap.h"
#include <vector>

using namespace std;

#define MAX_MILESTONES 4
#define LIFE 3

class Player
{
    public :
        Player();
        ~Player();

        //Number of Milestones Completed by player
        int CompletedMilestones;
        int health;
        vector<SDL_Rect> BoysHostelsVisited;
        SDL_Rect GirlsHostelVisited;

        //Check if the player quit
        int quit;
        //check if id is already set
        bool isready;
        //Check if Player won the game
        int GameWon;
        //Surface of Player object
        SDL_Surface* surface = NULL;
        //Texture of Player object
        SDL_Texture* texture = NULL;
        //The position where Player is is to be placed
        SDL_Rect position;

        bool move(SDL_Event event, const Uint8 *state, int curr_win_width, int curr_win_height, SDL_Rect map_pos, int Key_Reverse);
};

#endif /* PLAYER_HPP */