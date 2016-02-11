#ifndef _TILE_H
#define _TILE_H

#include	"Object.h"
#include	"Position.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

class Tile: public Object
{
public:
	Tile();
	Tile(Position currentPosition, Texture texture, Orientation orientation, bool collidable, bool passable);
	~Tile();

	Position	getCurrentPosition();

	void render(int x, int y);

private:



};

#endif // !_TILE_H
