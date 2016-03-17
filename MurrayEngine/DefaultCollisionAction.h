#ifndef _DEFAULT_COLLISION_ACTION
#define _DEFAULT_COLLISION_ACTION

#include "CollisionAction.h"
#include "Object.h"

class Object;

///-------------------------------------------------------------------------------------------------
/// <summary>	The DefaultCollisionAction class is a default implementation of the CollisionAction
/// 			interface.
/// 			
/// 			When executed, DefaultCollisionAction will move the objA 1 px away from objB.
/// 			</summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class DefaultCollisionAction : public CollisionAction{

public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objA">	[in,out] If non-null, the object a. </param>
	///-------------------------------------------------------------------------------------------------
	DefaultCollisionAction(Object* objA);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~DefaultCollisionAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the given object b. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objB">	[in,out] If non-null, the object b. </param>
	///-------------------------------------------------------------------------------------------------
	void execute(Object* objB);



private:
	Object* objA;
	Object* objB;

};


#endif //!_DEFAULT_COLLISION_ACTION