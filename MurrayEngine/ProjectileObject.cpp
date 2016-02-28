#define _CRTDBG_MAP_ALLOC
#include "ProjectileObject.h"

ProjectileObject::ProjectileObject(std::string id, Position currentPosition, Position targetPosition, std::shared_ptr<Animation> animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable): 
	AnimatedObject(id, currentPosition, animation, maxSpeed, acceleration, currentSpeed, orientation, isCollidable){

	this->targetPosition = targetPosition;
	this->animation = animation;
}

ProjectileObject::~ProjectileObject(){
	
}

void	ProjectileObject::setTargetPosition(int x, int y){
	this->targetPosition = { x, y };
}
void	ProjectileObject::setTargetPosition(Position pos){
	this->targetPosition = pos;
}
Position   ProjectileObject::getTargetPosition(){
	return this->targetPosition;
}










