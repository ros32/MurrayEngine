#define _CRTDBG_MAP_ALLOC
#include	"NonPlayerCharacter.h"

NonPlayerCharacter::NonPlayerCharacter()
{
	this->baseObject = nullptr;
	this->actionQueue;
}

NonPlayerCharacter::NonPlayerCharacter(AnimatedObject* object)
{
	this->baseObject = object;
	this->actionQueue;

}

NonPlayerCharacter::~NonPlayerCharacter()
{
	delete this->baseObject;
	delete this->ai;

	while (!this->actionQueue.empty())
	{
		delete this->actionQueue.front();
		this->actionQueue.pop();
	}
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

std::shared_ptr<Texture>		NonPlayerCharacter::getTexture()
{
	return this->baseObject->getTexture();
}

std::shared_ptr<Texture>		NonPlayerCharacter::getCollisionTexture()
{
	return this->baseObject->getCollisionTexture();
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

void	NonPlayerCharacter::setTexture(std::shared_ptr<Texture> texture)
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

std::shared_ptr<Animation>	NonPlayerCharacter::getAnimation()
{
	return this->baseObject->getAnimation();
}

void		NonPlayerCharacter::setAnimation(std::shared_ptr<Animation> animation)
{
	this->baseObject->setAnimation(animation);
}

void		NonPlayerCharacter::addAnimation(std::string key, std::shared_ptr<Animation> animation)
{
	this->baseObject->addAnimation(key, animation);
}

void		NonPlayerCharacter::changeAnimation(std::string key)
{
	this->baseObject->changeAnimation(key);
}

AnimatedObject*		NonPlayerCharacter::getBaseObject()
{
	return this->baseObject;
}

void				NonPlayerCharacter::setBaseObject(AnimatedObject* object)
{
	this->baseObject = object;
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