/*
The concrete action DamageAction
*/

#ifndef _DAMAGE_ACTION_H
#define _DAMAGE_ACTION_H

#include "Object.h"
#include "Action.h"
#include "map.h"

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

class DamageAction : public Action{

public:
//	DamageAction(GameInstance* instance, Object* source, std::vector<Object*> targets);
	DamageAction(Object* source);
	~DamageAction();

	void execute();

	Action*	copy();

private:

//	GameInstance* instance;
	Object* source;
	std::vector<Object*> targets;
};




#endif // !_DAMAGE_ACTION_H

