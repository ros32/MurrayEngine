#include	"Camera.h"

Camera::Camera()
{
	this->position = { 0, 0 };
	this->height = 0;
	this->width = 0;
}

Camera::Camera(SDL_Window* window)
{
	this->position = { 0, 0 };
	SDL_GetWindowSize(window, &this->width, &this->height);
	this->focusType = FREE_FOCUS;
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

void		Camera::setWindow(SDL_Window* window)
{
	SDL_GetWindowSize(window, &this->width, &this->height);
}

void		Camera::move(int x, int y)
{
	this->position = { this->position.x + x, this->position.y + y };
}

void		Camera::center(Position pos)
{
	this->position = { pos.x - (this->width / 2), pos.y - (this->height / 2) };
}

CameraFocus	Camera::getFocusType()
{
	return this->focusType;
}