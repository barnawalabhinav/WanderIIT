#include "WanderIIT.h"
//#include "glad/glad.h"

// Constructor
WanderIIT::WanderIIT()
{
    isOnline = true;
    char ip[20];

    if(isOnline)
    {
        cout << "Please enter server ip address : ";
        cin.getline(ip, 20);
        Myclient->setupConnection(ip);
    }

    Himadri.x = 949;
    Himadri.y = 141;
    Himadri.w = 4;
    Himadri.h = 8;

    Kailash.x = 945;
    Kailash.y = 178;
    Kailash.w = 4;
    Kailash.h = 6;

    LHC.x = 774;
    LHC.y = 325;
    LHC.w = 10;
    LHC.h = 8;

    Main_Building.x = 727;
    Main_Building.y = 243;
    Main_Building.w = 8;
    Main_Building.h = 8;

    Library.x = 679;
    Library.y = 294;
    Library.w = 8;
    Library.h = 8;

    Amul.x = 651;
    Amul.y = 287;
    Amul.w = 6;
    Amul.h = 6;

    Bharti_School.x = 606;
    Bharti_School.y = 315;
    Bharti_School.w = 4;
    Bharti_School.h = 4;

    Ground.x = 585;
    Ground.y = 355;
    Ground.w = 7;
    Ground.h = 3;

    Girnar.x = 440;
    Girnar.y = 202;
    Girnar.w = 4;
    Girnar.h = 7;

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
    delete Myclient;
}

Player *Player1 = nullptr;
Player *Player2 = nullptr;
buttons *object_buttons = nullptr;
instructions *object_instructions = nullptr;

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

bool WanderIIT::SameHostel(SDL_Rect Space, SDL_Rect Hostel)
{
    if (Space.x == Hostel.x && Space.y == Hostel.y && Space.w == Hostel.w && Space.h == Hostel.h)
        return true;
    else
        return false;
}

bool WanderIIT::WithinRegion(SDL_Rect Position, SDL_Rect Area)
{
    if (Position.x - Area.x < Area.w && Area.x - Position.x < Area.w && Position.y - Area.y < Area.h && Area.y - Position.y < Area.h)
        return true;
    else
        return false;
}

bool WanderIIT::init(const char *name, int xpos, int ypos, int width, int height)
{
    Player1 = new Player();
    Player2 = new Player();
    Player1->GirlsHostelVisited.x = 0;
    Player1->GirlsHostelVisited.y = 0;
    Player1->GirlsHostelVisited.w = 0;
    Player1->GirlsHostelVisited.h = 0;

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

    //Display Instructions
    object_instructions = new instructions();
    object_instructions->instructions_window(window, renderer);

    SDL_Delay(2);

    //Display Buttons
	object_buttons = new buttons();
	int hostel = object_buttons->buttons_window(window, renderer);

    //We take this input from User
    switch (hostel)
    {
    case 1:
        Start = Satpura;
        break;
    case 2:
        Start = Girnar;
        break;
    case 3:
        Start = Udaigiri;
        break;
    case 4:
        Start = Karakoram;
        break;
    case 5:
        Start = Nilgiri;
        break;
    case 6:
        Start = Aravali;
        break;
    case 7:
        Start = Kumaon;
        break;
    case 8:
        Start = Himadri;
        break;
    case 9:
        Start = Kailash;
        break;
    case 10:
        Start = Vindhyachal;
        break;
    case 11:
        Start = Zanskar;
        break;
    case 12:
        Start = Shivalik;
        break;
    case 13:
        Start = Jwala;
        break;
    default:
        break;
    }

    FinishPoint = LHC;

    Player1->position.x = Start.x;
    Player1->position.y = Start.y;

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

    Player2->surface = SDL_LoadBMP("Resources/Player2.bmp");
    Player2->texture = SDL_CreateTextureFromSurface(renderer, Player2->surface);
    if (Player2->surface == NULL)
    {
        printf("Unable to load the image Resources/Player2.bmp! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }
    SDL_QueryTexture(Player2->texture, NULL, NULL, &Player2->position.w, &Player2->position.h);

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
    Dog0->position.x = 208;
    Dog0->position.y = 221;
    Dog1->position.x = 252;
    Dog1->position.y = 418;
    Dog2->position.x = 473;
    Dog2->position.y = 320;
    Dog3->position.x = 679;
    Dog3->position.y = 366;
    Dog4->position.x = 894;
    Dog4->position.y = 214;
    Dog5->position.x = 1090;
    Dog5->position.y = 374;
    Dog6->position.x = 480;
    Dog6->position.y = 203;
    Dog7->position.x = 119;
    Dog7->position.y = 564;
    Dog8->position.x = 47;
    Dog8->position.y = 314;
    Dog9->position.x = 936;
    Dog9->position.y = 379;

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

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "Error at OpenAudio : " << Mix_GetError() << endl;
    }

    Music = Mix_LoadMUS( "Resources/Music.wav" );
    if( Music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    Mix_PlayMusic(Music, -1);
    
    //Load sound effects
    DogCollide = Mix_LoadWAV( "Resources/DogCollide.wav" );
    if( DogCollide == NULL )
    {
        printf( "Failed to load DogCollide sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    ProfCollide = Mix_LoadWAV( "Resources/ProfCollide.wav" );
    if( ProfCollide == NULL )
    {
        printf( "Failed to load ProfCollide sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    KeyCorrect = Mix_LoadWAV( "Resources/KeyCorrect.wav" );
    if( KeyCorrect == NULL )
    {
        printf( "Failed to load KeyCorrect sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        isRunning = false;
        return false;
    }
    Milestone = Mix_LoadWAV( "Resources/Milestone.wav" );
    if( Milestone == NULL )
    {
        printf( "Failed to load Milestone sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
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

    SDL_Event event;
    
    // Starting Event Loop
    SDL_PollEvent(&event);

    //Capture Mouse Here
        int x, y;
        Uint32 buttons = SDL_GetMouseState(&x, &y);
        if( event.button.button == SDL_BUTTON_LEFT ) {
            SetPixel(ScreenSurface, x, y, 255, 0, 0);
        }
        if( event.button.button == SDL_BUTTON_RIGHT ) {
            SetPixel(ScreenSurface, x, y, 255, 0, 255);
        }

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RETURN])
    {
        printf("<RETURN> is pressed.\n");
    }
    // Handle Different Events
    else if (event.type == SDL_QUIT)
    {
        isRunning = false;
        Player1->quit = 1;
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
        Myclient->sendData(Player1);
        Myclient->recvData(Player2);
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
    }

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
    //Check collison with Finish Point
    if (WithinRegion(Player1->position, FinishPoint))
    {
        if (Player1->CompletedMilestones == MAX_MILESTONES)
        {
            Player1->GameWon = 1;
                            
            //Render the Won Screen

            isRunning = false;
        }
    }

    //Check collison with own hostel
    if (WithinRegion(Player1->position, Start))
    {
        if (Key_Reverse == -1)
        {
            Mix_PlayChannel( -1, KeyCorrect, 0 );
        }
        Key_Reverse = 1;
    }
    //If the collided hostel is not own hostel, check for all hostels.
    else if (WithinRegion(Player1->position, Himadri))
    {
        if (!SameHostel(Player1->GirlsHostelVisited, Himadri) && !SameHostel(Player1->GirlsHostelVisited, Kailash))
        {
            Player1->CompletedMilestones++;
            Player1->GirlsHostelVisited = Himadri;
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Kailash))
    {
        if (!SameHostel(Player1->GirlsHostelVisited, Himadri) && !SameHostel(Player1->GirlsHostelVisited, Kailash))
        {
            Player1->CompletedMilestones++;
            Player1->GirlsHostelVisited = Kailash;
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Girnar))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Girnar))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Girnar);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Satpura))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Satpura))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Satpura);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Jwala))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Jwala))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Jwala);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Aravali))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Aravali))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Aravali);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Kumaon))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Kumaon))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Kumaon);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Karakoram))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Karakoram))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Karakoram);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Zanskar))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Zanskar))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Zanskar);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Vindhyachal))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Vindhyachal))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Vindhyachal);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Shivalik))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Shivalik))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Shivalik);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Udaigiri))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Udaigiri))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Udaigiri);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }
    else if (WithinRegion(Player1->position, Nilgiri))
    {
        bool visited = false;
        for (int i = 0; i < Player1->BoysHostelsVisited.size(); i++)
        {
            if (SameHostel(Player1->BoysHostelsVisited[i], Nilgiri))
            {
                visited = true;
                break;
            }
        }
        if (!visited && Player1->BoysHostelsVisited.size() < (MAX_MILESTONES - 1))
        {
            Player1->CompletedMilestones++;
            Player1->BoysHostelsVisited.push_back(Nilgiri);
            Mix_PlayChannel( -1, Milestone, 0 );
        }
    }

    //Check Collison with a dog
    else if ((Player1->position.x - Dog0->position.x < 4 && Dog0->position.x - Player1->position.x < 4 && Player1->position.y - Dog0->position.y < 4 && Dog0->position.y - Player1->position.y < 4) ||
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
        Mix_PlayChannel( -1, DogCollide, 0 );
        Player1->position.x = 476;
        Player1->position.y = 316;
    }

    //Check collison with a Prof
    else if ((Player1->position.x - Prof0->position.x < 4 && Prof0->position.x - Player1->position.x < 4 && Player1->position.y - Prof0->position.y < 4 && Prof0->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof1->position.x < 4 && Prof1->position.x - Player1->position.x < 4 && Player1->position.y - Prof1->position.y < 4 && Prof1->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof2->position.x < 4 && Prof2->position.x - Player1->position.x < 4 && Player1->position.y - Prof2->position.y < 4 && Prof2->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof3->position.x < 4 && Prof3->position.x - Player1->position.x < 4 && Player1->position.y - Prof3->position.y < 4 && Prof3->position.y - Player1->position.y < 4) ||
        (Player1->position.x - Prof4->position.x < 4 && Prof4->position.x - Player1->position.x < 4 && Player1->position.y - Prof4->position.y < 4 && Prof4->position.y - Player1->position.y < 4))
    {
        Mix_PlayChannel( -1, ProfCollide, 0 );
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
    Mix_FreeChunk( DogCollide );
    Mix_FreeChunk( ProfCollide );
    Mix_FreeChunk( KeyCorrect );
    Mix_FreeChunk( Milestone );
    Mix_FreeChunk( Finish );
    DogCollide = NULL;
    ProfCollide = NULL;
    KeyCorrect = NULL;
    Milestone = NULL;
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