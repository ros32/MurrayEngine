#include	"NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter()
{
	this->actionQueue;
}

NonPlayerCharacter::~NonPlayerCharacter()
{
	delete this->baseObject;
}

std::string NonPlayerCharacter::getId()
{
	return this->baseObject->getId();
}

void	NonPlayerCharacter::setId(std::string id)
{
	this->baseObject->setId(id);
}

Position NonPlayerCharacter::getCurrentPosition()
{
	return this->baseObject->getCurrentPosition();
}

void NonPlayerCharacter::setCurrentPosition(int x, int y)
{
	this->baseObject->setCurrentPosition(x, y);
}

void	NonPlayerCharacter::setCurrentPosition(Position pos)
{
	this->baseObject->setCurrentPosition(pos);
}

Position NonPlayerCharacter::getTargetPosition(){

	return this->baseObject->getTargetPosition();
}

void NonPlayerCharacter::setTargetPosition(int x, int y)
{
	this->baseObject->setTargetPosition(x, y);
}

void	NonPlayerCharacter::setTargetPosition(Position pos)
{
	this->baseObject->setTargetPosition(pos);
}

void NonPlayerCharacter::setOrientation(Orientation orientation)
{
	this->baseObject->setOrientation(orientation);
}

Orientation NonPlayerCharacter::getOrientation()
{
	return this->baseObject->getOrientation();
}

double NonPlayerCharacter::getMaxSpeed()
{
	return this->baseObject->getMaxSpeed();
}

void	NonPlayerCharacter::setMaxSpeed(double speed)
{
	this->baseObject->setMaxSpeed(speed);
}

bool NonPlayerCharacter::getIsCollidable()
{
	return this->baseObject->getIsCollidable();
}

void NonPlayerCharacter::reverseMove()
{
	this->baseObject->reverseMove();
}

void NonPlayerCharacter::move()
{
	this->baseObject->move();
}

bool NonPlayerCharacter::collideBox(Object* objectB)
{
	return this->baseObject->collideBox(objectB);
}

bool NonPlayerCharacter::readAlpha(SDL_Surface* surface, int x, int y)
{
	return this->baseObject->readAlpha(surface, x, y);
}

bool NonPlayerCharacter::collidePixel(Object* objectB)
{
	return this->baseObject->collidePixel(objectB);
}

Texture			NonPlayerCharacter::getTexture()
{
	return this->baseObject->getTexture();
}

void NonPlayerCharacter::render(int x, int y)
{
	this->baseObject->render(x, y);
}

int		NonPlayerCharacter::getCurrentSpeed()
{
	return this->baseObject->getCurrentSpeed();
}

void   NonPlayerCharacter::jump()
{
	this->baseObject->jump();
}
void   NonPlayerCharacter::doDamage()
{
	this->baseObject->doDamage();
}
void  NonPlayerCharacter::takeDamage()
{
	this->baseObject->takeDamage();
}

void	NonPlayerCharacter::setTexture(Texture texture)
{
	this->baseObject->setTexture(texture);
}

Uint32	NonPlayerCharacter::getLastRender()
{
	return this->baseObject->getLastRender();
}

Uint32	NonPlayerCharacter::getLastMove()
{
	return this->baseObject->getLastMove();
}

void	NonPlayerCharacter::setLastMove(Uint32 lastMove)
{
	this->baseObject->setLastMove(lastMove);
}

void	NonPlayerCharacter::setLastRender(Uint32 lastRender)
{
	this->baseObject->setLastRender(lastRender);
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