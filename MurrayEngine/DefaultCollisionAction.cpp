#include "DefaultCollisionAction.h"

DefaultCollisionAction::DefaultCollisionAction(NonPlayerCharacter* objA){
	this->objA = objA;
}

DefaultCollisionAction::~DefaultCollisionAction(){

}

void DefaultCollisionAction::execute(NonPlayerCharacter* objB){

	SDL_Log("A collision has been detected");

}





