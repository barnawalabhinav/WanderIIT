#include "buttons.h"

using namespace std;

buttons::buttons(){}

buttons::~buttons(){}

int buttons::buttons_window(SDL_Window *window, SDL_Renderer *render)
{

	/* Load bitmap image */
	SDL_Surface *bmp = SDL_LoadBMP("Resources/IIT-Delhi.bmp");
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
	srcrect.x = 254;
	srcrect.y = 103;
	SDL_RenderCopy(render, texture, NULL, &srcrect); // Copy the texture into render
	SDL_RenderPresent(render);					 // Show render on window

	int hostelname = 0;

	bool running = true;

	while (running)
	{
		SDL_Event button_event;
		SDL_PollEvent(&button_event);
		int x, y;
		if (button_event.type == SDL_QUIT)
			running = false;
		else
		{
			SDL_GetMouseState(&x, &y);
			if (button_event.button.button == SDL_BUTTON_LEFT)
			{
				if (39 < x - srcrect.x && x - srcrect.x < 179 && 35 < y - srcrect.y && y - srcrect.y < 100)
				{
					hostelname = 1; // Satpura;
					running = false;
				}
				else if (208 < x - srcrect.x && x - srcrect.x < 344 && 34 < y - srcrect.y && y - srcrect.y < 99)
				{
					hostelname = 2; // Girnar;
					running = false;
				}
				else if (364 < x - srcrect.x && x - srcrect.x < 493 && 34 < y - srcrect.y && y - srcrect.y < 98)
				{
					hostelname = 3; // Udaigiri;
					running = false;
				}
				else if (517 < x - srcrect.x && x - srcrect.x < 654 && 33 < y - srcrect.y && y - srcrect.y < 97)
				{
					hostelname = 4; // Karakoram;
					running = false;
				}
				else if (41 < x - srcrect.x && x - srcrect.x < 181 && 136 < y - srcrect.y && y - srcrect.y < 202)
				{
					hostelname = 5; // Nilgiri;
					running = false;
				}
				else if (212 < x - srcrect.x && x - srcrect.x < 347 && 135 < y - srcrect.y && y - srcrect.y < 200)
				{
					hostelname = 6; // Aravali;
					running = false;
				}
				else if (368 < x - srcrect.x && x - srcrect.x < 493 && 134 < y - srcrect.y && y - srcrect.y < 200)
				{
					hostelname = 7; // Kumaon;
					running = false;
				}
				else if (518 < x - srcrect.x && x - srcrect.x < 655 && 133 < y - srcrect.y && y - srcrect.y < 196)
				{
					hostelname = 8; // Himadri;
					running = false;
				}
				else if (42 < x - srcrect.x && x - srcrect.x < 182 && 231 < y - srcrect.y && y - srcrect.y < 303)
				{
					hostelname = 9; // Kailash;
					running = false;
				}
				else if (212 < x - srcrect.x && x - srcrect.x < 347 && 232 < y - srcrect.y && y - srcrect.y < 303)
				{
					hostelname = 10; // Vindhyachal;
					running = false;
				}
				else if (371 < x - srcrect.x && x - srcrect.x < 494 && 231 < y - srcrect.y && y - srcrect.y < 302)
				{
					hostelname = 11; // Zanskar;
					running = false;
				}
				else if (43 < x - srcrect.x && x - srcrect.x < 183 && 332 < y - srcrect.y && y - srcrect.y < 405)
				{
					hostelname = 12; // Shivalik;
					running = false;
				}
				else if (214 < x - srcrect.x && x - srcrect.x < 351 && 332 < y - srcrect.y && y - srcrect.y < 406)
				{
					hostelname = 13; // Jwalamukhi;
					running = false;
				}
			}
		}
	}

	/* Free all objects*/
	SDL_DestroyTexture(texture);
	return hostelname;
}