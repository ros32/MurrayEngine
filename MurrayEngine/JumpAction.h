#ifndef _JUMPACTION_H
#define _JUMPACTION_H

#include "GenericObject.h"
#include "Action.h"

class JumpAction : public Action{
//	JumpAction(GenericObject* source);
	JumpAction();
	~JumpAction();

	void execute(GenericObject* source);

private:

	GenericObject* source;

};



#endif //´!_JUMPACTION_H