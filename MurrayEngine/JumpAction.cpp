#include "JumpAction.h"

JumpAction::JumpAction(GenericObject* source){
	this->source = source;
}
JumpAction::~JumpAction(){

}
void JumpAction::execute(){
	SDL_Log("made it to JumpAction");
	source->jump();
}

