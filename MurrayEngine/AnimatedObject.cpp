#include "AnimatedObject.h"

AnimatedObject::AnimatedObject() : GenericObject()
{

}

AnimatedObject::AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision) : 
	GenericObject(id, currentPosition, Texture(), maxSpeed, acceleration, currentSpeed, orientation, hasCollision)
{
	this->animation = animation;
	this->setTexture(this->animation.textures[0]);
}

Animation	AnimatedObject::getAnimation()
{
	return this->animation;
}

void		AnimatedObject::setAnimation(Animation animation)
{
	this->animation = animation;
}

void		AnimatedObject::render(int x, int y)
{
	Uint32 lastRender = this->getLastRender();
	if (this->timer.getTicks() > this->getLastRender() + this->animation.time)
	{
		if (this->animation.lastTexture >= this->animation.textures.size())
			this->animation.lastTexture = 0;

		this->setTexture(this->animation.textures[this->animation.lastTexture++]);
		GenericObject::render(x, y);
	}
	else
	{
		GenericObject::render(x, y);
		this->setLastRender(lastRender);
	}

	
}