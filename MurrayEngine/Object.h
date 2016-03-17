#ifndef _GENERIC_OBJECT_H
#define _GENERIC_OBJECT_H

#include	<memory>
#include	<algorithm>
#include	"Orientation.h"
#include	"Position.h"
#include	"Timer.h"
#include	"Action.h"
#include	"Texture.h"
#include	"DefaultCollisionAction.h"

class CollisionAction;
struct Animation;
class Action;

///-------------------------------------------------------------------------------------------------
/// <summary>	The Object class is the most basic representation of something that should be
/// 			displayed in the game. An Object has a static image and can be moved. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class Object
{

public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="id">			  	The identifier. </param>
	/// <param name="currentPosition">	The current position. </param>
	/// <param name="texture">		  	The texture. </param>
	/// <param name="maxSpeed">		  	The maximum speed. </param>
	/// <param name="acceleration">   	The acceleration. </param>
	/// <param name="currentSpeed">   	The current speed. </param>
	/// <param name="orientation">	  	The orientation. </param>
	/// <param name="isCollidable">   	true if this object is collidable. </param>
	///-------------------------------------------------------------------------------------------------
	Object(std::string id, Position currentPosition, std::shared_ptr<Texture> texture, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~Object();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the identifier. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The identifier. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual std::string				getId();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets an identifier. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="id">	The identifier. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setId(std::string id);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets current position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The current position. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Position				getCurrentPosition();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets target position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The target position. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Position				getTargetPosition();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets current position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setCurrentPosition(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets current position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setCurrentPosition(int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets target position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setTargetPosition(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets target position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setTargetPosition(int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets current speed. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The current speed. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual int						getCurrentSpeed();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets maximum speed. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The maximum speed. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual double					getMaxSpeed();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets maximum speed. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="maxSpeed">	The maximum speed. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setMaxSpeed(double maxSpeed);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the orientation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The orientation. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Orientation				getOrientation();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets an orientation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="orientation">	The orientation. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setOrientation(Orientation orientation);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The texture. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual std::shared_ptr<Texture>	getTexture();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets collision texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The collision texture. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual std::shared_ptr<Texture>	getCollisionTexture();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="texture">	The texture. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setTexture(std::shared_ptr<Texture> texture);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Renders this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					render(int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Collide box. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objectB">	[in,out] If non-null, the object b. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual bool					collideBox(Object* objectB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Collide pixel. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objectB">	[in,out] If non-null, the object b. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual bool					collidePixel(Object* objectB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets is collidable. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual bool					getIsCollidable();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the last move. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The last move. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Uint32					getLastMove();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the last render. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The last render. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Uint32					getLastRender();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets last render. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="lastRender">	The last render. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setLastRender(Uint32 lastRender);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Reverse move. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual void					reverseMove();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds an action. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="action">	[in,out] If non-null, the action. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					addAction(Action* action);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the action. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the action. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Action*					getAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the action operation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual void					doAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Reads an alpha. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="surface">	[in,out] If non-null, the surface. </param>
	/// <param name="x">	  	The x coordinate. </param>
	/// <param name="y">	  	The y coordinate. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual bool					readAlpha(SDL_Surface* surface, int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Change animation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="key">	The key. </param>
	///-------------------------------------------------------------------------------------------------
	virtual	void					changeAnimation(std::string key);



	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets an animation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="key">	The key. </param>
	///
	/// <returns>	The animation. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual std::shared_ptr<Animation> getAnimation(std::string key);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds an animation to 'animation'. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="key">			The key. </param>
	/// <param name="animation">	The animation. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	addAnimation(std::string key, std::shared_ptr<Animation> animation);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets collision action. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="collisionAction">	[in,out] If non-null, the collision action. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	setCollisionAction(CollisionAction* collisionAction);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the collision action operation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="obj">	[in,out] If non-null, the object. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	doCollisionAction(Object* obj);

protected:

	/// <summary>	The timer. </summary>
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

	CollisionAction* collisionAction;

	/// <summary>	The texture. </summary>
	std::shared_ptr<Texture>			texture;
	
};

#endif // !_GENERIC_OBJECT_H
