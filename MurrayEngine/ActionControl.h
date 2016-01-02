/*
Invoker
Stores the concrete actions
*/

#ifndef _ACTION_CONTROL_H
#define _ACTION_CONTROL_H

#include "Action.h"

class ActionControl{

public:
	ActionControl();

	~ActionControl();

	void setAction(Action *action);

	void buttonPressed();

private:
	Action *action;

};




#endif // !_ACTION_CONTROL_H