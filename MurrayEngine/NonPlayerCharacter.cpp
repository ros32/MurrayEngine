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
	if (this->baseObject != nullptr)
		return this->baseObject->getId();
	else
		return "NO_BASE_OBJ";
}

void	NonPlayerCharacter::setId(std::string id)
{
	if (this->baseObject != nullptr)
		this->baseObject->setId(id);
}

Position NonPlayerCharacter::getCurrentPosition()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getCurrentPosition();
	else
		return{ 0, 0 };
}


std::shared_ptr<Animation> NonPlayerCharacter::getAnimation(std::string key)
{
	if (this->baseObject != nullptr)
		return this->baseObject->getAnimation(key);
	else
		return nullptr;
}




void NonPlayerCharacter::setCurrentPosition(int x, int y)
{
	if (this->baseObject != nullptr)
		this->baseObject->setCurrentPosition(x, y);
}

void	NonPlayerCharacter::setCurrentPosition(Position pos)
{
	if (this->baseObject != nullptr)
		this->baseObject->setCurrentPosition(pos);
}

Position NonPlayerCharacter::getTargetPosition()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getTargetPosition();
	else
		return{ 0, 0 };
}

void NonPlayerCharacter::setTargetPosition(int x, int y)
{
	if (this->baseObject != nullptr)
		this->baseObject->setTargetPosition(x, y);
}

void	NonPlayerCharacter::setTargetPosition(Position pos)
{
	if (this->baseObject != nullptr)
		this->baseObject->setTargetPosition(pos);
}

void NonPlayerCharacter::setOrientation(Orientation orientation)
{
	if (this->baseObject != nullptr)
		this->baseObject->setOrientation(orientation);
}

Orientation NonPlayerCharacter::getOrientation()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getOrientation();
	else
		return NONE;
}

double NonPlayerCharacter::getMaxSpeed()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getMaxSpeed();
	else
		return 0.0;
}

void	NonPlayerCharacter::setMaxSpeed(double speed)
{
	if (this->baseObject != nullptr)
		this->baseObject->setMaxSpeed(speed);
}

bool NonPlayerCharacter::getIsCollidable()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getIsCollidable();
	else
		return false;
}

void NonPlayerCharacter::reverseMove()
{
	if (this->baseObject != nullptr)
		this->baseObject->reverseMove();
}

void NonPlayerCharacter::move()
{
	if (this->baseObject != nullptr)
		this->baseObject->move();
}

bool NonPlayerCharacter::collideBox(Object* objectB)
{
	if (this->baseObject != nullptr)
		return this->baseObject->collideBox(objectB);
	else
		return false;
}

bool NonPlayerCharacter::readAlpha(SDL_Surface* surface, int x, int y)
{
	if (this->baseObject != nullptr)
		return this->baseObject->readAlpha(surface, x, y);
	else
		return false;
}

bool NonPlayerCharacter::collidePixel(Object* objectB)
{
	if (this->baseObject != nullptr)
		return this->baseObject->collidePixel(objectB);
	else
		return false;
}

std::shared_ptr<Texture>		NonPlayerCharacter::getTexture()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getTexture();
	return nullptr;
}

std::shared_ptr<Texture>		NonPlayerCharacter::getCollisionTexture()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getCollisionTexture();
	return nullptr;
}

void NonPlayerCharacter::render(int x, int y)
{
	if (this->baseObject != nullptr)
		this->baseObject->render(x, y);
}

int		NonPlayerCharacter::getCurrentSpeed()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getCurrentSpeed();
	return 0;
}

void   NonPlayerCharacter::jump()
{
	if (this->baseObject != nullptr)
		this->baseObject->jump();
}
void   NonPlayerCharacter::doDamage()
{
	if (this->baseObject != nullptr)
		this->baseObject->doDamage();
}
void  NonPlayerCharacter::takeDamage()
{
	if (this->baseObject != nullptr)
		this->baseObject->takeDamage();
}

void	NonPlayerCharacter::setTexture(std::shared_ptr<Texture> texture)
{
	if (this->baseObject != nullptr)
		this->baseObject->setTexture(texture);
}

Uint32	NonPlayerCharacter::getLastRender()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getLastRender();
	return 0;
}

Uint32	NonPlayerCharacter::getLastMove()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getLastMove();
	return 0;
}

void	NonPlayerCharacter::setLastMove(Uint32 lastMove)
{
	if (this->baseObject != nullptr)
		this->baseObject->setLastMove(lastMove);
}

void	NonPlayerCharacter::setLastRender(Uint32 lastRender)
{
	if (this->baseObject != nullptr)
		this->baseObject->setLastRender(lastRender);
}

void		NonPlayerCharacter::addAction(Action* action)
{
	this->actionQueue.push(action);
}

std::shared_ptr<Animation>	NonPlayerCharacter::getAnimation()
{
	if (this->baseObject != nullptr)
		return this->baseObject->getAnimation();
	return nullptr;
}

void		NonPlayerCharacter::setAnimation(std::shared_ptr<Animation> animation)
{
	if (this->baseObject != nullptr)
		this->baseObject->setAnimation(animation);
}

void		NonPlayerCharacter::addAnimation(std::string key, std::shared_ptr<Animation> animation)
{
	if (this->baseObject != nullptr)
		this->baseObject->addAnimation(key, animation);
}

void		NonPlayerCharacter::changeAnimation(std::string key)
{
	if (this->baseObject != nullptr)
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

bool NonPlayerCharacter::actionExists()
{
	if (!this->actionQueue.empty())
		return true;
	return false;
}