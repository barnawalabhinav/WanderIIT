#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Hurdles.hpp"

class network
{
    SDLNet_SocketSet server;
    TCPsocket connection;
    char tmp[1400];
    public :
        Player *Player2 = nullptr;
        Player *Player3 = nullptr;
        Player *Player4 = nullptr;
        Player *Player5 = nullptr;
        network(const char* ip);
        ~network();
        void send(Player *p);
        void quit(Player *p);
        void recv (vector<Player*>&players, Player *p);
};

#endif /* NETWORK_HPP */