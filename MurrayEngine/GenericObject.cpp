#include "GenericObject.h"

GenericObject::GenericObject()
{

}

GenericObject::GenericObject(std::string id, Position currentPosition, TextureAsset* texture, std::string textureName, double maxSpeed, double acceleration, Orientation orientation)
{
	this->id = id;
	this->currentPosition = currentPosition;
	this->texture = texture;
	this->textureName = textureName;
	this->maxSpeed = maxSpeed;
	//this->acceleration = acceleration;
	this->orientation = orientation;
}

GenericObject::~GenericObject()
{

}

void GenericObject::setCurrentPosition(int x, int y)
{
	this->currentPosition = { x, y };
}

void GenericObject::setTargetPosition(int x, int y)
{
	this->targetPosition = { x, y };
}

void GenericObject::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}

void GenericObject::move()
{
	//	Move object distance equal to current speed closer to target

	//	Check for collision

	//	If collided, set target position to current position

	//	Perform collision action

	//	Update lastMoved
}

bool GenericObject::collideBox(GenericObject objectB)
{
	//	compare position of object a rect and object b rect

	//	If object a rect placed on object a position overlaps object b rect placed on object b position

		//	return true since objects has collided

	//	Else return false since objects has not collided
	return false;
}

bool GenericObject::collidePixel(GenericObject objectB)
{
	//	should only be run when collideBox is true




	return false;
}

void GenericObject::render(int x, int y)
{

}