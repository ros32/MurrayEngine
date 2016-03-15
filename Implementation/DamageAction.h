/*
The concrete action DamageAction
*/

#ifndef _DAMAGE_ACTION_H
#define _DAMAGE_ACTION_H

#include "Object.h"
#include "Action.h"
#include "Map.h"
#include "ProjectileObject.h"
#include "NonPlayerCharacter.h"
#include "ExtendedCollisionAction.h"

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

class ObjectFactory;
class DamageAction : public Action{

public:
	DamageAction(Object* source, Map* map);
	~DamageAction();

	void execute();

	Action*	copy();

private:

	Object* source;
	std::vector<Object*> targets;
	Map* map;
	static int counter;
};




#endif // !_DAMAGE_ACTION_H

