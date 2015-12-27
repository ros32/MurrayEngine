#include "DamageAction.h"

DamageAction::DamageAction() {
	this->instance = instance;
	this->source = source;
	this->targets = targets;
}

DamageAction::~DamageAction(){

}
void DamageAction::execute(GenericObject* source){
	source->damage();

	for (auto target : targets){
		target->takeDamage();
	}
}
