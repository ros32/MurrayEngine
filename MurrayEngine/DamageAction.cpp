#define _CRTDBG_MAP_ALLOC
#include "DamageAction.h"
/*
DamageAction::DamageAction(GameInstance* instance, Object* source, std::vector<Object*> targets) 
{	
	this->instance = instance;
	this->source = source;
	this->targets = targets;
}
*/

DamageAction::DamageAction(Object* source)
{
	this->source = source;
}

DamageAction::~DamageAction()
{

}

void DamageAction::execute()
{
	source->doDamage();

	/*
	for (auto target : targets)
	{
	target->takeDamage();

	//get target HP
	//If target HP <=0, call map->removeObject(target)
	}
	*/
}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source);
}




