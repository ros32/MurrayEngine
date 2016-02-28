#ifndef _ANIMATION_H
#define	_ANIMATION_H

#include	<vector>
#include	<memory>
#include	"Texture.h"

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

#endif // !_ANIMATION_H
