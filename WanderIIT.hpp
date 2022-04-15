#ifndef WanderIIT_hpp
#define WanderIIT_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>
#include "Gamemap_back.h"
#include <fstream>
#include <vector>

using namespace std;

class WanderIIT {
    public:
        WanderIIT();
        ~WanderIIT();
        
        //int get_pixel(SDL_Surface *surface, SDL_Texture *texture, int x, int y);
        bool init(const char* name, int xpos, int ypos, int width, int height, bool fullscreen);
        void SetPixel( SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b );
        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }
        bool loadmedia( const char* obj );

    private:
        //The position where object is to be placed
        SDL_Rect offset;
        //The original size of the map screen
        SDL_Rect map_pos;
        //Player object dimensions
        int object_width, object_height, screen_width, screen_height, curr_win_width, curr_win_height;

        bool isRunning;
        
        //The window we'll be rendeing to
        SDL_Window* window = NULL;

        //The renderer object
        SDL_Renderer *renderer;

        //The surface contained by the window
        SDL_Surface* ScreenSurface = NULL;
        SDL_Texture* ScreenTexture = NULL;

        //The object we will load and show on the screen
        SDL_Surface* objectSurface = NULL;
        SDL_Texture* objectTexture = NULL;
};

#endif /* WanderIIT_hpp*/