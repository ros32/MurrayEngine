#include	"Tile.h"

Tile::Tile() : GenericObject()
{

}

Tile::Tile(Position currentPosition, Texture texture, Orientation orientation) : GenericObject("tile", currentPosition, texture, 0.0, 0.0, 0, orientation, false)
{

}

Tile::~Tile()
{

}

Position	Tile::getCurrentPosition()
{
	return this->GenericObject::getCurrentPosition();
}

void	Tile::render(int x, int y)
{
	this->GenericObject::render(x, y);
}