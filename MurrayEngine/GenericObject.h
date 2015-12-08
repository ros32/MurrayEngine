#ifndef _GENERIC_OBJECT_H
#define _GENERIC_OBJECT_H

#include	<string>
#include	"Position.h"
#include	"TextureAsset.h"
#include	"Timer.h"
#include	"Camera.h"

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
	SDL_Texture*	texture;

	///	SDL_Rect of texture asset
	SDL_Rect*		rect;

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
	GenericObject(std::string id, Position currentPosition, SDL_Texture* texture, SDL_Rect* rect, double maxSpeed, double acceleration, Orientation orientation);
	~GenericObject();

	std::string				getId();
	void					setId(std::string id);

	Position				getCurrentPosition();

	///	<summary>
	///	Move (teleport) object to the specified absolute position
	///	</summary>
	void					setCurrentPosition(Position pos);

	///	<summary>
	///	Move (teleport) object to the specified absolute position
	///	</summary>
	void					setCurrentPosition(int x, int y);

	Position				getTargetPosition();

	///	<summary>
	///	Move object to the specified relative position
	///	</summary>
	void					setTargetPosition(Position pos);

	void					setTargetPosition(int x, int y);

	SDL_Texture*			getTexture();
	void					setTexture(SDL_Texture* texture);

	SDL_Rect*				getRect();
	void					setRect(SDL_Rect* rect);

	double					getMaxSpeed();
	void					setMaxSpeed(double maxSpeed);

	Orientation				getOrientation();

	///	<summary>
	///	Sets the orientation of the object
	///	</summary>
	void					setOrientation(Orientation orientation);

	Uint32					getLastRender();
	void					setLastRender(Uint32 lastRender);

	Uint32					getLastMove();
	void					setLastMove(Uint32 lastMove);

	///	<summary>
	///	Move object towards target position
	///	</summary>
	void					move();

	///	<summary>
	///	Detect per-pixel collision between two objects
	///	</summary>
	bool					collidePixel(GenericObject objectB);

	///	<summary>
	///	Detect box collision between two objects
	///	</summary>
	bool					collideBox(GenericObject objectB);

	///	<summary>
	///	Render object in the specified renderer
	///	</summary>
	void					render(Camera* camera);



//	std::string getId();
};

#endif // !_GENERIC_OBJECT_H
