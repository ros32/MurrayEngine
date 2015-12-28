#include "InputControl.h"



InputControl::InputControl(){

}

InputControl::~InputControl(){

}

void InputControl::setAction(Action *action){
	this->action = action;
}

void InputControl::buttonPressed(){
	SDL_Log("Arrived at InputControl");
	action->execute();
}
