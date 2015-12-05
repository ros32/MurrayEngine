#include <iostream>
#include <string>
#include "SDL.h"	//	Include SDL2
#include "SDL_ttf.h"

SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	//	Load TTF font
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr)
	{
		SDL_Log(TTF_GetError());
		return nullptr;
	}

	SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), color);

	if (surface == nullptr)
	{
		SDL_Log("TTF_RenderText_Blended");
		return nullptr;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == nullptr)
	{
		SDL_Log("SDL_CreateTextureFromSurface");
		return nullptr;
	}

	SDL_FreeSurface(surface);
	TTF_CloseFont(font);

	return texture;

}

int main(int, char** argv)
{
	//	Define size of window
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	//  Define the color blue
	const SDL_Color BLUE = { 850, 320, 760, 56 };

	//	Define the color white
	const SDL_Color	WHITE = { 240, 240, 240 };

	//	Define a rectangle positioned in the middle of the screen
	const SDL_Rect MIDPOINTRECT = { 0, WINDOW_HEIGHT / 2 - 32, 640, 64 };





	//	Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//	Create SDL Window
	SDL_Window *window = SDL_CreateWindow("SDLTest", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//	If window has not been created, exit application
	if (window == nullptr)	
		return 0;

	//	Create SDL renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//	If renderer has not been created, exit application
	if (renderer == nullptr)
		return 0;

	//	Initialize TTF
	TTF_Init();

	//	Create a texture from a string using provided font
	SDL_Texture *texture = renderText("Hello World", "C:\\Windows\\Fonts\\tahoma.ttf", BLUE, 24, renderer);

	//	If texture is nullptr it failed to render text
	if (texture == nullptr)
		SDL_Log("Texture is null");

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
		SDL_RenderCopy(renderer, texture, NULL, &MIDPOINTRECT);
		SDL_RenderPresent(renderer);

	}

	//	Quit TTF
	TTF_Quit();

	//	Destroy renderer
	SDL_DestroyRenderer(renderer);

	//	Destroy window
	SDL_DestroyWindow(window);

	//	Quit SDL
	SDL_Quit();

	//	Return 0 and end application
	return 0;						//	Return 0 to report success
}