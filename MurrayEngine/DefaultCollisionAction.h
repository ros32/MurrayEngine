#ifndef _DEFAULT_COLLISION_ACTION
#define _DEFAULT_COLLISION_ACTION

#include "CollisionAction.h"
#include <SDL.h>

class NonPlayerCharacter;

class DefaultCollisionAction : public CollisionAction{

public:

	DefaultCollisionAction(NonPlayerCharacter* objA);
	~DefaultCollisionAction();

	void execute(NonPlayerCharacter* objB);



private:
	NonPlayerCharacter* objA;
	NonPlayerCharacter* objB;

};


#endif //!_DEFAULT_COLLISION_ACTION