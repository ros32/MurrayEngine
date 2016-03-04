#include	"Camera.h"

Camera::Camera()
{
	this->position = { 0, 0 };
	this->height = 0;
	this->width = 0;
	this->focusType = FREE_FOCUS;
	this->gui;
}

Camera::Camera(SDL_Window* window)
{
	//	Set position to 0,0
	this->position = { 0, 0 };

	//	Set Cameras width and height to the same as the provided window
	this->setWindow(window);

	//	Use OBJECT_FOCUS as standard
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

GUI*		Camera::getGUI()
{
	return &this->gui;
}

void		Camera::setFocusType(CameraFocus focusType)
{
	this->focusType = focusType;
}