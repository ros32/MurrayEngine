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

}