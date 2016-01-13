/*
The concrete action JumpAction
*/

#ifndef _JUMPACTION_H
#define _JUMPACTION_H

#include "Object.h"
#include "Action.h"

class JumpAction : public Action{

public:
	JumpAction(Object* source);
	~JumpAction();

	void execute();

private:

	Object* source;

};



#endif //!_JUMPACTION_H