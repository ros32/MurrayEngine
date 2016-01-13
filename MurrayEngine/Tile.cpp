#include	"Tile.h"

Tile::Tile() : Object()
{

}

Tile::Tile(Position currentPosition, Texture texture, Orientation orientation) : Object("tile", currentPosition, texture, 0.0, 0.0, 0, orientation, false)
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