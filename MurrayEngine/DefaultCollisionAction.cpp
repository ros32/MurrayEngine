#include "DefaultCollisionAction.h"

DefaultCollisionAction::DefaultCollisionAction(Object* objA){
	this->objA = objA;
}

DefaultCollisionAction::~DefaultCollisionAction(){

}

void DefaultCollisionAction::execute(Object* objB){

	SDL_Log("A collision has been detected");

}





