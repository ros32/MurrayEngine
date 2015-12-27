#include "AnimatedObject.h"

AnimatedObject::AnimatedObject() : GenericObject()
{

}

AnimatedObject::AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision) : 
	GenericObject(id, currentPosition, Texture(), maxSpeed, acceleration, currentSpeed, orientation, hasCollision)
{
	this->animation = animation;
}

Animation	AnimatedObject::getAnimation()
{
	return this->animation;
}

void		AnimatedObject::setAnimation(Animation animation)
{
	this->animation = animation;
}

void		AnimatedObject::render()
{
	if (this->timer.getTicks() > this->getLastRender() + this->animation.time)
	{
		if (this->animation.textures.size() >= this->animation.lastTexture)
			this->animation.lastTexture = 0;

		std::stringstream ss(this->animation.textures[this->animation.lastTexture++]);

		std::string segment;
		std::vector<std::string> splitString;
		std::string tileset;
		std::string texture;

		while (std::getline(ss, segment, '.'))
		{
			splitString.push_back(segment);
		}

		if (splitString.size() >= 2)
		{
			tileset = splitString[0];
			texture = splitString[1];
		}
		else
		{

		}
	}
}