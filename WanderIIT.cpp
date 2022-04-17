#include "WanderIIT.hpp"
//#include "glad/glad.h"

// Constructor
WanderIIT::WanderIIT()
{
    isOnline = true;
    char ip[20];

    if(isOnline)
    {
        //127.0.0.1
        cout << "Please enter your ip address : ";
        cin.getline(ip, 20);
        net = new network(ip);
    }

    Himadri.x = 949;
    Himadri.y = 141;
    Himadri.w = 4;
    Himadri.h = 8;

    Kailash.x = 945;
    Kailash.y = 178;
    Kailash.w = 4;
    Kailash.h = 6;

    LHC.x = 781;
    LHC.y = 329;
    LHC.w = 4;
    LHC.h = 4;

    Main_Building.x = 728;
    Main_Building.y = 246;
    Main_Building.w = 4;
    Main_Building.h = 4;

    Library.x = 681;
    Library.y = 298;
    Library.w = 4;
    Library.h = 4;

    Amul.x = 654;
    Amul.y = 290;
    Amul.w = 4;
    Amul.h = 4;

    Bharti_School.x = 606;
    Bharti_School.y = 315;
    Bharti_School.w = 4;
    Bharti_School.h = 4;

    Ground.x = 589;
    Ground.y = 355;
    Ground.w = 4;
    Ground.h = 4;

    Girnar.x = 443;
    Girnar.y = 205;
    Girnar.w = 3;
    Girnar.h = 4;

    Hospital.x = 474;
    Hospital.y = 315;
    Hospital.w = 4;
    Hospital.h = 2;

    Udaigiri.x = 476;
    Udaigiri.y = 167;
    Udaigiri.w = 7;
    Udaigiri.h = 4;

    Satpura.x = 397;
    Satpura.y = 191;
    Satpura.w = 5;
    Satpura.h = 4;

    Masala_Mix.x = 434;
    Masala_Mix.y = 321;
    Masala_Mix.w = 2;
    Masala_Mix.h = 8;

    Rajdhani.x = 441;
    Rajdhani.y = 302;
    Rajdhani.w = 4;
    Rajdhani.h = 8;

    Vindhyachal.x = 325;
    Vindhyachal.y = 197;
    Vindhyachal.w = 4;
    Vindhyachal.h = 5;

    Zanskar.x = 345;
    Zanskar.y = 296;
    Zanskar.w = 4;
    Zanskar.h = 4;

    Shivalik.x = 305;
    Shivalik.y = 265;
    Shivalik.w = 3;
    Shivalik.h = 3;

    SAC.x = 320;
    SAC.y = 390;
    SAC.w = 3;
    SAC.h = 3;

    Kumaon.x = 224;
    Kumaon.y = 193;
    Kumaon.w = 4;
    Kumaon.h = 2;

    Jwala.x = 162;
    Jwala.y = 226;
    Jwala.w = 4;
    Jwala.h = 4;

    Aravali.x = 169;
    Aravali.y = 296;
    Aravali.w = 5;
    Aravali.h = 5;

    Karakoram.x = 166;
    Karakoram.y = 365;
    Karakoram.w = 4;
    Karakoram.h = 4;

    Nilgiri.x = 174;
    Nilgiri.y = 438;
    Nilgiri.w = 4;
    Nilgiri.h = 4;
}
// Deconstructor
WanderIIT::~WanderIIT()
{
    delete net;
}

Player *Player1 = nullptr;

Dog *Dog0 = nullptr;
Dog *Dog1 = nullptr;
Dog *Dog2 = nullptr;
Dog *Dog3 = nullptr;
Dog *Dog4 = nullptr;
Dog *Dog5 = nullptr;
Dog *Dog6 = nullptr;
Dog *Dog7 = nullptr;
Dog *Dog8 = nullptr;
Dog *Dog9 = nullptr;

Prof *Prof0 = nullptr;
Prof *Prof1 = nullptr;
Prof *Prof2 = nullptr;
Prof *Prof3 = nullptr;
Prof *Prof4 = nullptr;

bool WanderIIT::init(const char *name, int xpos, int ypos, int width, int height, int Start_Xpos, int Start_Ypos)
{
    SDL_Window *Instrwindow = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }
    Instrwindow = SDL_CreateWindow("C++ SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1354, 687, SDL_WINDOW_SHOWN);

    SDL_Renderer *Instrrenderer = nullptr;
    Instrrenderer = SDL_CreateRenderer(Instrwindow, -1, SDL_RENDERER_ACCELERATED);
    if (TTF_Init() == -1)
    {
        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL2_ttf system ready to go!" << std::endl;
    }
    TTF_Font *ourFont = TTF_OpenFont("./fonts/8bitOperatorPlus8-Regular.ttf", 32);
    if (ourFont == nullptr)
    {
        std::cout << "Could not load font" << std::endl;
        exit(1);
    }

    SDL_Surface *surfaceText = TTF_RenderText_Blended_Wrapped(ourFont, "            * Welcome to Wander IIT! *\n* Here you have to reach your destination starting from your hostel while surpassing various hurdles! \n * Use the arraow keys to move only on the roads, though you may move diagonally using two keys together (Left+Up will take you towards North-West) \n * Encountering a dog injurs you and the very helpful community of IIT Delhi drops you at the hospital! \n * On encountering an angry Professor, you lose your mental balance and start walking insanely (your key movements reverse)! Go to your hostel to rejuvenate yourself!", {255, 255, 255}, 687);
    SDL_Texture *textureText = SDL_CreateTextureFromSurface(Instrrenderer, surfaceText);
    SDL_FreeSurface(surfaceText);
    SDL_Rect rectangle;
    rectangle.x = 20;
    rectangle.y = 20;
    rectangle.w = 1318;
    rectangle.h = 100;
    bool InstrRunning = true;
    while (InstrRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                InstrRunning = false;
            }
        }
        SDL_SetRenderDrawColor(Instrrenderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(Instrrenderer);
        SDL_RenderCopy(Instrrenderer, textureText, NULL, &rectangle);
        SDL_RenderPresent(Instrrenderer);

        SDL_Delay(3000);
        InstrRunning = false;
    }

    SDL_DestroyTexture(textureText);
    SDL_DestroyWindow(Instrwindow);
    TTF_CloseFont(ourFont);

    Start.x = Start_Xpos;
    Start.y = Start_Ypos;

    Player1 = new Player();

    Player1->position.x = Start_Xpos;
    Player1->position.y = Start_Ypos;
    map_pos.x = 0;
    map_pos.y = 0;

    Dog0 = new Dog();
    Dog1 = new Dog();
    Dog2 = new Dog();
    Dog3 = new Dog();
    Dog4 = new Dog();
    Dog5 = new Dog();
    Dog6 = new Dog();
    Dog7 = new Dog();
    Dog8 = new Dog();
    Dog9 = new Dog();

    Prof0 = new Prof();
    Prof1 = new Prof();
    Prof2 = new Prof();
    Prof3 = new Prof();
    Prof4 = new Prof();

    // Initialize all the SDL subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        isRunning = false;
        return false;
    }

    printf("Game Initialized!\n");
    /*
        //Specify OPENGL version before use
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
    */
    // Creating game window
    window = SDL_CreateWindow(name, xpos, ypos, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        printf("Window could not be created!, SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    curr_win_width = width;
    curr_win_height = height;
    printf("Window Created!\n");

    // OpenGl Setup the Graphics context
    // SDL_GLContext context;
    // context = SDL_GL_CreateContext(window);

    // Setup out function pointers
    // gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Creating the Renderer for our window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        printf("Renderer could not be created!, SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    printf("Renderer Created!\n");

    ScreenSurface = SDL_LoadBMP("Resources/map_label.bmp");
    ScreenTexture = SDL_CreateTextureFromSurface(renderer, ScreenSurface);

    if (ScreenSurface == NULL)
    {
        printf("Screen Surface could not be created!, SDL_Error: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    printf("Screen Created!\n");

    // Select the color for drawing. It is set to red here.
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    /*
        //Get window surface
        ScreenSurface = SDL_GetWindowSurface( window );
        if ( ScreenSurface == NULL ) {
            printf( "Screen Surface could not be created!, SDL_Error: %s\n", SDL_GetError() );
            isRunning = false;
            return false;
        }

        //Background Color of the surface
        SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 0, 0, 0));

        glViewport(0, 0, 640, 480);
        //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow( window );
    */
    // Accessed by the running() constructor
    isRunning = true;

    return true;
}

// Set the pixels colotr values at a position (x, y) to (r, g, b) arguments
void WanderIIT::SetPixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
    /* Once locked, surface->pixels is safe to access. */
    SDL_LockSurface(surface);
    uint8_t *pixelArray = (uint8_t *)surface->pixels;
    pixelArray[y * surface->pitch + x * surface->format->BytesPerPixel + 0] = g;
    pixelArray[y * surface->pitch + x * surface->format->BytesPerPixel + 1] = b;
    pixelArray[y * surface->pitch + x * surface->format->BytesPerPixel + 2] = r;
    SDL_UnlockSurface(surface);
}

/*
int WanderIIT::get_pixel(SDL_Surface *surface, SDL_Texture *texture, int x, int y)
{
    unsigned char* pixels;
    SDL_LockTexture( texture, NULL, (void**)&pixels, &surface->pitch );
    // access pixels
    int pixel = pixels[y*surface->pitch + x];
    SDL_UnlockTexture( texture );
    return pixel;
}
*/

bool WanderIIT::loadmedia()
{
    // Load player1
    Player1->surface = SDL_LoadBMP("Resources/Player1.bmp");
    Player1->texture = SDL_CreateTextureFromSurface(renderer, Player1->surface);
    if (Player1->surface == NULL)
    {
        printf("Unable to load the image Resources/Player1.bmp! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }
    SDL_QueryTexture(Player1->texture, NULL, NULL, &Player1->position.w, &Player1->position.h);

    // Load Dogs
    Dog0->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog0->texture = SDL_CreateTextureFromSurface(renderer, Dog0->surface);
    Dog1->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog1->texture = SDL_CreateTextureFromSurface(renderer, Dog1->surface);
    Dog2->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog2->texture = SDL_CreateTextureFromSurface(renderer, Dog2->surface);
    Dog3->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog3->texture = SDL_CreateTextureFromSurface(renderer, Dog3->surface);
    Dog4->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog4->texture = SDL_CreateTextureFromSurface(renderer, Dog4->surface);
    Dog5->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog5->texture = SDL_CreateTextureFromSurface(renderer, Dog5->surface);
    Dog6->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog6->texture = SDL_CreateTextureFromSurface(renderer, Dog6->surface);
    Dog7->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog7->texture = SDL_CreateTextureFromSurface(renderer, Dog7->surface);
    Dog8->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog8->texture = SDL_CreateTextureFromSurface(renderer, Dog8->surface);
    Dog9->surface = SDL_LoadBMP("Resources/Dog.bmp");
    Dog9->texture = SDL_CreateTextureFromSurface(renderer, Dog9->surface);

    if (Dog0->surface == NULL || Dog1->surface == NULL || Dog2->surface == NULL || Dog3->surface == NULL ||
        Dog4->surface == NULL || Dog5->surface == NULL || Dog6->surface == NULL || Dog7->surface == NULL ||
        Dog8->surface == NULL || Dog9->surface == NULL)
    {
        printf("Unable to load the Dogs Hurdle! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    printf("Dogs Created!\n");

    // Set initial position of dogs
    Dog0->position.x = 55;
    Dog0->position.y = 55;
    Dog1->position.x = 1200;
    Dog1->position.y = 670;
    Dog2->position.x = 520;
    Dog2->position.y = 236;
    Dog3->position.x = 790;
    Dog3->position.y = 600;
    Dog4->position.x = 892;
    Dog4->position.y = 410;
    Dog5->position.x = 219;
    Dog5->position.y = 600;
    Dog6->position.x = 650;
    Dog6->position.y = 350;
    Dog7->position.x = 780;
    Dog7->position.y = 350;
    Dog8->position.x = 200;
    Dog8->position.y = 200;
    Dog9->position.x = 190;
    Dog9->position.y = 45;

    // Dimensions of dog
    SDL_QueryTexture(Dog0->texture, NULL, NULL, &Dog0->position.w, &Dog0->position.h);
    SDL_QueryTexture(Dog1->texture, NULL, NULL, &Dog1->position.w, &Dog1->position.h);
    SDL_QueryTexture(Dog2->texture, NULL, NULL, &Dog2->position.w, &Dog2->position.h);
    SDL_QueryTexture(Dog3->texture, NULL, NULL, &Dog3->position.w, &Dog3->position.h);
    SDL_QueryTexture(Dog4->texture, NULL, NULL, &Dog4->position.w, &Dog4->position.h);
    SDL_QueryTexture(Dog5->texture, NULL, NULL, &Dog5->position.w, &Dog5->position.h);
    SDL_QueryTexture(Dog6->texture, NULL, NULL, &Dog6->position.w, &Dog6->position.h);
    SDL_QueryTexture(Dog7->texture, NULL, NULL, &Dog7->position.w, &Dog7->position.h);
    SDL_QueryTexture(Dog8->texture, NULL, NULL, &Dog8->position.w, &Dog8->position.h);
    SDL_QueryTexture(Dog9->texture, NULL, NULL, &Dog9->position.w, &Dog9->position.h);

    // Load Profs
    Prof0->surface = SDL_LoadBMP("Resources/Prof.bmp");
    Prof0->texture = SDL_CreateTextureFromSurface(renderer, Prof0->surface);
    Prof1->surface = SDL_LoadBMP("Resources/Prof.bmp");
    Prof1->texture = SDL_CreateTextureFromSurface(renderer, Prof1->surface);
    Prof2->surface = SDL_LoadBMP("Resources/Prof.bmp");
    Prof2->texture = SDL_CreateTextureFromSurface(renderer, Prof2->surface);
    Prof3->surface = SDL_LoadBMP("Resources/Prof.bmp");
    Prof3->texture = SDL_CreateTextureFromSurface(renderer, Prof3->surface);
    Prof4->surface = SDL_LoadBMP("Resources/Prof.bmp");
    Prof4->texture = SDL_CreateTextureFromSurface(renderer, Prof4->surface);

    if (Prof0->surface == NULL || Prof1->surface == NULL || Prof2->surface == NULL || Prof3->surface == NULL || Prof4->surface == NULL)
    {
        printf("Unable to load the Profs Hurdle! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

    printf("Profs Created!\n");

    // Set initial position of Profs
    Prof0->position.x = 651;
    Prof0->position.y = 138;
    Prof1->position.x = 773;
    Prof1->position.y = 325;
    Prof2->position.x = 735;
    Prof2->position.y = 240;
    Prof3->position.x = 315;
    Prof3->position.y = 385;
    Prof4->position.x = 960;
    Prof4->position.y = 216;

    // Dimensions of Profs
    SDL_QueryTexture(Prof0->texture, NULL, NULL, &Prof0->position.w, &Prof0->position.h);
    SDL_QueryTexture(Prof1->texture, NULL, NULL, &Prof1->position.w, &Prof1->position.h);
    SDL_QueryTexture(Prof2->texture, NULL, NULL, &Prof2->position.w, &Prof2->position.h);
    SDL_QueryTexture(Prof3->texture, NULL, NULL, &Prof3->position.w, &Prof3->position.h);
    SDL_QueryTexture(Prof4->texture, NULL, NULL, &Prof4->position.w, &Prof4->position.h);

    Music = Mix_LoadMUS( "Resources/Music.wav" );
    if( Music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    
    //Load sound effects
    Dog_collison = Mix_LoadWAV( "Resources/Dog.wav" );
    if( Dog_collison == NULL )
    {
        printf( "Failed to load Dog_collison sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    Prof_collison = Mix_LoadWAV( "Resources/Prof.wav" );
    if( Prof_collison == NULL )
    {
        printf( "Failed to load Prof_collison sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    Wall = Mix_LoadWAV( "Resources/Wall.wav" );
    if( Wall == NULL )
    {
        printf( "Failed to load Wall sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    Finish = Mix_LoadWAV( "Resources/Finish.wav" );
    if( Finish == NULL )
    {
        printf( "Failed to load Finish sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }

    return isRunning;
}

void WanderIIT::handleEvents()
{
    int win_w, win_h;

    // Handle resize of game with window size
    SDL_GetWindowSize(window, &win_w, &win_h);
    if (curr_win_width != win_w || curr_win_height != win_h)
    {
        int change_x = (win_w - curr_win_width) / 2;
        int change_y = (win_h - curr_win_height) / 2;
        map_pos.x += change_x;
        map_pos.y += change_y;
        Player1->position.x += change_x;
        Player1->position.y += change_y;
        curr_win_width = win_w;
        curr_win_height = win_h;
    }

    // Capture movement of Dogs
    Dog0->move(curr_win_width, curr_win_height, map_pos, 0);
    Dog1->move(curr_win_width, curr_win_height, map_pos, 139);
    Dog2->move(curr_win_width, curr_win_height, map_pos, 521);
    Dog3->move(curr_win_width, curr_win_height, map_pos, 54);
    Dog4->move(curr_win_width, curr_win_height, map_pos, 213);
    Dog5->move(curr_win_width, curr_win_height, map_pos, 230);
    Dog6->move(curr_win_width, curr_win_height, map_pos, 600);
    Dog7->move(curr_win_width, curr_win_height, map_pos, 71);
    Dog8->move(curr_win_width, curr_win_height, map_pos, 8139);
    Dog9->move(curr_win_width, curr_win_height, map_pos, 412);

    // Capture movement of Professors
    Prof0->move(curr_win_width, curr_win_height, map_pos, 0);
    Prof1->move(curr_win_width, curr_win_height, map_pos, 139);
    Prof2->move(curr_win_width, curr_win_height, map_pos, 521);
    Prof3->move(curr_win_width, curr_win_height, map_pos, 54);
    Prof4->move(curr_win_width, curr_win_height, map_pos, 213);

    /*
    //Capture Mouse Here
        int x, y;
        Uint32 buttons = SDL_GetMouseState(&x, &y);
        if( event.button.button == SDL_BUTTON_LEFT ) {
            SetPixel(ScreenSurface, x, y, 255, 0, 0);
        }
        if( event.button.button == SDL_BUTTON_RIGHT ) {
            SetPixel(ScreenSurface, x, y, 255, 0, 255);
        }
    */

    SDL_Event event;
    
    // Starting Event Loop
    SDL_PollEvent(&event);

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RETURN])
    {
        printf("<RETURN> is pressed.\n");
    }
    // Handle Different Events
    else if (event.type == SDL_QUIT)
    {
        isRunning = false;
        net->quit(Player1);
    }
    else
    {
        // Capture movement of player
        Player1->move(event, state, curr_win_width, curr_win_height, map_pos, Key_Reverse);
    }

    // Apply the Player1->surface image
    // SDL_BlitSurface( Player1->surface, NULL, ScreenSurface, &offset );
}

void WanderIIT::update()
{
    // Update the surface
    if(isOnline)
    {
        net->send(Player1);
        net->recv(players, Player1);
    }
}

void WanderIIT::render()
{
    // Clear the current rendering target with the drawing color
    SDL_RenderClear(renderer);
    // Get the map on the screen
    SDL_QueryTexture(ScreenTexture, NULL, NULL, &screen_width, &screen_height);
    map_pos.w = MAP_FRAME_WIDTH;
    map_pos.h = MAP_FRAME_HEIGHT;
    SDL_RenderCopy(renderer, ScreenTexture, NULL, &map_pos);
    
    // Get the Player1 on the screen
    SDL_QueryTexture(Player1->texture, NULL, NULL, &object_width, &object_height);
    Player1->position.w = object_width;
    Player1->position.h = object_height;
    SDL_RenderCopy(renderer, Player1->texture, NULL, &Player1->position);

/*
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->surface = SDL_LoadBMP("Resources/Player2.bmp");
        players[i]->texture = SDL_CreateTextureFromSurface(renderer, players[i]->surface);
        if (players[i]->surface == NULL)
        {
            printf("Unable to load the image Resources/Player2.bmp! SDL_ERROR: %s\n", SDL_GetError());
            isRunning = false;
        }
        SDL_RenderCopy(renderer, players[i]->texture, NULL, &players[i]->position);
        cout << "Player " << i+2 << " rendered!" << endl;
    }
*/
    // Update position of Dogs on the screen
    SDL_RenderCopy(renderer, Dog0->texture, NULL, &Dog0->position);
    SDL_RenderCopy(renderer, Dog1->texture, NULL, &Dog1->position);
    SDL_RenderCopy(renderer, Dog2->texture, NULL, &Dog2->position);
    SDL_RenderCopy(renderer, Dog3->texture, NULL, &Dog3->position);
    SDL_RenderCopy(renderer, Dog4->texture, NULL, &Dog4->position);
    SDL_RenderCopy(renderer, Dog5->texture, NULL, &Dog5->position);
    SDL_RenderCopy(renderer, Dog6->texture, NULL, &Dog6->position);
    SDL_RenderCopy(renderer, Dog7->texture, NULL, &Dog7->position);
    SDL_RenderCopy(renderer, Dog8->texture, NULL, &Dog8->position);
    SDL_RenderCopy(renderer, Dog9->texture, NULL, &Dog9->position);

    // Update position of Profs on the screen
    SDL_RenderCopy(renderer, Prof0->texture, NULL, &Prof0->position);
    SDL_RenderCopy(renderer, Prof1->texture, NULL, &Prof1->position);
    SDL_RenderCopy(renderer, Prof2->texture, NULL, &Prof2->position);
    SDL_RenderCopy(renderer, Prof3->texture, NULL, &Prof3->position);
    SDL_RenderCopy(renderer, Prof4->texture, NULL, &Prof4->position);

    // Update the screen with any rendering performed since the previous call
    SDL_RenderPresent(renderer);
}

void WanderIIT::collison()
{
    if (Player1->position.x - Start.x < Start.w && Start.x - Player1->position.x < Start.w && Player1->position.y - Start.y < Start.h && Start.y - Player1->position.y < Start.h)
    {
        Key_Reverse = 1;
    }

    if ((Player1->position.x - Dog0->position.x < 4 && Dog0->position.x - Player1->position.x < 4 && Player1->position.y - Dog0->position.y < 4 && Dog0->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog1->position.x < 4 && Dog1->position.x - Player1->position.x < 4 && Player1->position.y - Dog1->position.y < 4 && Dog1->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog2->position.x < 4 && Dog2->position.x - Player1->position.x < 4 && Player1->position.y - Dog2->position.y < 4 && Dog2->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog3->position.x < 4 && Dog3->position.x - Player1->position.x < 4 && Player1->position.y - Dog3->position.y < 4 && Dog3->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog4->position.x < 4 && Dog4->position.x - Player1->position.x < 4 && Player1->position.y - Dog4->position.y < 4 && Dog4->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog5->position.x < 4 && Dog5->position.x - Player1->position.x < 4 && Player1->position.y - Dog5->position.y < 4 && Dog5->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog6->position.x < 4 && Dog6->position.x - Player1->position.x < 4 && Player1->position.y - Dog6->position.y < 4 && Dog6->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog7->position.x < 4 && Dog7->position.x - Player1->position.x < 4 && Player1->position.y - Dog7->position.y < 4 && Dog7->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog8->position.x < 4 && Dog8->position.x - Player1->position.x < 4 && Player1->position.y - Dog8->position.y < 4 && Dog8->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Dog9->position.x < 4 && Dog9->position.x - Player1->position.x < 4 && Player1->position.y - Dog9->position.y < 4 && Dog9->position.y - Player1->position.y < 4))
    {
        Mix_PlayChannel( -1, Dog_collison, 0 );
        Player1->position.x = 476;
        Player1->position.y = 316;
    }

    if ((Player1->position.x - Prof0->position.x < 4 && Prof0->position.x - Player1->position.x < 4 && Player1->position.y - Prof0->position.y < 4 && Prof0->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof1->position.x < 4 && Prof1->position.x - Player1->position.x < 4 && Player1->position.y - Prof1->position.y < 4 && Prof1->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof2->position.x < 4 && Prof2->position.x - Player1->position.x < 4 && Player1->position.y - Prof2->position.y < 4 && Prof2->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof3->position.x < 4 && Prof3->position.x - Player1->position.x < 4 && Player1->position.y - Prof3->position.y < 4 && Prof3->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof4->position.x < 4 && Prof4->position.x - Player1->position.x < 4 && Player1->position.y - Prof4->position.y < 4 && Prof4->position.y - Player1->position.y < 4))
    {
        Mix_PlayChannel( -1, Prof_collison, 0 );
        Key_Reverse = -1;
    }
}

void WanderIIT::clean()
{
    // Deallocate Player1->surface surface
    SDL_FreeSurface(Player1->surface);
    Player1->surface = NULL;

    // Deallocate Screen surface
    SDL_FreeSurface(ScreenSurface);
    ScreenSurface = NULL;

     //Free the sound effects
    Mix_FreeChunk( Dog_collison );
    Mix_FreeChunk( Prof_collison );
    Mix_FreeChunk( Wall );
    Mix_FreeChunk( Finish );
    Dog_collison = NULL;
    Prof_collison = NULL;
    Wall = NULL;
    Finish = NULL;
    
    //Free the music
    Mix_FreeMusic( Music );
    Music = NULL;

    // Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    // Destroy Renderer
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Quit music subsystem
    Mix_Quit();
    // Quit SDL subsystems
    SDL_Quit();

    printf("Game Cleaned!\n");
}