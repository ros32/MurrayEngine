#include "CopyAction.h"


CopyAction::CopyAction(Object* npc, Action* action){
	this->npc = npc;
	this->action = action;
}
CopyAction::~CopyAction(){

}
void CopyAction::execute(){
	
	this->npc->addAction(action);

}
Action* CopyAction::copy(){

	return new CopyAction(this->npc, this->action);
}
