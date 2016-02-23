
#include "ProjectileObject.h"

ProjectileObject::ProjectileObject(std::string id, Position currentPosition, Position targetPosition, Animation animation, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool isCollidable): 
	AnimatedObject(id, currentPosition, animation, maxSpeed, acceleration, currentSpeed, orientation, isCollidable){

	this->targetPosition = targetPosition;
}

ProjectileObject::~ProjectileObject(){

}

void	ProjectileObject::setTargetPosition(int x, int y){
	this->targetPosition = { x, y };
}
void	ProjectileObject::setTargetPosition(Position pos){
	this->targetPosition = pos;
}




