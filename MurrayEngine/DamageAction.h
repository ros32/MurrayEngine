#ifndef _DAMAGEACTION_H
#define _DAMAGEACTION_H

#include "GameInstance.h"
#include "GenericObject.h"
#include "Action.h"

class DamageAction : public Action{

public:
//	DamageAction(GameInstance* instance, GenericObject* source, std::vector<GenericObject*> targets);
	DamageAction();
	~DamageAction();
	void execute(GenericObject* source);

private:
	GameInstance* instance;
	GenericObject* source;
	std::vector<GenericObject*> targets;
};




#endif // !_DAMAGEACTION_H

