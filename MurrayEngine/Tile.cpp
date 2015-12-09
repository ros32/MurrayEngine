#include	"Tile.h"

Tile::Tile() : GenericObject()
{

}

Tile::Tile(Position currentPosition, TextureAsset* texture, std::string textureName, Orientation orientation) : GenericObject("tile", currentPosition, texture, textureName, 0.0, 0.0, orientation)
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