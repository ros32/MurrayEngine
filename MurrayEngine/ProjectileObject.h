#ifndef _PROJECTILE_OBJECT_H
#define	_PROJECTILE_OBJECT_H

#include "AnimatedObject.h"

class ProjectileObject: public AnimatedObject
{
public:
	ProjectileObject(std::string id, Position currentPosition, Position targetPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);
	~ProjectileObject();

	void	setTargetPosition(int x, int y);
	void	setTargetPosition(Position pos);

private:

};

#endif // !_PROJECTILE_OBJECT_H
