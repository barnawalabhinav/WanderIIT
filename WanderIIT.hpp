#ifndef WanderIIT_hpp
#define WanderIIT_hpp

#include <SDL2/SDL_mixer.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "Hurdles.hpp"

using namespace std;

class WanderIIT
{
public:
    WanderIIT();
    ~WanderIIT();

    // The surface contained by the window
    SDL_Surface *ScreenSurface = NULL;
    SDL_Texture *ScreenTexture = NULL;

    // The object we will load and show on the screen
    SDL_Surface *objectSurface = NULL;
    SDL_Texture *objectTexture = NULL;

    // The music that will be played
    Mix_Music *Music = NULL;

    // The sound effects that will be used
    Mix_Chunk *Dog_collison = NULL;
    Mix_Chunk *Prof_collison = NULL;
    Mix_Chunk *Wall = NULL;
    Mix_Chunk *Finish = NULL;

    // int get_pixel(SDL_Surface *surface, SDL_Texture *texture, int x, int y);
    bool init(const char *name, int xpos, int ypos, int width, int height, int Start_Xpos, int Start_Ypos);
    void SetPixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    bool loadmedia();
    int Key_Reverse = 1;   // Keys work opposite when you encounter a professor untill you reach the rescue point.
    SDL_Rect rescue_point; // Reach here to rescue yourself from Angry Professors
    void collison();

private:
    // The position where object is to be placed
    SDL_Rect offset;
    // The original size of the map screen
    SDL_Rect map_pos;
    // Start point of the player
    SDL_Rect Start;
    // Player object dimensions
    int object_width, object_height, screen_width, screen_height, curr_win_width, curr_win_height, Dog_width, Dog_height;

    bool isRunning;

    // The window we'll be rendeing to
    SDL_Window *window = NULL;

    // The renderer object
    SDL_Renderer *renderer;
};

#endif /* WanderIIT_hpp*/