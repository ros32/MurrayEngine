#include "JumpAction.h"

JumpAction::JumpAction(){
	this->source = source;
}
JumpAction::~JumpAction(){

}
void JumpAction::execute(GenericObject* source){
	SDL_Log("made it to JumpAction");
	source->jump();
}

