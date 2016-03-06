#include	"NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter(std::string id, Position currentPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable) :
	AnimatedObject(id, currentPosition, animation, maxSpeed, acceleration, currentSpeed, orientation, isCollidable)
{
	this->actionQueue;
	this->ai = nullptr;
}


NonPlayerCharacter::~NonPlayerCharacter()
{
	delete this->ai;

	while (!this->actionQueue.empty())
	{
		delete this->actionQueue.front();
		this->actionQueue.pop();
	}
}

void		NonPlayerCharacter::addAction(Action* action)
{
	this->actionQueue.push(action);
}

AI*					NonPlayerCharacter::getAI()
{
	return this->ai;
}

void				NonPlayerCharacter::setAI(AI* ai)
{
	this->ai = ai;
}

void		NonPlayerCharacter::doAction()
{
	if (this->ai != nullptr)
		this->ai->doNext();

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
		}
	}

}

Action* NonPlayerCharacter::getAction()
{
	if (!this->actionQueue.empty())
		return this->actionQueue.front();
	return nullptr;
}

bool NonPlayerCharacter::actionExists()
{
	if (!this->actionQueue.empty())
		return true;
	return false;
}