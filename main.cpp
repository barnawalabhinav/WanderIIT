#include "WanderIIT.hpp"

WanderIIT *game = nullptr;

int main ( int args, const char* argv[])
{
    game = new WanderIIT();
    game->Start = game->Himadri;

    game->init("WanderIIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAP_FRAME_WIDTH, MAP_FRAME_HEIGHT, game->Start.x, game->Start.y);
    game->loadmedia();

    while (game->running()) {
        game->handleEvents();
        game->collison();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}

