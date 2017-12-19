#include	"Camera.h"

Camera::Camera(SDL_Window* window)
{
	//	Set position to 0,0
	this->position = { 0, 0 };

	//	Set Cameras width and height to the same as the provided window
	this->setWindow(window);

	//	Use OBJECT_FOCUS as standard
	this->focusType = FREE_FOCUS;

	this->renderer = SDL_GetRenderer(window);

	this->gui = new GUI(renderer);
}

Camera::~Camera()
{

}

int	Camera::getHeight() const
{
	return this->height;
}

int Camera::getWidth() const
{
	return this->width;
}

Position	Camera::getPosition() const
{
	return this->position;
}

void		Camera::setWindow(SDL_Window* window)
{
	SDL_GetWindowSize(window, &this->width, &this->height);
}

void		Camera::move(const int x, const int y)
{
	this->position = { this->position.x + x, this->position.y + y };
}

void		Camera::center(const Position pos)
{
	this->position = { pos.x - (this->width / 2), pos.y - (this->height / 2) };
}

CameraFocus	Camera::getFocusType() const
{
	return this->focusType;
}

GUI*		Camera::getGUI() const
{
	return this->gui;
}

void		Camera::setFocusType(const CameraFocus focusType)
{
	this->focusType = focusType;
}