#ifndef _CAMERA_H
#define	_CAMERA_H

#include	<SDL.h>
#include	"GenericObject.h"
#include	"Position.h"

class Camera
{
public:
	Camera();
	Camera(SDL_Window* window);
	~Camera();

	SDL_Rect			getCameraRect();

	int					getHeight();
	int					getWidth();

	Position			getPosition();
	void				setPosition(Position pos);
	void				setPosition(GenericObject object);



private:

	int					height;
	int					width;

	Position			position;
	SDL_Renderer*		renderer;
	SDL_Rect			cameraRect;

};

#endif // !_CAMERA_H
