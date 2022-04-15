#include "WanderIIT.hpp"

WanderIIT *game = nullptr;

int main ( int args, const char* argv[])
{
    game = new WanderIIT();

    game->init("WanderIIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1354, 687, false);
    game->loadmedia("Resources/player.bmp");

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}

