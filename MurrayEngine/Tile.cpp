#include	"Tile.h"

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

void		Tile::setCurrentPosition(Position pos)
{

}

void	Tile::render(int x, int y)
{
	this->Object::render(x, y);
}

bool	Tile::getIsCollidable()
{
	return Object::getIsCollidable();
}