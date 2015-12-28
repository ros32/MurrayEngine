/*
The concrete action DamageAction
*/

#ifndef _DAMAGEACTION_H
#define _DAMAGEACTION_H

#include "GameInstance.h"
#include "GenericObject.h"
#include "Action.h"

class DamageAction : public Action{

public:
//	DamageAction(GameInstance* instance, GenericObject* source, std::vector<GenericObject*> targets);
	DamageAction(GameInstance* instance, GenericObject* source, std::vector<GenericObject*> targets);
	~DamageAction();
	void execute();

private:
	GameInstance* instance;
	GenericObject* source;
	std::vector<GenericObject*> targets;
};




#endif // !_DAMAGEACTION_H

