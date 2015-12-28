/*
The concrete action JumpAction
*/

#ifndef _JUMPACTION_H
#define _JUMPACTION_H

#include "GenericObject.h"
#include "Action.h"

class JumpAction : public Action{

public:
	JumpAction(GenericObject* source);
	~JumpAction();

	void execute();

private:

	GenericObject* source;

};



#endif //´!_JUMPACTION_H