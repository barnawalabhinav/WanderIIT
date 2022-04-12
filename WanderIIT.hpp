#ifndef WanderIIT_hpp
#define WanderIIT_hpp

#include <SDL2/SDL.h>
#include <iostream>

class WanderIIT {
    public:
        WanderIIT();
        ~WanderIIT();

        void init(const char* name, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }

    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif /* WanderIIT_hpp*/