#include	"ChangeInputModeAction.h"

ChangeInputModeAction::ChangeInputModeAction(KeyController* keyController)
{
	this->keyController = keyController;
}

ChangeInputModeAction::~ChangeInputModeAction()
{

}

void	ChangeInputModeAction::execute()
{
	if (this->keyController != nullptr)
	{
		this->keyController->setTextInputMode(!this->keyController->getTextInputMode());
	}
}

Action*	ChangeInputModeAction::copy()
{
	return new ChangeInputModeAction(this->keyController);
}