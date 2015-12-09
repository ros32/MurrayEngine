#include	"Camera.h"

Camera::Camera()
{
	this->position = { 0, 0 };
}

Camera::Camera(SDL_Window* window)
{
	this->position = { 0, 0 };
	SDL_GetWindowSize(window, &this->width, &this->height);
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

Position	Camera::getPosition()
{
	return this->position;
}