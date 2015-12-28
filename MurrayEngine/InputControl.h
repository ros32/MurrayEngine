/*
Invoker
Stores the concrete actions
*/

#ifndef _INPUT_CONTROL_H
#define _INPUT_CONTROL_H

#include "Action.h"

class InputControl{

public:
	InputControl();

	~InputControl();

	void setAction(Action *action);

	void buttonPressed();

private:
	Action *action;

};




#endif // !_INPUT_CONTROL_H