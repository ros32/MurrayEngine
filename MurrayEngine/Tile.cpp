#define _CRTDBG_MAP_ALLOC
#include	"Tile.h"

Tile::Tile() : Object()
{

}

Tile::Tile(Position currentPosition, std::shared_ptr<Texture> texture, Orientation orientation, bool isCollidable, bool isPassable) : 
	Object("tile", currentPosition, texture, 0.0, 0.0, 0, orientation, isCollidable)
{

}

Tile::~Tile()
{

}

Position	Tile::getCurrentPosition()
{
	return this->Object::getCurrentPosition();
}

void	Tile::render(int x, int y)
{
	this->Object::render(x, y);
}

bool	Tile::getIsCollidable()
{
	return Object::getIsCollidable();
}