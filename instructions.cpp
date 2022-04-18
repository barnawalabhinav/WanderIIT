#include "instructions.h"

using namespace std;

instructions::instructions(){
}

instructions::~instructions(){}

int instructions::instructions_window(SDL_Window *window, SDL_Renderer *render)
{
	/* Load bitmap image */
	SDL_Surface *bmp = SDL_LoadBMP("Resources/instructions.bmp");
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
	SDL_Rect srcrect;
	SDL_QueryTexture(texture, NULL, NULL, &srcrect.w, &srcrect.h);
	srcrect.x = 229;
	srcrect.y = 43;
	SDL_RenderCopy(render, texture, NULL, &srcrect); // Copy the texture into render
	SDL_RenderPresent(render);					 // Show render on window

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
			SDL_GetMouseState(&x, &y);
			if (event.button.button == SDL_BUTTON_LEFT)
			{
                if(496 < x && x < 653 && 602 < y && y < 635)
                running = false;
			}
		}
	}

	/* Free all objects*/
	SDL_DestroyTexture(texture);
    return 0;
}