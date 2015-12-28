#include "DamageAction.h"

DamageAction::DamageAction(GameInstance* instance, GenericObject* source, std::vector<GenericObject*> targets) {
	this->instance = instance;
	this->source = source;
	this->targets = targets;
}

DamageAction::~DamageAction(){

}
void DamageAction::execute(){
	source->damage();

	for (auto target : targets){
		target->takeDamage();
	}
}
