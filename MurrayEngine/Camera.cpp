#include	"Camera.h"

Camera::Camera()
{

}

Camera::Camera(SDL_Renderer* renderer)
{

}

Camera::~Camera()
{

}

int	Camera::getHeight()
{
	return this->height;
}

int Camera::getWidth()
{
	return this->width;
}