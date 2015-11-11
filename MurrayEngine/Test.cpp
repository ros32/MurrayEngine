#include "SpriteAssetHandler.h"
#include "FrameLimiter.h"
#include <string>
#include <direct.h>
#include <stdlib.h>

#define	_DEBUG_FRAME_LIMIT		30

#define		_DEBUG_START_POS	=	{121, 333};

int main(int, char** argv)
{
	//	Define size of window
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	const int TILE_SIZE = 32;
	const int MAX_TILES = (WINDOW_WIDTH / TILE_SIZE) * (WINDOW_HEIGHT / TILE_SIZE);

	//	Define the color white
	const SDL_Color	WHITE = { 240, 240, 240 };

	//	Define a rectangle positioned in the middle of the screen
	const SDL_Rect MIDPOINTRECT = { 0, 0, 32, 32 };
	const SDL_Rect MIDPOINTRECT2 = { 32, 0, 32, 32 };

	SDL_Rect	tiles[MAX_TILES];

	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < MAX_TILES; i++)
	{
		tiles[i] = { currentX, currentY, TILE_SIZE, TILE_SIZE };
		
		if(currentX/TILE_SIZE +1 < (WINDOW_WIDTH/TILE_SIZE))
			currentX += TILE_SIZE; 
		else
		{
			currentY += TILE_SIZE;
			currentX = 0;
		}
	}






	//	Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//	Create SDL Window
	SDL_Window *window = SDL_CreateWindow("SDLTest", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//	If window has not been created, exit application
	if (window == nullptr)
		return 0;

	//	Create SDL renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	//	If renderer has not been created, exit application
	if (renderer == nullptr)
		return 0;
	
	IMG_Init(IMG_INIT_PNG);
	/*char filePath[FILENAME_MAX];
	_getcwd(filePath, sizeof(filePath));
	SDL_Log(filePath);
	std::string fileName(filePath);
	fileName += "\\spritesheet.png";*/
	SpriteAssetHandler	spriteHandler(renderer, "tileset.png", 32, 0, SDL_Color{ 255, 0, 255 });

	FrameLimiter	counter = FrameLimiter(*new Timer(), _DEBUG_FRAME_LIMIT);

	//	Loop forever
	while (1)
	{
		counter.start();
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
		for (auto tile : tiles)
		{
			int randX = rand() % 23;
			int randY = rand() % 21;
			SDL_RenderCopy(renderer, spriteHandler.getTexture(), spriteHandler.getSourceRect(randX, randY), &tile);
		}

		//	Update renderer
		SDL_RenderPresent(renderer);
		counter.limit();
	}

	IMG_Quit();

	//	Destroy renderer
	SDL_DestroyRenderer(renderer);

	//	Destroy window
	SDL_DestroyWindow(window);

	//	Quit SDL
	SDL_Quit();

	//	Return 0 and end application
	return 0;						//	Return 0 to report success
}