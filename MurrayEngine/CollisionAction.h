#ifndef _COLLISION_ACTION_H
#define _COLLISION_ACTION_H

//class NonPlayerCharacter;
class Object;

///-------------------------------------------------------------------------------------------------
/// <summary>	The CollisionAction class is (despite the name) NOT an implementation of the Action
/// 			interface, but an interface in itself.
/// 			
/// 			The CollisionAction class controls what will happen when two objects collide. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class CollisionAction{

public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	CollisionAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objA">	[in,out] If non-null, the object a. </param>
	///-------------------------------------------------------------------------------------------------
	explicit CollisionAction(Object* objA);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~CollisionAction() = 0;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the given object b. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objB">	[in,out] If non-null, the object b. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void execute(Object* objB) = 0;



private:


};


#endif //!_COLLISION_ACTION_H