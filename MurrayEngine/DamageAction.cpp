#include "DamageAction.h"

DamageAction::DamageAction(GameInstance* instance, Object* source, std::vector<Object*> targets) {
	this->instance = instance;
	this->source = source;
	this->targets = targets;
}

DamageAction::~DamageAction(){

}
void DamageAction::execute(){
	source->doDamage();

	for (auto target : targets){
		target->takeDamage();

		//get target HP
		//If target HP <=0, call map->removeObject(target)
	}
}
