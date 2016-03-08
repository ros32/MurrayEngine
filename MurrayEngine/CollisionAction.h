#ifndef _COLLISION_ACTION_H
#define _COLLISION_ACTION_H

class NonPlayerCharacter;

class CollisionAction{

public:
	CollisionAction();
	CollisionAction(NonPlayerCharacter* objA);

	virtual ~CollisionAction() = 0;

	virtual void execute(NonPlayerCharacter* objB) = 0;



private:


};


#endif //!_COLLISION_ACTION_H