#ifndef _NON_PLAYER_CHARACTER_H
#define	_NON_PLAYER_CHARACTER_H

#include	<queue>
#include	"AnimatedObject.h"
#include	"AI.h"
#include    "DefaultCollisionAction.h"

class CollisionAction;
class AI;

///-------------------------------------------------------------------------------------------------
/// <summary>	The NonPlayerCharacter class is a representation of an AnimatedObject that can perform
/// 			Actions (has an actionQueue) and an AI.
/// 			
/// 			The Action Queue allows the NonPlayerCharacter to execute actions such as the default
/// 			MoveAction (or other actions written by the implementation). </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class NonPlayerCharacter : public AnimatedObject
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
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
	NonPlayerCharacter(std::string id, Position currentPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~NonPlayerCharacter();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets an i. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else a i. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual AI*						getAI();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets an i. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="ai">	[in,out] If non-null, the ai. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void					setAI(AI* ai);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds an action. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="action">	[in,out] If non-null, the action. </param>
	///-------------------------------------------------------------------------------------------------
	void					addAction(Action* action) override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the action. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the action. </returns>
	///-------------------------------------------------------------------------------------------------
	Action*					getAction() override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the action operation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void					doAction() override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Queries if a given action exists. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual bool actionExists();


protected:

	

private:

	/// <summary>	The ai. </summary>
	AI*								ai;

	/// <summary>	Queue of actions. </summary>
	std::queue<Action*>	actionQueue;

	/// <summary>	The collision action. </summary>
	CollisionAction* collisionAction;

};

#endif // !_NON_PLAYER_CHARACTER_H
