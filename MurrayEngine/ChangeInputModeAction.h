#ifndef _CHANGE_INPUT_MODE_ACTION_H
#define	_CHANGE_INPUT_MODE_ACTION_H

#include	"Action.h"
#include	"KeyController.h"

class ChangeInputModeAction: public Action
{
public:
	ChangeInputModeAction(KeyController* keyController);
	~ChangeInputModeAction();

	void	execute();

private:

	KeyController* keyController;

};

#endif // !_CHANGE_INPUT_MODE_ACTION_H
