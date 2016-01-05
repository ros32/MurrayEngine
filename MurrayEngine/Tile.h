#ifndef _TILE_H
#define _TILE_H

#include	"GenericObject.h"
#include	"Position.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

class Tile: public GenericObject
{
public:
	Tile();
	Tile(Position currentPosition, Texture texture, Orientation orientation);
	~Tile();

	Position	getCurrentPosition();

	void render(int x, int y);

private:



};

#endif // !_TILE_H
