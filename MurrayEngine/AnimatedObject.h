#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include <vector>
#include <sstream>
#include "Object.h"


struct Animation
{
	std::vector<Texture>	textures;
	int time;
	int lastTexture;

	Animation()
	{
		textures.push_back(Texture());
		time = 10000;
		lastTexture = 0;
	}

	Animation(std::vector<Texture> tx, int tm)
	{
		textures = tx;
		time = tm;
		lastTexture = 0;
	}
};

class AnimatedObject: public Object
{
public:
	AnimatedObject();
	AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);
	~AnimatedObject();

	void	render(int x, int y);

	Animation	getAnimation();


	void						setAnimation(Animation animation);
	void						addAnimation(std::string key, Animation animation);
	void						changeAnimation(std::string key);
	std::vector<Texture>		getAnimationVector(std::string key);
	int							getAnimationTime(std::string key);

private:
	std::map<std::string, Animation> animationMap;
	Animation	animation;
	typedef std::map<std::string, Animation>::iterator iterator;

};

#endif // !_ANIMATED_OBJECT_H
