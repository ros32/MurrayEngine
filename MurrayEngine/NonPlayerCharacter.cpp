#include	"NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter()
{
	this->actionQueue;
}

NonPlayerCharacter::~NonPlayerCharacter()
{

}

void		NonPlayerCharacter::addAction(Action* action)
{
	this->actionQueue.push(action);
}

void		NonPlayerCharacter::doAction()
{
	Action*	tempAction = nullptr;

	if (!this->actionQueue.empty())
		tempAction = this->actionQueue.front();

	if (tempAction != nullptr)
	{
		if (!tempAction->isCompleted())
			tempAction->execute();
		else
		{
			delete tempAction;
			this->actionQueue.pop();
			this->doAction();
		}
	}

}