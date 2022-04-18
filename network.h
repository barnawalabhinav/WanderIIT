#ifndef NETWORK_H
#define NETWORK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Hurdles.h"

class network
{
    SDLNet_SocketSet server;
    TCPsocket connection;
    char tmp[1400];
    public :
        network(const char* ip);
        ~network();
        void send(Player *p);
        void quit(Player *p);
        void recv (vector<Player*>&players, Player *p);
};

#endif /* NETWORK_H */