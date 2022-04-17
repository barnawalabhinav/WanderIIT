#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <string>
#include <vector>

#define MAX_PLAYERS 5

using namespace std;

struct data
{
    TCPsocket socket;
    // Disconnect from client when no data received from player fo a long time
    Uint32 timeout;
    // Unique id of the player
    int id;
    data(TCPsocket sock, Uint32 t, int i) : socket(sock), timeout(t), id(i) {}
};

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDLNet_Init();

    // Identifier of players in the order they join
    int curid = 0;

    // Number of players that increases as more players join
    int playernum = 0;

    // Handle events
    SDL_Event event;

    IPaddress ip;

    // NULL indicates that this is a server
    SDLNet_ResolveHost(&ip, NULL, 1234);

    vector<data> socketvector;

    // Temporary Variable used to store incoming and outgoing data
    char tmp[1400];
    bool running = true;

    // Vector of Sockets of size maximum number of players to ensure Non-Blocking server
    SDLNet_SocketSet sockets = SDLNet_AllocSocketSet(MAX_PLAYERS);

    // Create Window to Capture Key Events
    SDL_Window *ServerWindow = SDL_CreateWindow("Server", 0, 0, 1231, 687, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_Renderer *ServerRenderer = SDL_CreateRenderer(ServerWindow, -1, SDL_RENDERER_ACCELERATED);

    // Create a socket for server
    TCPsocket server = SDLNet_TCP_Open(&ip);

    char curr_tmp1[1400];

    while (running)
    {
        // Close the server if the program has been Quit
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                running = false;

        // Check if someone is trying to connect
        TCPsocket tmpsocket = SDLNet_TCP_Accept(server);

        // If someone actually tries to connect
        if (tmpsocket)
        {
            if (playernum < MAX_PLAYERS)
            {
                // Add the socket for new player to socket vecotr
                SDLNet_TCP_AddSocket(sockets, tmpsocket);
                socketvector.push_back(data(tmpsocket, SDL_GetTicks(), curid));

                // Number of players have increased
                playernum++;
                sprintf(tmp, "0 %d \n", curid);

                // The next player id will be 1 more than than current
                curid++;
                cout << "New Connection: " << curid << '\n';
            }
            else
            {
                sprintf(tmp, "3 \n");
            }
            // Send the socket details to the client
            SDLNet_TCP_Send(tmpsocket, tmp, strlen(tmp) + 1);
        }

        // Check for incoming data
        while (SDLNet_CheckSockets(sockets, 0) > 0)
        {
            // Iterate over all the active players
            for (int i = 0; i < socketvector.size(); i++)
            {
                // Check if the player socket is ready to send data
                if (SDLNet_SocketReady(socketvector[i].socket))
                {
                    // Check for timeout
                    socketvector[i].timeout = SDL_GetTicks();

                    // Receive data from the player
                    SDLNet_TCP_Recv(socketvector[i].socket, tmp, 1400);
                    int num = stoi(tmp);

                    switch (num)
                    {

                    // Incoming data is an input to game
                    case 1:
                        for (int k = 0; k < socketvector.size(); k++)
                        {
                            // we send the data to each player except the one who sent it
                            if (k == i)
                                continue;
                            SDLNet_TCP_Send(socketvector[k].socket, tmp, strlen(tmp) + 1);
                        }
                        break;

                    // Current player has Quit
                    case 2:
                        for (int k = 0; k < socketvector.size(); k++)
                        {
                            // We send the info to each player except the one who sent it
                            if (k == i)
                                continue;
                            SDLNet_TCP_Send(socketvector[k].socket, tmp, strlen(tmp) + 1);
                        }
                        // Delete the player who quit
                        SDLNet_TCP_DelSocket(sockets, socketvector[i].socket);

                        // Close the connection with that player
                        SDLNet_TCP_Close(socketvector[i].socket);

                        // Delete the socket from socket vector
                        socketvector.erase(socketvector.begin() + i);

                        // Decrease the number of players playing the game
                        playernum--;
                        break;

                    default:
                        break;
                    }
                }

                if (SDL_GetTicks() - socketvector[i].timeout > 5000)
                {
                    sprintf (tmp, "2 %d \n", socketvector[i].id);
                    for (int k = 0; k < socketvector.size(); k++)
                    {
                        // We send the info that a player has been disconnected to each player
                        SDLNet_TCP_Send(socketvector[k].socket, tmp, strlen(tmp) + 1);
                    }
                    // Delete the player who quit
                    SDLNet_TCP_DelSocket(sockets, socketvector[i].socket);

                    // Close the connection with that player
                    SDLNet_TCP_Close(socketvector[i].socket);

                    // Delete the socket from socket vector
                    socketvector.erase(socketvector.begin() + i);

                    // Decrease the number of players playing the game
                    playernum--;
                }

                SDL_Delay(1);
            }
        }
    }

    // Close the socket of each player when the game finishes
    for (int i = 0; i < socketvector.size(); i++)
    {
        SDLNet_TCP_Close (socketvector[i].socket);
    }

    // Free the entities created
    SDLNet_FreeSocketSet(sockets);

    //Close the server
    SDLNet_TCP_Close(server);
        
    //Exit 
    SDLNet_Quit();
    SDL_Quit();
}