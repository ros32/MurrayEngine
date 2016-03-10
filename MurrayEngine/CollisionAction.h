#ifndef _COLLISION_ACTION_H
#define _COLLISION_ACTION_H

//class NonPlayerCharacter;
class Object;

class CollisionAction{

public:
	CollisionAction();
	CollisionAction(Object* objA);

	virtual ~CollisionAction() = 0;

	virtual void execute(Object* objB) = 0;



private:


};


#endif //!_COLLISION_ACTION_H