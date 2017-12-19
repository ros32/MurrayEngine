#ifndef _EXTENDED_COLLISION_ACTION_H
#define _EXTENDED_COLLISION_ACTION_H

#include "CollisionAction.h"
#include "Object.h"
#include "Map.h"
#include "ObjectFactory.h"

class ObjectFactory;

///-------------------------------------------------------------------------------------------------
/// <summary>	The ExtendedCollisionAction is an implementation of the CollisionAction interface
/// 			that controls collision for the objects in our implementation. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class ExtendedCollisionAction : public CollisionAction{

public:
	ExtendedCollisionAction(Map* map, Object* objA);
	ExtendedCollisionAction(ObjectFactory* objectFactory, Map* map, Object* objA);
	~ExtendedCollisionAction();

	void execute(Object* objB) override;



private:

	Object* objA;
	Object* objB;
	ObjectFactory* objectFactory;
	GameInstance* gameInstance;

	Map* map;
};


#endif //!_COLLISION_ACTION_H