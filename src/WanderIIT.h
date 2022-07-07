#ifndef WanderIIT_h
#define WanderIIT_h

#include <SDL2/SDL_mixer.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Hurdles.h"
#include "buttons.h"
#include "instructions.h"
#include "client.h"
#include "server.h"

using namespace std;

class WanderIIT
{
public:
    WanderIIT();
    ~WanderIIT();

    SDL_Rect Himadri;
    SDL_Rect Kailash;
    SDL_Rect Main_Building;
    SDL_Rect LHC;
    SDL_Rect Library;
    SDL_Rect Amul;
    SDL_Rect Bharti_School;
    SDL_Rect Ground;
    SDL_Rect Masala_Mix;
    SDL_Rect Rajdhani;
    SDL_Rect Hospital;
    SDL_Rect Udaigiri;
    SDL_Rect Girnar;
    SDL_Rect Satpura;
    SDL_Rect Vindhyachal;
    SDL_Rect Shivalik;
    SDL_Rect Zanskar;
    SDL_Rect SAC;
    SDL_Rect Kumaon;
    SDL_Rect Jwala;
    SDL_Rect Aravali;
    SDL_Rect Karakoram;
    SDL_Rect Nilgiri;

    int sys_type;
    //Check if the Space rectangle points to Hostel
    bool SameHostel(SDL_Rect Space, SDL_Rect Hostel);
    //Check if Position is within the Range of Hostel
    bool WithinRegion(SDL_Rect Position, SDL_Rect Area);
    //Convert Char Array to String
    string stringFromCharList (char *chrl);

    //Finish Point
    SDL_Rect FinishPoint;

    // The surface contained by the window
    SDL_Surface *ScreenSurface = NULL;
    SDL_Texture *ScreenTexture = NULL;

    SDL_Surface *WinSurface = NULL;
    SDL_Texture *WinTexture = NULL;
    SDL_Surface *LoseSurface = NULL;
    SDL_Texture *LoseTexture = NULL;
    SDL_Surface *QuitSurface = NULL;
    SDL_Texture *QuitTexture = NULL;

    SDL_Rect WinDim;
    SDL_Rect LoseDim;
    SDL_Rect QuitDim;

    // The music that will be played
    Mix_Music *Music = NULL;

    // The sound effects that will be used
    Mix_Chunk *KeyCorrect = NULL;
    Mix_Chunk *DogCollide = NULL;
    Mix_Chunk *ProfCollide = NULL;
    Mix_Chunk *Milestone = NULL;
    Mix_Chunk *Finish = NULL;

    bool isOnline;
    client* Myclient = nullptr;
    server* Myserver = nullptr;
    vector <Player*> players;
    bool init(const char *name, int xpos, int ypos, int width, int height, int sys_type);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }
    bool loadmedia();
    int Key_Reverse = 1;   // Keys work opposite when you encounter a professor untill you reach the rescue point.
    void collison();
    // Start point of the player
    SDL_Rect Start;

private:
    // The original size of the map screen
    SDL_Rect map_pos;
    // Player object dimensions
    int object_width, object_height, screen_width, screen_height, curr_win_width, curr_win_height, Dog_width, Dog_height;

    bool isRunning;

    // The window we'll be rendeing to
    SDL_Window *window = NULL;

    // The renderer object
    SDL_Renderer *renderer;
};

#endif /* WanderIIT_hpp*/