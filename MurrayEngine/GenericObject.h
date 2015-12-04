#ifndef _GENERIC_OBJECT_H
#define _GENERIC_OBJECT_H

#include	<string>
#include	"Position.h"
#include	"TextureAsset.h"
#include	"Timer.h"

enum Orientation
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};

class GenericObject
{
private:

	///	Object identifier
	std::string id;

	///	Current position of object
	Position	currentPosition;

	///	Target position of object
	Position	targetPosition;

	///	Texture asset used by object
	TextureAsset*	textureAsset;

	///	SDL_Rect of texture asset
	SDL_Rect*		textureRect;

	///	The maximum speed the GenericObject can travel, or 0 for static
	double			maxSpeed;

	///	The current speed an object is travelling
	///	double			currentSpeed;

	///	How fast an object reaches its maxSpeed
	///	double			acceleration;

	///	Current orientation of object
	Orientation		orientation;

	Timer			timer;

	Uint32			lastRender;
	Uint32			lastMove;


public:
	GenericObject();
	GenericObject(std::string id, Position currentPosition, TextureAsset* texture, SDL_Rect* rect, double maxSpeed, double acceleration, Orientation orientation);
	~GenericObject();

	///	<summary>
	///	Move (teleport) object to the specified absolute position
	///	</summary>
	void	setCurrentPosition(int x, int y);

	///	<summary>
	///	Move object to the specified relative position
	///	</summary>
	void	setTargetPosition(int x, int y);

	///	<summary>
	///	Sets the orientation of the object
	///	</summary>
	void	setOrientation(Orientation orientation);

	///	<summary>
	///	Move object towards target position
	///	</summary>
	void	move();

	///	<summary>
	///	Detect per-pixel collision between two objects
	///	</summary>
	bool	collidePixel(GenericObject objectB);

	///	<summary>
	///	Detect box collision between two objects
	///	</summary>
	bool	collideBox(GenericObject objectB);

	///	<summary>
	///	Render object in the specified renderer
	///	</summary>
	void	render(SDL_Renderer* renderer);

//	std::string getId();
};

#endif // !_GENERIC_OBJECT_H
