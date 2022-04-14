#include "WanderIIT.hpp"
#include "glad/glad.h"

// Constructor
WanderIIT::WanderIIT()
{}
// Deconstructor
WanderIIT::~WanderIIT()
{}

bool WanderIIT::init (const char *name, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int fullscreen_flag = 0;
    if( fullscreen == true) {
        fullscreen_flag = SDL_WINDOW_FULLSCREEN;
    }

    offset.x = 100;
    offset.y = 250;

    // Initialize all the SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ) {
        printf( "SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError() );        
        isRunning = false;
        return false;
    }
    
    printf( "Game Initialized!\n" );

    //Specify OPENGL version before use
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );

    // Creating game window
    window = SDL_CreateWindow( name, xpos, ypos, width, height, fullscreen_flag | SDL_WINDOW_OPENGL );

    if( window == NULL) {
        printf( "Window could not be created!, SDL_Error: %s\n", SDL_GetError() );
        isRunning = false;
        return false;
    }

    printf( "Window Created!\n" );

    //OpenGl Setup the Graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    //Setup out function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Creating the Renderer for our window
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
                        
    if( renderer == NULL ) {
        printf( "Renderer could not be created!, SDL_Error: %s\n", SDL_GetError() );
        isRunning = false;
        return false;
    }
    
    printf ("Renderer Created!\n");

    ScreenSurface = SDL_LoadBMP( "Resources/map.bmp" );
    ScreenTexture = SDL_CreateTextureFromSurface(renderer, ScreenSurface);

    if ( ScreenSurface == NULL ) {
        printf( "Screen Surface could not be created!, SDL_Error: %s\n", SDL_GetError() );
        isRunning = false;
        return false;
    }

    printf( "Screen Created!\n" );

    // Select the color for drawing. It is set to red here.
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
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
void WanderIIT::SetPixel( SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b )
{
    /* Once locked, surface->pixels is safe to access. */
    SDL_LockSurface( surface );
    uint8_t* pixelArray = (uint8_t*) surface->pixels;
    pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 0] = g;
    pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 1] = b;
    pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 2] = r;
    SDL_UnlockSurface( surface );
}

void WanderIIT::handleEvents()
{
    int w, h;
    SDL_GetWindowSize(window, &w, &h);

    SDL_Event event;
    // Starting Event Loop
    SDL_PollEvent (&event);
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
    switch (event.type) {
        //Handle Different Events
        case SDL_QUIT :
            isRunning = false;
            break;
        case SDL_KEYDOWN :
            switch (event.key.keysym.sym) {
                case SDLK_UP :
                    offset.y = offset.y - 1;
                    break;
                case SDLK_LEFT :
                    offset.x = offset.x - 1;
                    break;
                case SDLK_DOWN :
                    // Limit the objectSurface within the screen height
                    if (offset.y + objectSurface->h < h) { offset.y = offset.y + 1; }
                    break;
                case SDLK_RIGHT :
                    // Limit the objectSurface within the screen width
                    if (offset.x + objectSurface->w < w) { offset.x = offset.x + 1; }
                    break;
                default :
                    break;
            }
        default :
            break;
    }
        
    //Apply the objectSurface image
    //SDL_BlitSurface( objectSurface, NULL, ScreenSurface, &offset );

}

void WanderIIT::update()
{
    //Update the surface
    //SDL_UpdateWindowSurface( window );
}

void WanderIIT::render()
{
    // Clear the current rendering target with the drawing color
    SDL_RenderClear(renderer);
    // Get the background and the player object on the screen
    SDL_RenderCopy(renderer, ScreenTexture, NULL, NULL);
    int object_width, object_height;
    SDL_QueryTexture(objectTexture, NULL, NULL, &object_width, &object_height);
    offset.w = object_width;
    offset.h = object_height;
    SDL_RenderCopy(renderer, objectTexture, NULL, &offset);
    // Update the screen with any rendering performed since the previous call
    SDL_RenderPresent(renderer);
}

bool WanderIIT::loadmedia( const char* obj )
{
    //Load image
    objectSurface = SDL_LoadBMP( obj );
    objectTexture = SDL_CreateTextureFromSurface(renderer, objectSurface);
	if ( objectSurface == NULL ) {
        printf( "Unable to load the image %s! SDL_ERROR: %s\n", obj, SDL_GetError() );
        isRunning = false;
        return false;
    }
    
    printf( "Player Created!\n" );
    return isRunning;
}

void WanderIIT::clean()
{
    //Deallocate objectSurface surface
    SDL_FreeSurface(objectSurface);
    objectSurface = NULL;

    //Deallocate Screen surface
    SDL_FreeSurface( ScreenSurface );
    ScreenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Destroy Renderer
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    printf( "Game Cleaned!\n" );
}