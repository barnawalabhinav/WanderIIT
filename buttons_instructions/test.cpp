#include "buttons.hpp"

#include "instructions.hpp"

using namespace std;


int main()

{

	/* Starting SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL_Init Error: ");
		return 1;
	}

	/* Create a Window */
	SDL_Window *window = SDL_CreateWindow("Hostel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_instruct, SCREEN_HEIGHT_instruct, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("SDL_CreateWindow Error: ");
		return 1;
	}

	/* Create a Render */
	SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (render == nullptr)
	{
		printf("SDL_CreateRenderer Error: ");
		return 1;
	}

    instructions *object_instructions = nullptr;

    object_instructions = new instructions();
    object_instructions->instructions_window(window, render);

    SDL_Delay(1);

    buttons *object_buttons = nullptr;

	object_buttons = new buttons();
	int abc = object_buttons->buttons_window(window, render);
	cout << abc << endl;
    SDL_Quit();
	return 0;
}