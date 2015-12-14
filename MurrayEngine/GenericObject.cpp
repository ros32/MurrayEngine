#include "GenericObject.h"

GenericObject::GenericObject()
{

}

GenericObject::GenericObject(std::string id, Position currentPosition, TextureAsset* texture, std::string textureName, double maxSpeed, double acceleration, int currentSpeed, Orientation orientation, bool hasCollision)
{
	this->id = id;
	this->currentPosition = currentPosition;
	this->texture = texture;
	this->textureName = textureName;
	this->maxSpeed = maxSpeed;
	this->currentSpeed = currentSpeed;
	//this->acceleration = acceleration;
	this->orientation = orientation;
	this->targetPosition = { 0, 0 };
	this->hasCollision = hasCollision;
	this->lastPosition;
	

}

GenericObject::~GenericObject()
{

}

std::string GenericObject::getId()
{
	return id;
}

Position GenericObject::getCurrentPosition()
{
	return currentPosition;
}

void GenericObject::setCurrentPosition(int x, int y)
{
	this->currentPosition = { x, y };
}

Position GenericObject::getTargetPosition(){

	return targetPosition;
}

void GenericObject::setTargetPosition(int x, int y)
{
	this->targetPosition = { x, y };
}

void GenericObject::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}

Orientation GenericObject::getOrientation()
{
	return orientation;
}

double GenericObject::getMaxSpeed()
{
	return maxSpeed;
}

bool GenericObject::getHasCollision()
{
//	return hasCollision;

	return true;
}

void GenericObject::reverseMove()
{
	currentPosition = lastPosition;
}

void GenericObject::move()
{
	//Save the currentposition before we move
	lastPosition = currentPosition;

	int directionValue;
	//Set the appropriate directionValue after orientation
	switch (orientation){
		//North 
	case 0:
		directionValue = 1;
		break;
		//East
	case 1:
		directionValue = 1;
		break;
		//South
	case 2:
		directionValue = -1;
		break;
		//West
	case 3:
		directionValue = -1;
		break;
		//None
	default:
		break;
	}
	//The amount of pixels to travel in both x/y axis
	int velocity = currentSpeed * directionValue;

	//Add the velocity to the current position
	currentPosition.x += velocity;
	currentPosition.y += velocity;

	//If the new currentPosition is too close to the map edge, step back through reverseMove
	if ((currentPosition.x > (640 - 32)) || (currentPosition.x < 32) || (currentPosition.y >(480 - 32)) || (currentPosition.y < 32)){
        reverseMove();
	}
	
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

TextureAsset*	GenericObject::getTexture()
{
	return this->texture;
}

std::string		GenericObject::getTextureName()
{
	return this->textureName;
}

void GenericObject::render(int x, int y)
{
	if (this->texture != nullptr && this->textureName != "")
		this->texture->render(x, y, this->texture->getSourceRect(this->textureName));
}