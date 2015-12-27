#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include "GenericObject.h"
#include "TextureAsset.h"
#include <vector>
#include <sstream>

struct Animation
{
	std::vector<std::string>	textures;
	int time;
	int lastTexture;
};

class AnimatedObject: public GenericObject
{
public:
	AnimatedObject();
	AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision);
	~AnimatedObject();

	void	render();

	Animation	getAnimation();
	void		setAnimation(Animation animation);

private:

	Animation	animation;

};

#endif // !_ANIMATED_OBJECT_H
