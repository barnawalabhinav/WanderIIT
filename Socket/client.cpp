#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
        return false;
    }

    if (SDLNet_Init() < 0)
    {
        printf("Couldn't initialize SDL_net: %s\n", SDLNet_GetError());
    }

    IPaddress ip;
    SDLNet_ResolveHost(&ip, "127.0.0.1", 8080);

    SDL_Event event;
    // Starting Event Loop
    SDL_PollEvent(&event);
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    const char *action = "";

    // Handle Diagonol Movements
    if (state[SDL_SCANCODE_RETURN])
    {
        action = "return";
    }
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP])
    {
        action = "RightUp";
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP])
    {
        action = "LeftUp";
    }
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN])
    {
        action = "RightDown";
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN])
    {
        action = "LeftDown";
    }

    switch (event.type)
    {
    // Handle Different Events
    case SDL_QUIT:
        action = "false";
        break;
    // Handle Orthogonol Movements
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            action = "Up";
        case SDLK_LEFT:
            action = "Left";
        case SDLK_DOWN:
            action = "Down";
        case SDLK_RIGHT:
            action = "Right";
        default:
            break;
        }
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            action = "Up";
        case SDLK_LEFT:
            action = "Left";
        case SDLK_DOWN:
            action = "Down";
        case SDLK_RIGHT:
            action = "Right";
        default:
            break;
        }
    default:
        break;
    }

    TCPsocket client = SDLNet_TCP_Open(&ip);

    SDLNet_TCP_Send(client, action, 10);

    char text[10000];

    while (SDLNet_TCP_Recv(client, text, 10000))
    {
        cout << text;
    }

    SDLNet_TCP_Close(client);
    SDLNet_Quit();
    SDL_Quit();
}