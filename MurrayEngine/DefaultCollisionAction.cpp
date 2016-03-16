#include "DefaultCollisionAction.h"

DefaultCollisionAction::DefaultCollisionAction(Object* objA){
	this->objA = objA;
	this->objB = nullptr;
}

DefaultCollisionAction::~DefaultCollisionAction(){

}

void DefaultCollisionAction::execute(Object* objB){
	this->objA->reverseMove();
	
}





