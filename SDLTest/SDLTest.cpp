#include "SDL.h"	//	Include SDL2

int main(int, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);	//	Try to initialize SDL
	SDL_Quit();						//	Quit SDL
	return 0;						//	Return 0 to report success
}