#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include "GenericObject.h"
#include "TextureAsset.h"
#include <vector>
#include <sstream>

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

class AnimatedObject: public GenericObject
{
public:
	AnimatedObject();
	AnimatedObject(std::string id, Position currentPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision);
	~AnimatedObject();

	void	render(int x, int y);

	Animation	getAnimation();
	void		setAnimation(Animation animation);

private:

	Animation	animation;

};

#endif // !_ANIMATED_OBJECT_H
