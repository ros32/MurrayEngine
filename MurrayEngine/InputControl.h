#ifndef _INPUT_CONTROL_H
#define _INPUT_CONTROL_H

#include "Action.h"
#include <SDL.h>

struct KeyState2
{
	bool	key_m = false;
	bool    key_enter = false;
	bool	key_space = false;
};

class InputControl{

public:
	InputControl();

	~InputControl();

	Action* inputHandler();


private:
	Action* buttonEnter;
	Action* buttonSpace;
	Action* buttonM;
	Action* JumpAction;

	KeyState2 keyState;


};




#endif // !_INPUT_CONTROL_H