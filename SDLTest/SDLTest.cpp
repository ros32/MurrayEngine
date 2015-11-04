#include "SDL.h"	//	Include SDL2

int main(int, char** argv)
{
	//	Define size of window
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	//	Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//	Create SDL Window
	SDL_Window *window = SDL_CreateWindow("SDLTest", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//	If window has not been created, exit application
	if (window == NULL)	
		return 0;

	//	Create SDL renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//	If renderer has not been created, exit application
	if (renderer == NULL)
		return 0;

	//	Loop forever
	while (1)
	{
		//	Define SDL Event
		SDL_Event e;

		//	Poll for pending event into &e
		if (SDL_PollEvent(&e))
		{
			//	If Event Type is SDL_QUIT then break loop
			if (e.type == SDL_QUIT)
				break;
		}

		//	Clear renderer
		SDL_RenderClear(renderer);

		//	Update renderer
		SDL_RenderPresent(renderer);

	}

	//	Destroy renderer
	SDL_DestroyRenderer(renderer);

	//	Destroy window
	SDL_DestroyWindow(window);

	//	Quit SDL
	SDL_Quit();

	//	Return 0 and end application
	return 0;						//	Return 0 to report success
}