#include "WanderIIT.h"

WanderIIT *game = nullptr;

int main ( int args, const char* argv[])
{
    game = new WanderIIT();

    game->init("WanderIIT", 0, 0, MAP_FRAME_WIDTH, MAP_FRAME_HEIGHT);
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

