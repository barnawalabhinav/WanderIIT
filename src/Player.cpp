#include "Player.h"

Player::Player()
{
    CompletedMilestones = 0;
    GameWon = 0;
    quit = 0;
    health = LIFE;
}

Player::~Player()
{
}

bool Player::move(SDL_Event event, const Uint8 *state, int curr_win_width, int curr_win_height, SDL_Rect map_pos, int Key_Reverse)
{
    // Handle Diagonol Movements
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP])
    {
        if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + Key_Reverse + (surface->w) / 4] != 1)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += Key_Reverse;
            }
        }
        if (map_data[(position.y - map_pos.y - Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
        {
            if (position.y > map_pos.y)
            {
                position.y -= Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP])
    {
        if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x - Key_Reverse + (surface->w) / 4] != 1)
        {
            if (position.x > map_pos.x)
            {
                position.x -= Key_Reverse;
            }
        }
        if (map_data[(position.y - map_pos.y - Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
        {
            if (position.y > map_pos.y)
            {
                position.y -= Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN])
    {
        if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + Key_Reverse + (surface->w) / 4] != 1)
        {
            if (position.x + map_pos.x + position.w < curr_win_width)
            {
                position.x += Key_Reverse;
            }
        }
        if (map_data[(position.y - map_pos.y + Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
        {
            if (position.y + map_pos.y + position.h < curr_win_height )
            {
                position.y += Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN])
    {
        if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x - Key_Reverse + (surface->w) / 4] != 1)
        {
            if (position.x > map_pos.x)
            {
                position.x -= Key_Reverse;
            }
        }
        if (map_data[(position.y - map_pos.y + Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
        {
            if (position.y + map_pos.y + position.h < curr_win_height )
            {
                position.y += Key_Reverse;
            }
        }
    }

    switch (event.type)
    {
    // Handle Orthogonol Movements
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE :
            return false;
            break;
        case SDLK_UP:
            if (map_data[(position.y - map_pos.y - Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1 && map_data[(position.y - map_pos.y - 2 + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
            {
                if (position.y > map_pos.y)
                {
                    position.y -= Key_Reverse;
                }
            }
            break;
        case SDLK_LEFT:
            if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x - Key_Reverse + (surface->w) / 4] != 1 && map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x - 2 + (surface->w) / 4] != 1)
            {
                if (position.x > map_pos.x)
                {
                    position.x -= Key_Reverse;
                }
            }
            break;
        case SDLK_DOWN:
            // Limit the surface within the screen height
            if (map_data[(position.y - map_pos.y + Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1 && map_data[(position.y - map_pos.y + 2 + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
            {
                if (position.y + map_pos.y + surface->h < curr_win_height )
                {
                    position.y += Key_Reverse;
                }
            }
            break;
        case SDLK_RIGHT:
            // Limit the surface within the screen width
            if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + Key_Reverse + (surface->w) / 4] != 1 && map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + 2 + (surface->w) / 4] != 1)
            {
                if (position.x + map_pos.x + surface->w < curr_win_width)
                {
                    position.x += Key_Reverse;
                }
            }
            break;
        default:
            break;
        }
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (map_data[(position.y - map_pos.y - Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
            {
                if (position.y > map_pos.y)
                {
                    position.y -= Key_Reverse;
                }
            }
            break;
        case SDLK_LEFT:
            if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x - Key_Reverse + (surface->w) / 4] != 1)
            {
                if (position.x > map_pos.x)
                {
                    position.x -= Key_Reverse;
                }
            }
            break;
        case SDLK_DOWN:
            // Limit the surface within the screen height
            if (map_data[(position.y - map_pos.y + Key_Reverse + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + (surface->w) / 4] != 1)
            {
                if (position.y + map_pos.y + surface->h < curr_win_height )
                {
                    position.y += Key_Reverse;
                }
            }
            break;
        case SDLK_RIGHT:
            // Limit the surface within the screen width
            if (map_data[(position.y - map_pos.y + (surface->h) / 4) * MAP_FRAME_WIDTH + position.x - map_pos.x + Key_Reverse + (surface->w) / 4] != 1)
            {
                if (position.x + map_pos.x + surface->w < curr_win_width)
                {
                    position.x += Key_Reverse;
                }
            }
            break;
        default:
            break;
        }
    default:
        break;
    }
    return true;
}