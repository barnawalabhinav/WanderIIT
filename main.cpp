#include "WanderIIT.hpp"

WanderIIT *game = nullptr;

int main ( int args, const char* argv[])
{
    game = new WanderIIT();

    game->init("WanderIIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1231, 687, 44, 140);
    game->loadmedia();

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->collison();
        game->render();
    }

    game->clean();

    return 0;
}

