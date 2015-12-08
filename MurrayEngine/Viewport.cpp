#include	"Viewport.h"

Viewport::Viewport()
{

}

Viewport::Viewport(SDL_Renderer* renderer)
{

}

Viewport::~Viewport()
{

}

int	Viewport::getHeight()
{
	return this->height;
}

int Viewport::getWidth()
{
	return this->width;
}