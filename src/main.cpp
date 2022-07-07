#include "WanderIIT.h"

WanderIIT *game = nullptr;

int main ( int argc, char* argv[])
{
    //Defines whether system is client or server
    int sys_type = 0;
    if (argc > 1 && game->stringFromCharList(argv[argc-1]) == "1")
    {
        sys_type = 1;
    }

    game = new WanderIIT();

    game->init("WanderIIT", 0, 0, MAP_FRAME_WIDTH, MAP_FRAME_HEIGHT, sys_type);
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

