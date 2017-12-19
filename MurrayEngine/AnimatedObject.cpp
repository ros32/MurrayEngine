#include "AnimatedObject.h"

AnimatedObject::AnimatedObject(const std::string id, const Position currentPosition, const std::shared_ptr<Animation> animation, const double maxSpeed, const double acceleration, const int currentSpeed, const Orientation orientation, const bool isCollidable) :
	Object(id, currentPosition, nullptr, maxSpeed, acceleration, currentSpeed, orientation, isCollidable)
{
	this->animation = animation;
	this->Object::setTexture(this->animation->textures[0]);
}

AnimatedObject::~AnimatedObject()
{

}

std::shared_ptr<Animation>	AnimatedObject::getAnimation() const
{
	return this->animation;
}

std::shared_ptr<Animation> AnimatedObject::getAnimation(std::string key)
{
	const iterator iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		auto tempAnimation = iterator->second;
		return tempAnimation;
	}
	else{
		auto errorMessage = "A value for key \"" + key + "\" does not exist";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());
	}
	return nullptr;
}

void		AnimatedObject::setAnimation(const std::shared_ptr<Animation> animation)
{
	this->animation = animation;
}

void		AnimatedObject::addAnimation(std::string key, std::shared_ptr<Animation> animation){
	const iterator iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		auto errorMessage = "A value for key \"" + key + "\" already exist";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());

	}
	else{
		animationMap.insert(std::pair<std::string, std::shared_ptr<Animation>>(key, animation));
	}

}

void		AnimatedObject::changeAnimation(std::string key){
	const iterator iterator = this->animationMap.find(key);

	if (iterator != this->animationMap.end()){
		const auto tempAnimation = iterator->second;
		this->setAnimation(tempAnimation);
	}
	else{
		auto errorMessage = "A value for key \"" + key + "\" does not exist";
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errorMessage.c_str());
	}
}

void		AnimatedObject::render(const int x, const int y)
{
	const auto lastRender = this->getLastRender();
	if (this->timer.getTicks() > this->getLastRender() + this->animation->time)
	{
		if (this->animation->lastTexture >= this->animation->textures.size())
			this->animation->lastTexture = 0;

		this->setTexture(this->animation->textures[this->animation->lastTexture++]);
		Object::render(x, y);
	}
	else
	{
		Object::render(x, y);
		this->setLastRender(lastRender);
	}
}

std::shared_ptr<Texture>	AnimatedObject::getCollisionTexture()
{
	if (this->collisionTexture == nullptr)
		this->collisionTexture = this->animation->textures[0];
	return this->collisionTexture;
}