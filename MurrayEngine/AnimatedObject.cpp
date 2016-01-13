#include "AnimatedObject.h"

AnimatedObject::AnimatedObject() : Object()
{

}

AnimatedObject::AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable) : 
	Object(id, currentPosition, Texture(), maxSpeed, acceleration, currentSpeed, orientation, isCollidable)
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
		Object::render(x, y);
	}
	else
	{
		Object::render(x, y);
		this->setLastRender(lastRender);
	}

	
}