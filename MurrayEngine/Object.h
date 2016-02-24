#ifndef _GENERIC_OBJECT_H
#define _GENERIC_OBJECT_H

#include	<math.h>
#include	<algorithm>
#include	<assert.h>
#include	<string>
#include	"Position.h"
#include	"TextureAsset.h"
#include	"Timer.h"
#include	"Physics.h"
#include	"Action.h"

class CollisionEvent;

class Action;

enum Orientation
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
	NONE = 4
};

///	<summary>
///	Object is the base class for objects in the game engine.
///	</summary>
class Object
{

public:

	Object();
	Object(std::string id, Position currentPosition, Texture texture, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);

	~Object();

	//	Basic
	virtual std::string				getId();
	virtual void					setId(std::string id);

	//	Position
	virtual Position				getCurrentPosition();
	virtual Position				getTargetPosition();
	virtual void					setCurrentPosition(Position pos);
	virtual void					setCurrentPosition(int x, int y);
	virtual void					setTargetPosition(Position pos);
	virtual void					setTargetPosition(int x, int y);

	//	Speed
	virtual int						getCurrentSpeed();
	virtual double					getMaxSpeed();
	virtual void					setMaxSpeed(double maxSpeed);

	//	Direction
	virtual Orientation				getOrientation();
	virtual void					setOrientation(Orientation orientation);

	//	Texture & Rendering
	virtual Texture					getTexture();
	virtual void					setTexture(Texture texture);
	virtual void					render(int x, int y);

	//	Collision
	virtual bool					collideBox(Object* objectB);
	virtual bool					collidePixel(Object* objectB);
	virtual bool					getIsCollidable();

	// Timer counters
	virtual Uint32					getLastMove();
	virtual Uint32					getLastRender();
	virtual void					setLastRender(Uint32 lastRender);
	virtual void					setLastMove(Uint32 lastMove);

	//	Actions
	virtual void					move();
	virtual void					reverseMove();
	virtual void					jump();
	virtual void					doDamage();
	virtual void					takeDamage();

	//	Action queue
	virtual void					addAction(Action* action);
	virtual Action*					getAction();
	virtual void					doAction();

	virtual bool					readAlpha(SDL_Surface* surface, int x, int y);

	virtual	void					changeAnimation(std::string key);

	virtual void					setCollisionEvent(CollisionEvent* event);

	virtual CollisionEvent*			getCollisionEvent();

	//	Texture asset used by object
	Texture			texture;

protected:

	Timer			timer;

	

private:

	//	Object identifier
	std::string		id;

	//	Current position of object
	Position		currentPosition;

	//	Target position of object
	Position		targetPosition;

	//	Last position of object
	Position		lastPosition;



	//	The maximum speed the Object can travel, or 0 for static
	double			maxSpeed;

	//	The current speed an object is travelling
	int				currentSpeed;

	// If an object can collide with other objects or not
	bool			isCollidable;

	//	Current orientation of object
	Orientation		orientation;

	//	Timestamp of last rendering
	Uint32			lastRender;

	//	Timestamp of last movement
	Uint32			lastMove;

	//	Values of pixel color
	Uint8 red, green, blue, alpha;

	Uint32 rmask, gmask, bmask, amask;

	float			velocity;
	float			force;
	float			mass;

	CollisionEvent* collisionEvent;
	

};

#endif // !_GENERIC_OBJECT_H
