/*
The concrete action DamageAction
*/

#ifndef _DAMAGEACTION_H
#define _DAMAGEACTION_H

#include "GameInstance.h"
#include "Object.h"
#include "Action.h"

class DamageAction : public Action{

public:
	DamageAction(GameInstance* instance, Object* source, std::vector<Object*> targets);
	~DamageAction();
	void execute();

private:
	GameInstance* instance;
	Object* source;
	std::vector<Object*> targets;
};




#endif // !_DAMAGEACTION_H

