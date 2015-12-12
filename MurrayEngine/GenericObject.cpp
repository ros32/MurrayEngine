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
	this->targetPosition = { 0, 0 };
//	this->tempVector;
	

}

GenericObject::~GenericObject()
{

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

/*
void GenericObject::move()
{
	//	Move object distance equal to current speed closer to target

	
	currentPosition.x += maxSpeed;
	currentPosition.y += maxSpeed;

	//If current XPosition has not yet been reached and current position is greater than maxWidth - 1 spriteWidth: move back 20 pixels
	//Or if current XPosition is less than 1 spriteWidth pixels: add one pixel
	if ((currentPosition.x != targetPosition.x) && (currentPosition.x >= (640 - 32))){
			currentPosition.x = currentPosition.x - 20;
	} else if ((currentPosition.x != targetPosition.x) && (currentPosition.x <= 32)){
			currentPosition.x = currentPosition.x + 20;
	}
	

	//Same in Y as in X axis	
	if ((currentPosition.y != targetPosition.y) && (currentPosition.y >= (480 - 32))){
			currentPosition.y = currentPosition.y - 20;
	} else if ((currentPosition.y != targetPosition.y) && (currentPosition.y <= 32)){
			currentPosition.y = currentPosition.y + 20;
	}
	
	
	tempVector = Map::GetObject(currentPosition);

	for (auto object : tempVector){
		bool isCollided = this->collideBox(object);
		if (isCollided == true){
	
		//	Check which objects collided to perform action
		//	Switch case perhaps
		//	Set targetPosition to current position

		}
	}
	

	// this->render(currentPosition.x, currentPosition.y);
	





	//	Check for collision

	//	If collided, set target position to current position

	//	Perform collision action

	//	Update lastMoved
}
*/

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