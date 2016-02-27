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

DamageAction::DamageAction(Object* source, Map* map)
{
	this->source = source;
	this->map = map;
}

DamageAction::~DamageAction()
{

}

void DamageAction::execute()
{
	source->changeAnimation("projectile");


}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source, this->map);
}




