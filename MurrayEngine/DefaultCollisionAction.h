#ifndef _DEFAULT_COLLISION_ACTION
#define _DEFAULT_COLLISION_ACTION

#include "CollisionAction.h"
#include "Object.h"
#include <SDL.h>

class Object;

class DefaultCollisionAction : public CollisionAction{

public:

	DefaultCollisionAction(Object* objA);
	~DefaultCollisionAction();

	void execute(Object* objB);



private:
	Object* objA;
	Object* objB;

};


#endif //!_DEFAULT_COLLISION_ACTION