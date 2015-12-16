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
	WEST = 3,
	NONE = 4
};

///	<summary>
///	GenericObject is the base class for objects in the game engine.
///	</summary>
class GenericObject
{

public:

	///	<summary>
	///	Create an empty object
	///	</summary>
	GenericObject();

	///	<summary>
	///	Creates an object with the values provided
	///	</summary>
	GenericObject(std::string id, Position currentPosition, TextureAsset* texture, std::string textureName, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision);

	~GenericObject();

	///	<summary>
	///	Returns the identifier of the object
	///	</summary>
	std::string				getId();

	///	<summary>
	///	Set the identifier of the object
	///	</summary>
	void					setId(std::string id);

	///	<summary>
	///	Returns the current position of the object
	///	</summary>
	Position				getCurrentPosition();

	///	<summary>
	///	Set the current position of an object
	///	</summary>
	///	<remarks>
	///	This will teleport the object to the specified location.
	///	To have the game engine handle the movement, use <see cref="GenericObject.setTargetPosition(Position pos)"/> instead.
	///	</remarks>
	void					setCurrentPosition(Position pos);

	///	<summary>
	///	Set the current position of an object
	///	</summary>
	///	<remarks>
	///	This will teleport the object to the specified location.
	///	To have the game engine handle the movement, use <see cref="GenericObject.setTargetPosition(Position pos)"/> instead.
	///	</remarks>
	void					setCurrentPosition(int x, int y);

	///	<summary>
	///	Returns the current speed of the object.
	///	</summary>
	int						getCurrentSpeed();

	///	<summary>
	///	Returns the target position of where the object is moving, 
	///	as a value relative to current position
	///	</summary>
	Position				getTargetPosition();

	///	<summary>
	///	Set the target position for where the object should move.
	///	Use <c>GenericObject.move()</c> to perform the movement.
	///	</summary>
	void					setTargetPosition(Position pos);

	///	<summary>
	///	Set the target position for where the object should move.
	///	Use <c>GenericObject.move()</c> to perform the movement.
	///	</summary>
	void					setTargetPosition(int x, int y);

	///	<summary>
	///	Returns a pointer to the TextureAsset used by the object.
	///	</summary>
	TextureAsset*			getTexture();

	///	<summary>
	///	Sets the TextureAsset used by the object
	///	</summary>
	void					setTexture(TextureAsset* texture);

	///	<summary>
	///	Returns the name of the texture used from the TextureAsset
	///	</summary>
	std::string				getTextureName();

	///	<summary>
	///	Sets the name of the texture to use from the TextureAsset
	///	</summary>
	void					setTextureName(std::string name);

	///	<summary>
	///	Returns the maximum speed the object is capable of moving
	///	</summary>
	double					getMaxSpeed();

	///	<summary>
	///	Sets the maximum possible speed of the object
	///	</summary>
	void					setMaxSpeed(double maxSpeed);

	///	<summary>
	///	Returns the orientation of the object
	///	</summary>
	Orientation				getOrientation();

	///	<summary>
	///	Sets the orientation of the object
	///	</summary>
	void					setOrientation(Orientation orientation);

	///	<summary>
	///	Returns a timestamp of when the object was last rendered
	///	</summary>
	Uint32					getLastRender();

	///	<summary>
	///	Sets a timestamp of when the object was last rendered
	///	</summary>
	void					setLastRender(Uint32 lastRender);

	///	<summary>
	///	Returns a timestamp of when the object was last moved
	///	</summary>
	Uint32					getLastMove();

	///	<summary>
	///	Sets a timestamp of when the object was last moved.
	///	</summary>
	void					setLastMove(Uint32 lastMove);

	///	<summary>
	///	Perform movement operation and move target from
	///	currentPosition to targetPosition, resetting targetPosition
	///	</summary>
	void					move();

	///	<summary>
	///	Perform pixel-based collision detection. Returns true
	///	if a pixel from one object collides with a pixel from the other
	///	object.
	///	</summary>
	bool					collidePixel(GenericObject* objectB);

	///	<summary>
	///	Perform block-based collision detection. Returns true if 
	///	the SDL_Rect from one object overlaps the SDL_Rect from the
	///	other object.
	///	</summary>
	bool					collideBox(GenericObject* objectB);

	///	<summary>
	///	Performs rendering of the objects texture in the specified position
	///	</summary>
	void					render(int x, int y);

	///	<summary>
	///	Returns true if the object should use collision detection
	///	</summary>
	bool					getHasCollision();

	///	<summary>
	///	Reverses the move operation and restores the currentPositoin from 
	///	lastPosition. 
	///	<summary>
	void					reverseMove();

private:

	//	Object identifier
	std::string id;

	//	Current position of object
	Position	currentPosition;

	//	Target position of object
	Position	targetPosition;

	//	Last position of object
	Position	lastPosition;

	//	Texture asset used by object
	TextureAsset*	texture;

	//	SDL_Rect of texture asset
	std::string		textureName;

	//	The maximum speed the GenericObject can travel, or 0 for static
	double			maxSpeed;

	//	The current speed an object is travelling
	int			currentSpeed;

	// If an object can collide with other objects or not
	bool		hasCollision;

	//	Current orientation of object
	Orientation		orientation;

	//	Timer used for measuring rendering and movement
	Timer			timer;

	//	Timestamp of last rendering
	Uint32			lastRender;

	//	Timestamp of last movement
	Uint32			lastMove;

	//	Height and witdth of texture
	int textureWidth, textureHeight;
};

#endif // !_GENERIC_OBJECT_H
