#ifndef _TILE_H
#define _TILE_H

#include	"GenericObject.h"
#include	"Position.h"
#include	<SDL.h>

class Tile: public GenericObject
{
public:
	Tile();
	Tile(Position currentPosition, TextureAsset* texture, std::string textureName, Orientation orientation);
	~Tile();

	Position	getCurrentPosition();

	void render(int x, int y);

private:



};

#endif // !_TILE_H
