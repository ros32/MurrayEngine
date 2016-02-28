#ifndef _ANIMATED_OBJECT_H
#define _ANIMATED_OBJECT_H

#include	<vector>
#include	<sstream>
#include	<memory>
#include	"Object.h"
#include	"Animation.h"




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
