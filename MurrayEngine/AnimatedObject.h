#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include <vector>
#include <sstream>
#include <memory>
#include "Object.h"


struct Animation
{
	std::vector<std::shared_ptr<Texture>>	textures;
	int time;
	int lastTexture;

	Animation()
	{
		textures.push_back(nullptr);
		time = 10000;
		lastTexture = 0;
	}

	Animation(std::vector<std::shared_ptr<Texture>> tx, int tm)
	{
		textures = tx;
		time = tm;
		lastTexture = 0;
	}

	~Animation()
	{
		textures.clear();
	}
};

class AnimatedObject: public Object
{
public:
	AnimatedObject();
	AnimatedObject(std::string id, Position currentPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);
	virtual ~AnimatedObject();

	void	render(int x, int y);

	std::shared_ptr<Animation>	getAnimation();
	std::shared_ptr<Animation>  getAnimation(std::string key);


	void						setAnimation(std::shared_ptr<Animation> animation);
	void						addAnimation(std::string key, std::shared_ptr<Animation> animation);
	void						changeAnimation(std::string key);

	std::shared_ptr<Texture>	getCollisionTexture();

private:
	std::map<std::string, std::shared_ptr<Animation>> animationMap;
	std::shared_ptr<Animation>	animation;
	typedef std::map<std::string, std::shared_ptr<Animation>>::iterator iterator;
	std::shared_ptr<Texture>	collisionTexture = nullptr;

};

#endif // !_ANIMATED_OBJECT_H
