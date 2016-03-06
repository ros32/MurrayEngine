#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include	"Object.h"
#include	"Animation.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	An animated object. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class AnimatedObject: public Object
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="id">			  	The identifier. </param>
	/// <param name="currentPosition">	The current position. </param>
	/// <param name="animation">	  	The animation. </param>
	/// <param name="maxSpeed">		  	The maximum speed. </param>
	/// <param name="acceleration">   	The acceleration. </param>
	/// <param name="currentSpeed">   	The current speed. </param>
	/// <param name="orientation">	  	The orientation. </param>
	/// <param name="isCollidable">   	true if this object is collidable. </param>
	///-------------------------------------------------------------------------------------------------
	AnimatedObject(std::string id, Position currentPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~AnimatedObject();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Renders this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	///-------------------------------------------------------------------------------------------------
	void	render(int x, int y);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the animation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The animation. </returns>
	///-------------------------------------------------------------------------------------------------
	std::shared_ptr<Animation>	getAnimation();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets an animation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">	The key. </param>
	///
	/// <returns>	The animation. </returns>
	///-------------------------------------------------------------------------------------------------
	std::shared_ptr<Animation>  getAnimation(std::string key);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets an animation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="animation">	The animation. </param>
	///-------------------------------------------------------------------------------------------------
	void						setAnimation(std::shared_ptr<Animation> animation);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds an animation to 'animation'. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">			The key. </param>
	/// <param name="animation">	The animation. </param>
	///-------------------------------------------------------------------------------------------------
	void						addAnimation(std::string key, std::shared_ptr<Animation> animation);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Change animation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="key">	The key. </param>
	///-------------------------------------------------------------------------------------------------
	void						changeAnimation(std::string key);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets collision texture. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The collision texture. </returns>
	///-------------------------------------------------------------------------------------------------
	std::shared_ptr<Texture>	getCollisionTexture();

private:
	/// <summary>	The animation map. </summary>
	std::map<std::string, std::shared_ptr<Animation>> animationMap;

	/// <summary>	The animation. </summary>
	std::shared_ptr<Animation>	animation;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Defines an alias representing the iterator. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	typedef std::map<std::string, std::shared_ptr<Animation>>::iterator iterator;

	/// <summary>	The collision texture. </summary>
	std::shared_ptr<Texture>	collisionTexture;

};

#endif // !_ANIMATED_OBJECT_H
