#ifndef _CAMERA_H
#define	_CAMERA_H

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	"Object.h"
#include	"Position.h"
#include	"GUI.h"

///	<summary>
///	Controls the focus type the Camera should use.
///	</summary>
enum CameraFocus
{
	///	<summary>
	///	Sets camera to follow playerCharacter
	///	</summary>
	OBJECT_FOCUS = 0,
	///	<summary>
	///	Sets camera to not follow an object
	///	</summary>
	FREE_FOCUS = 1
};

///	<summary>
///	The Camera class is a representation of the viewport the User views the
///	game through. Only the portion of the Map visible in the Camera will be
///	rendered.
///	</summary>
class Camera
{
public:

	///	<summary>
	///	The Camera class is a representation of the viewport the User views the
	///	game through. Only the portion of the Map visible in the Camera will be
	///	rendered.
	///	</summary>
	Camera();

	///	<summary>
	///	The Camera class is a representation of the viewport the User views the
	///	game through. Only the portion of the Map visible in the Camera will be
	///	rendered.
	///	</summary>
	Camera(SDL_Window* window);

	~Camera();

	///	<summary>
	///	Return a copy of the SDL_Rect representing the Camera
	///	</summary>
	SDL_Rect			getCameraRect();

	///	<summary>
	///	Return the height of the Camera. Unless specified otherwise in implementation, 
	///	should be equal to window height.
	///	</summary>
	int					getHeight();

	///	<summary>
	///	Return the width of the Camera. Unless specified otherwise in implementation, 
	///	should be equal to window width.
	///	</summary>
	int					getWidth();

	///	<summary>
	///	Return a copy of the Position of the Camera object, measured from the 
	///	top left corner of the Cameras SDL_Rect
	///	</summary>
	Position			getPosition();

	///	<summary>
	///	Sets the position of the Camera to the specified Position
	///	</summary>
	void				setPosition(Position pos);

	///	<summary>
	///	Sets the position of the Camera to the specified Object
	///	</summary>
	void				setPosition(Object object);

	///	<summary>
	///	Move the Camera the specified amount of x and y coordinates relative to its current position.
	///	</summary>
	void				move(int x, int y);

	///	<summary>
	///	Return the focus type of the Camera.
	///	</summary>
	CameraFocus			getFocusType();

	///	<summary>
	///	Sets the focus type of the camera
	/// </summary>
	void				setFocusType(CameraFocus focusType);

	///	<summary>
	///	Sets the window of the Camera
	///	</summary>
	void				setWindow(SDL_Window* window);

	///	<summary>
	///	Center the Camera on the specified Position
	///	</summary>
	void				center(Position pos);

	GUI*				getGUI();

	//void				setGUI(GUI* gui);



private:

	//	Height of Camera
	int					height;

	//	Width of Camera
	int					width;

	//	Position of Camera
	Position			position;

	//	Pointer to SDL_Renderer
	SDL_Renderer*		renderer;

	//	The Cameras SDL_Rect
	SDL_Rect			cameraRect;

	//	Focus type of Camera
	CameraFocus			focusType;

	GUI					gui;

};

#endif // !_CAMERA_H
