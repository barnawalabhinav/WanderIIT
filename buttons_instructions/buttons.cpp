#include "buttons.hpp"

using namespace std;

buttons::buttons(){}

buttons::~buttons(){}

int buttons::buttons_window(SDL_Window *window, SDL_Renderer *render)
{

	/* Load bitmap image */
	SDL_Surface *bmp = SDL_LoadBMP("IIT-Delhi.bmp");
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
				cout << x << ", " << y << endl;
				if (39 < x && x < 179 && 35 < y && y < 100)
				{
					hostelname = 1; // Satpura;
					running = false;
				}
				if (208 < x && x < 344 && 34 < y && y < 99)
				{
					hostelname = 2; // Girnar;
					running = false;
				}
				if (364 < x && x < 493 && 34 < y && y < 98)
				{
					hostelname = 3; // Udaigiri;
					running = false;
				}
				if (517 < x && x < 654 && 33 < y && y < 97)
				{
					hostelname = 4; // Karakoram;
					running = false;
				}
				if (41 < x && x < 181 && 136 < y && y < 202)
				{
					hostelname = 5; // Nilgiri;
					running = false;
				}
				if (212 < x && x < 347 && 135 < y && y < 200)
				{
					hostelname = 6; // Aravali;
					running = false;
				}
				if (368 < x && x < 493 && 134 < y && y < 200)
				{
					hostelname = 7; // Kumaon;
					running = false;
				}
				if (518 < x && x < 655 && 133 < y && y < 196)
				{
					hostelname = 8; // Himadri;
					running = false;
				}
				if (42 < x && x < 182 && 231 < y && y < 303)
				{
					hostelname = 9; // Kailash;
					running = false;
				}
				if (212 < x && x < 347 && 232 < y && y < 303)
				{
					hostelname = 10; // Vindhyachal;
					running = false;
				}
				if (371 < x && x < 494 && 231 < y && y < 302)
				{
					hostelname = 11; // Zanskar;
					running = false;
				}
				if (43 < x && x < 183 && 332 < y && y < 405)
				{
					hostelname = 12; // Shivalik;
					running = false;
				}
				if (214 < x && x < 351 && 332 < y && y < 406)
				{
					hostelname = 13; // Jwalamukhi;
					running = false;
				}
			}
		}
	}

	/* Free all objects*/
	SDL_DestroyTexture(texture);

	/* Quit program */
	SDL_Quit();
	return hostelname;
}

buttons *object = nullptr;


