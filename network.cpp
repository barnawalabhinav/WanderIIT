#include "network.hpp"

network::network(const char *ipchar)
{
    SDLNet_Init();
    IPaddress ip;
    if (SDLNet_ResolveHost(&ip, ipchar, 8080) == -1)
        cout << "Error Encountered while connecting to server!" << endl;
    connection = SDLNet_TCP_Open(&ip);
    if (connection == NULL)
        cout << "Error encountered due to bad ip address!" << endl;
    server = SDLNet_AllocSocketSet(20);
    SDLNet_TCP_AddSocket(server, connection);
}

network::~network()
{
    SDLNet_TCP_Send(connection, "2 \n", 4);
    SDLNet_TCP_Close(connection);
    SDLNet_FreeSocketSet(server);
    SDLNet_Quit();
}

void network::send(Player *p)
{
    if (p->isReady())
    {
        SDL_Rect pos = p->position;
        // 1 id position
        sprintf(tmp, "1 %d %d %d %d %d \n", p->getId(), pos.x, pos.y, pos.w, pos.h);

        int size = 0;
        int len = strlen(tmp) + 1;

        // Handling cases of incomplete transfer of data
        while (size < len)
        {
            size += SDLNet_TCP_Send(connection, tmp + size, len - size);
        }
    }
}

void network::quit(Player *p)
{
    sprintf(tmp, "2 %d \n", p->id);
    SDLNet_TCP_Send(connection, tmp, strlen(tmp) + 1);
}

void network::recv(vector<Player *> &players, Player *p)
{
    while (SDLNet_CheckSockets(server, 0) > 0 && SDLNet_SocketReady(connection))
    {
        // size of data received
        int offset = 0;
        
        do
        {
            offset += SDLNet_TCP_Recv(connection, tmp + offset, 1400);
            if (offset <= 0)
                return;
        } while (tmp[strlen(tmp) - 1] != '\n');

        int type, id;
        sscanf(tmp, "%d %d", &type, &id);
        if (type == 0)
        {
            p->setId(id);
            cout << "My id is " << id << endl;
        }
        else if (type == 1)
        {
            int i = 0, x, y, w, h;
            for (i = 0; i < players.size(); i++)
            {
                if (players[i]->id == id)
                {
                    int tmp2;
                    sscanf(tmp, "1 %d %d %d %d %d \n", &tmp2, &x, &y, &w, &h);
                    players[i]->position.x = x;
                    players[i]->position.y = y;
                    players[i]->position.w = w;
                    players[i]->position.h = h;
                    break;
                }
            }
            if (i >= players.size())
            {
                int tmp2;
                Player *p_new = new Player();
                p_new->setId(id);
                sscanf(tmp, "1 %d %d %d %d %d \n", &tmp2, &x, &y, &w, &h);
                p_new->position.x = x;
                p_new->position.y = y;
                p_new->position.w = w;
                p_new->position.h = h;
                players.push_back(p_new);
            }
        }
        else if (type == 2)
        {
            for (int i = 0; i < players.size(); i++)
            {
                if (players[i]->getId() == id)
                    players.erase(players.begin() + i);
            }
        }
        else
        {
            // do nothing
        }
    }
}