#include "Hurdles.h"

// Dog Constructor
Dog::Dog() {}
// Dog Deconstructor
Dog::~Dog() {}

// Dog Constructor
Prof::Prof() {}
// Dog Deconstructor
Prof::~Prof() {}

void Dog::move(int curr_win_width, int curr_win_height, SDL_Rect map_pos, time_t timer)
{
    srand(time(NULL) + timer);
    int DogMove = rand() % 4;
    switch (DogMove)
    {
    case 0:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x - 1 + (surface->w) / 2] != 25)
        {
            if (position.x > map_pos.x)
            {
                position.x -= 1;
            } // Move Left
        }
        break;
    case 1:
        if (map_data[(position.y - 1 - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 25)
        {
            if (position.y > map_pos.y)
            {
                position.y -= 1;
            } // Move Up
        }
        break;
    case 2:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + 1 + (surface->w) / 2] != 25)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += 1;
            } // Move Right
        }
        break;
    case 3:
        if (map_data[(position.y - map_pos.y + 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 25)
        {
            if (position.y + map_pos.y + position.h < curr_win_height)
            {
                position.y += 1;
            } // Move Down
        }
        break;
    default:
        break;
    }
}

void Prof::move(int curr_win_width, int curr_win_height, SDL_Rect map_pos, time_t timer)
{
    srand(time(NULL) + timer);
    int ProfMove = rand() % 8;
    switch (ProfMove)
    {
    case 0:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x - 1 + (surface->w) / 2] != 1)
        {
            if (position.x > map_pos.x)
            {
                position.x -= 1;
            } // Move Left
        }
        break;
    case 1:
        if (map_data[(position.y - 1 - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y > map_pos.y)
            {
                position.y -= 1;
            } // Move Up
        }
        break;
    case 2:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + 1 + (surface->w) / 2] != 1)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += 1;
            } // Move Right
        }
        break;
    case 3:
        if (map_data[(position.y - map_pos.y + 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y + map_pos.y + position.h < curr_win_height)
            {
                position.y += 1;
            } // Move Down
        }
        break;
    case 4:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + 1 + (surface->w) / 2] != 1)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += 1;
            }
        }
        if (map_data[(position.y - map_pos.y - 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y > map_pos.y)
            {
                position.y -= 1;
            }
        }
    case 5:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x - 1 + (surface->w) / 2] != 1)
        {
            if (position.x > map_pos.x)
            {
                position.x -= 1;
            }
        }
        if (map_data[(position.y - map_pos.y - 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y > map_pos.y)
            {
                position.y -= 1;
            }
        }
    case 6:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + 1 + (surface->w) / 2] != 1)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += 1;
            }
        }
        if (map_data[(position.y - map_pos.y + 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y + map_pos.y + position.h < curr_win_height)
            {
                position.y += 1;
            }
        }
    case 7:
        if (map_data[(position.y - map_pos.y + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x - 1 + (surface->w) / 2] != 1)
        {
            if (position.x > map_pos.x)
            {
                position.x -= 1;
            }
        }
        if (map_data[(position.y - map_pos.y + 1 + (surface->h) / 2) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 2] != 1)
        {
            if (position.y + map_pos.y + position.h < curr_win_height)
            {
                position.y += 1;
            }
        }
    default:
        break;
    }
}