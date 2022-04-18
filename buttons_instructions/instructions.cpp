#include "instructions.hpp"

using namespace std;

instructions::instructions(){
}

instructions::~instructions(){}

int instructions::instructions_window(SDL_Window *window, SDL_Renderer *render)
{
	/* Load bitmap image */
	SDL_Surface *bmp = SDL_LoadBMP("instructions.bmp");
	if (bmp == nullptr)
	{
		printf("SDL_LoadBMP Error: ");
		return 1;
	}

	/* Upload surface to render, and then, free the surface */
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render, bmp);
	SDL_FreeSurface(bmp);
	if (texture == nullptr)
	{
		printf("SDL_CreateTextureFromSurface Error: ");
		return 1;
	}

	/* Draw the render on window */
	SDL_RenderClear(render);					 // Fill render with color
	SDL_RenderCopy(render, texture, NULL, NULL); // Copy the texture into render
	SDL_RenderPresent(render);					 // Show render on window

	int hostelname = 0;

	bool running = true;

	while (running)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		int x, y;
		if (event.type == SDL_QUIT)
			running = false;
		else
		{
			Uint32 buttons = SDL_GetMouseState(&x, &y);
			if (event.button.button == SDL_BUTTON_LEFT)
			{
                if(350 < x && x < 550 && 644 < y && y < 697)
                running = false;
			}
		}
	}

	/* Free all objects*/
	SDL_DestroyTexture(texture);

	/* Quit program */
	//SDL_Quit();
    return 0;
}


instructions *object_instructions = nullptr;

