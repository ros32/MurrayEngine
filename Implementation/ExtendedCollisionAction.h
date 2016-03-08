#ifndef _EXTENDED_COLLISION_ACTION_H
#define _EXTENDED_COLLISION_ACTION_H

#include "CollisionAction.h"
#include "NonPlayerCharacter.h"
#include "map.h"
#include "ObjectFactory.h"

class ObjectFactory;
class ExtendedCollisionAction : public CollisionAction{

public:
	ExtendedCollisionAction(NonPlayerCharacter* objA);
	~ExtendedCollisionAction();

	void execute(NonPlayerCharacter* objB);



private:

	NonPlayerCharacter* objA;
	NonPlayerCharacter* objB;
	ObjectFactory* objectFactory;

	Map* map;
};


#endif //!_COLLISION_ACTION_H