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

AnimatedObject::~AnimatedObject()
{

}

Animation	AnimatedObject::getAnimation()
{
	return this->animation;
}

void		AnimatedObject::setAnimation(Animation animation)
{
	this->animation = animation;
}

//std::vector<Texture>
std::vector<Texture> AnimatedObject::getAnimationVector(std::string key)
{
	SDL_Log("inside getAnimationVector");
	iterator iterator;
	iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		SDL_Log("Key in getAnimationVector was found");
		Animation tempAnimation = iterator->second;
		return tempAnimation.textures;
	}
	else{
		SDL_Log("Key in getAnimationVector was NOT found");
	}
}

int	AnimatedObject::getAnimationTime(std::string key)
{
	iterator iterator;
	iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		SDL_Log("Key in getAnimationTime was found");
		Animation tempAnimation = iterator->second;
		return tempAnimation.time;
	}
	else{
		SDL_Log("Key in getAnimationTime was NOT found");
	}
}

void		AnimatedObject::addAnimation(std::string key, Animation animation){
	//Check if animation already exists, otherwise add to map.
	iterator iterator;
	iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		std::string errorMessage = "A value for key \"" + key + "\" already exist";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());

	}
	else{
		animationMap.insert(std::pair<std::string, Animation>(key, animation));
	}

}

void		AnimatedObject::changeAnimation(std::string key){
	//Check if key exists, if it does, change to requested animation
	iterator iterator;
	iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		Animation tempAnimation = iterator->second;
		this->setAnimation(tempAnimation);
	}
	else{
		std::string errorMessage = "A value for key \"" + key + "\" does not exist";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());
	}
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