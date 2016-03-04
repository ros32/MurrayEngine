#ifndef _PROJECTILE_OBJECT_H
#define	_PROJECTILE_OBJECT_H

#include "AnimatedObject.h"
#include "Object.h"
#include "MoveAction.h"
#include "Map.h"

class ProjectileObject: public AnimatedObject
{
public:
	ProjectileObject(std::string id, Position currentPosition, Position targetPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable);
	~ProjectileObject();

	void	setTargetPosition(int x, int y);
	void	setTargetPosition(Position pos);
	Position getTargetPosition();	
//	void move();

private:

	Position targetPosition;
	std::shared_ptr<Animation> animation;
	Map* map;

};

#endif // !_PROJECTILE_OBJECT_H
