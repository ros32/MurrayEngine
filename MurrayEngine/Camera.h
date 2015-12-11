#ifndef _CAMERA_H
#define	_CAMERA_H

#include	<SDL.h>
#include	"GenericObject.h"
#include	"Position.h"

enum CameraFocus
{
	OBJECT_FOCUS = 0,
	FREE_FOCUS = 1
};

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

	void				move(int x, int y);

	CameraFocus			getFocusType();
	void				setFocusType(CameraFocus focusType);

	void				setWindow(SDL_Window* window);

	void				center(Position pos);



private:

	int					height;
	int					width;

	Position			position;
	SDL_Renderer*		renderer;
	SDL_Rect			cameraRect;

	CameraFocus			focusType;

};

#endif // !_CAMERA_H
