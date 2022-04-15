#include "WanderIIT.hpp"
//#include "glad/glad.h"

// Constructor
WanderIIT::WanderIIT()
{
}
// Deconstructor
WanderIIT::~WanderIIT()
{
}

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
    Start.x = Start_Xpos;
    Start.y = Start_Ypos;

    offset.x = Start_Xpos;
    offset.y = Start_Ypos;
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
    // Load player
    objectSurface = SDL_LoadBMP("Resources/player.bmp");
    objectTexture = SDL_CreateTextureFromSurface(renderer, objectSurface);
    if (objectSurface == NULL)
    {
        printf("Unable to load the image Resources/player.bmp! SDL_ERROR: %s\n", SDL_GetError());
        isRunning = false;
        return false;
    }

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
        offset.x += change_x;
        offset.y += change_y;
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

    // Capture keyboard here
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // Handle Diagonol Movements
    if (state[SDL_SCANCODE_RETURN])
    {
        printf("<RETURN> is pressed.\n");
    }
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP])
    {
        if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + Key_Reverse + (objectSurface->w) / 2] != 1)
        {
            if (offset.x + map_pos.x + object_width < win_w)
            {
                offset.x += Key_Reverse;
            }
        }
        if (map_data[(offset.y - map_pos.y - Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
        {
            if (offset.y > map_pos.y)
            {
                offset.y -= Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP])
    {
        if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x - Key_Reverse + (objectSurface->w) / 2] != 1)
        {
            if (offset.x > map_pos.x)
            {
                offset.x -= Key_Reverse;
            }
        }
        if (map_data[(offset.y - map_pos.y - Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
        {
            if (offset.y > map_pos.y)
            {
                offset.y -= Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN])
    {
        if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + Key_Reverse + (objectSurface->w) / 2] != 1)
        {
            if (offset.x + map_pos.x + object_width < win_w)
            {
                offset.x += Key_Reverse;
            }
        }
        if (map_data[(offset.y - map_pos.y + Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
        {
            if (offset.y + map_pos.y + object_height < win_h)
            {
                offset.y += Key_Reverse;
            }
        }
    }
    if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN])
    {
        if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x - Key_Reverse + (objectSurface->w) / 2] != 1)
        {
            if (offset.x > map_pos.x)
            {
                offset.x -= Key_Reverse;
            }
        }
        if (map_data[(offset.y - map_pos.y + Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
        {
            if (offset.y + map_pos.y + object_height < win_h)
            {
                offset.y += Key_Reverse;
            }
        }
    }

    switch (event.type)
    {
    // Handle Different Events
    case SDL_QUIT:
        isRunning = false;
        break;
    // Handle Orthogonol Movements
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (map_data[(offset.y - map_pos.y - Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1 && map_data[(offset.y - map_pos.y - 2 + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
            {
                if (offset.y > map_pos.y)
                {
                    offset.y -= Key_Reverse;
                }
            }
            break;
        case SDLK_LEFT:
            if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x - Key_Reverse + (objectSurface->w) / 2] != 1 && map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x - 2 + (objectSurface->w) / 2] != 1)
            {
                if (offset.x > map_pos.x)
                {
                    offset.x -= Key_Reverse;
                }
            }
            break;
        case SDLK_DOWN:
            // Limit the objectSurface within the screen height
            if (map_data[(offset.y - map_pos.y + Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1 && map_data[(offset.y - map_pos.y + 2 + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
            {
                if (offset.y + map_pos.y + objectSurface->h < win_h)
                {
                    offset.y += Key_Reverse;
                }
            }
            break;
        case SDLK_RIGHT:
            // Limit the objectSurface within the screen width
            if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + Key_Reverse + (objectSurface->w) / 2] != 1 && map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + 2 + (objectSurface->w) / 2] != 1)
            {
                if (offset.x + map_pos.x + objectSurface->w < win_w)
                {
                    offset.x += Key_Reverse;
                }
            }
            break;
        default:
            break;
        }
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (map_data[(offset.y - map_pos.y - Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
            {
                if (offset.y > map_pos.y)
                {
                    offset.y -= Key_Reverse;
                }
            }
            break;
        case SDLK_LEFT:
            if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x - Key_Reverse + (objectSurface->w) / 2] != 1)
            {
                if (offset.x > map_pos.x)
                {
                    offset.x -= Key_Reverse;
                }
            }
            break;
        case SDLK_DOWN:
            // Limit the objectSurface within the screen height
            if (map_data[(offset.y - map_pos.y + Key_Reverse + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + (objectSurface->w) / 2] != 1)
            {
                if (offset.y + map_pos.y + objectSurface->h < win_h)
                {
                    offset.y += Key_Reverse;
                }
            }
            break;
        case SDLK_RIGHT:
            // Limit the objectSurface within the screen width
            if (map_data[(offset.y - map_pos.y + (objectSurface->h) / 2) * MAP_FRAME_WIDTH + offset.x - map_pos.x + Key_Reverse + (objectSurface->w) / 2] != 1)
            {
                if (offset.x + map_pos.x + objectSurface->w < win_w)
                {
                    offset.x += Key_Reverse;
                }
            }
            break;
        default:
            break;
        }
    default:
        break;
    }

    // Apply the objectSurface image
    // SDL_BlitSurface( objectSurface, NULL, ScreenSurface, &offset );
}

void WanderIIT::update()
{
    // Update the surface
    // SDL_UpdateWindowSurface( window );
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
    // Get the player object on the screen
    SDL_QueryTexture(objectTexture, NULL, NULL, &object_width, &object_height);
    offset.w = object_width;
    offset.h = object_height;
    SDL_RenderCopy(renderer, objectTexture, NULL, &offset);

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
    if (offset.x - Start.x < 4 && Start.x - offset.x < 4 && offset.y - Start.y < 4 && Start.y - offset.y < 4)
    {
        Key_Reverse = 1;
    }

    if ((offset.x - Dog0->position.x < 4 && Dog0->position.x - offset.x < 4 && offset.y - Dog0->position.y < 4 && Dog0->position.y - offset.y < 4) ||
        (offset.x - Dog1->position.x < 4 && Dog1->position.x - offset.x < 4 && offset.y - Dog1->position.y < 4 && Dog1->position.y - offset.y < 4) ||
        (offset.x - Dog2->position.x < 4 && Dog2->position.x - offset.x < 4 && offset.y - Dog2->position.y < 4 && Dog2->position.y - offset.y < 4) ||
        (offset.x - Dog3->position.x < 4 && Dog3->position.x - offset.x < 4 && offset.y - Dog3->position.y < 4 && Dog3->position.y - offset.y < 4) ||
        (offset.x - Dog4->position.x < 4 && Dog4->position.x - offset.x < 4 && offset.y - Dog4->position.y < 4 && Dog4->position.y - offset.y < 4) ||
        (offset.x - Dog5->position.x < 4 && Dog5->position.x - offset.x < 4 && offset.y - Dog5->position.y < 4 && Dog5->position.y - offset.y < 4) ||
        (offset.x - Dog6->position.x < 4 && Dog6->position.x - offset.x < 4 && offset.y - Dog6->position.y < 4 && Dog6->position.y - offset.y < 4) ||
        (offset.x - Dog7->position.x < 4 && Dog7->position.x - offset.x < 4 && offset.y - Dog7->position.y < 4 && Dog7->position.y - offset.y < 4) ||
        (offset.x - Dog8->position.x < 4 && Dog8->position.x - offset.x < 4 && offset.y - Dog8->position.y < 4 && Dog8->position.y - offset.y < 4) ||
        (offset.x - Dog9->position.x < 4 && Dog9->position.x - offset.x < 4 && offset.y - Dog9->position.y < 4 && Dog9->position.y - offset.y < 4))
    {
        Mix_PlayChannel( -1, Dog_collison, 0 );
        offset.x = Start.x;
        offset.y = Start.y;
    }

    if ((offset.x - Prof0->position.x < 4 && Prof0->position.x - offset.x < 4 && offset.y - Prof0->position.y < 4 && Prof0->position.y - offset.y < 4) ||
        (offset.x - Prof1->position.x < 4 && Prof1->position.x - offset.x < 4 && offset.y - Prof1->position.y < 4 && Prof1->position.y - offset.y < 4) ||
        (offset.x - Prof2->position.x < 4 && Prof2->position.x - offset.x < 4 && offset.y - Prof2->position.y < 4 && Prof2->position.y - offset.y < 4) ||
        (offset.x - Prof3->position.x < 4 && Prof3->position.x - offset.x < 4 && offset.y - Prof3->position.y < 4 && Prof3->position.y - offset.y < 4) ||
        (offset.x - Prof4->position.x < 4 && Prof4->position.x - offset.x < 4 && offset.y - Prof4->position.y < 4 && Prof4->position.y - offset.y < 4))
    {
        Mix_PlayChannel( -1, Prof_collison, 0 );
        Key_Reverse = -1;
    }
}

void WanderIIT::clean()
{
    // Deallocate objectSurface surface
    SDL_FreeSurface(objectSurface);
    objectSurface = NULL;

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