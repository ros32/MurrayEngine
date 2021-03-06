#ifndef _CAMERA_H
#define	_CAMERA_H

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

#include	"GUI.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	Values that represent camera focus. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
enum CameraFocus
{
	OBJECT_FOCUS = 0,
	FREE_FOCUS = 1
};

///-------------------------------------------------------------------------------------------------
/// <summary>	The Camera class controls what should be rendered in the game. Everything within the Cameras
/// 			SDL_Rect will be rendered, whereas everything outside will not (with the exception of a padding
/// 			area around the camera to reduce stuttering).
/// 			
/// 			The Camera can be either bound to the player (OBJECT_FOCUS) or be free-floating (FREE_FOCUS).
/// 			
/// 			The Camera class also contains a GUI to display data on the screen. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class Camera
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	//Camera();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="window">	[in,out] If non-null, the window. </param>
	///-------------------------------------------------------------------------------------------------
	explicit Camera(SDL_Window* window);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~Camera();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets camera rectangle. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The camera rectangle. </returns>
	///-------------------------------------------------------------------------------------------------
	SDL_Rect			getCameraRect() = delete;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the height. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The height. </returns>
	///-------------------------------------------------------------------------------------------------
	int					getHeight() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the width. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The width. </returns>
	///-------------------------------------------------------------------------------------------------
	int					getWidth() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the position. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The position. </returns>
	///-------------------------------------------------------------------------------------------------
	Position			getPosition() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a position. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///-------------------------------------------------------------------------------------------------
	void				setPosition(Position pos) = delete;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Moves. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///-------------------------------------------------------------------------------------------------
	void				move(int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets focus type. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The focus type. </returns>
	///-------------------------------------------------------------------------------------------------
	CameraFocus			getFocusType() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets focus type. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="focusType">	Type of the focus. </param>
	///-------------------------------------------------------------------------------------------------
	void				setFocusType(CameraFocus focusType);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a window. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="window">	[in,out] If non-null, the window. </param>
	///-------------------------------------------------------------------------------------------------
	void				setWindow(SDL_Window* window);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Centers the given position. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///-------------------------------------------------------------------------------------------------
	void				center(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the graphical user interface. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	null if it fails, else the graphical user interface. </returns>
	///-------------------------------------------------------------------------------------------------
	GUI*				getGUI() const;

private:


	/// <summary>	The height. </summary>
	int					height;

	/// <summary>	The width. </summary>
	int					width;

	/// <summary>	The position. </summary>
	Position			position;

	/// <summary>	The renderer. </summary>
	SDL_Renderer*		renderer;

	/// <summary>	The camera rectangle. </summary>
	SDL_Rect			cameraRect;

	/// <summary>	Type of the focus. </summary>
	CameraFocus			focusType;

	/// <summary>	The graphical user interface. </summary>
	GUI*					gui;

};

#endif // !_CAMERA_H
