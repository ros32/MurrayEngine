#define _CRTDBG_MAP_ALLOC
#include "ActionControl.h"



ActionControl::ActionControl(){

}

ActionControl::~ActionControl(){

}

void ActionControl::setAction(Action *action){
	this->action = action;
}

void ActionControl::buttonPressed(){
//	SDL_Log("Arrived at ActionControl");
	action->execute();
}
