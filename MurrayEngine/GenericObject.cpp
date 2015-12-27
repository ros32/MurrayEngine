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
	this->timer = Timer();

	this->timer.start();
	this->lastRender = 0;
	this->lastMove = 0;
	

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
	return hasCollision;
}

void GenericObject::reverseMove()
{
		//North 
		if (this->orientation == 0){ this->currentPosition.y += 1; }
		//East 
		if (this->orientation == 1){ this->currentPosition.x -= 1; }
		//South
		if (this->orientation == 2){ this->currentPosition.y -= 1; }
		//West
		if (this->orientation == 3){ this->currentPosition.x += 1; }

}

void GenericObject::move()
{
	//Save the currentposition before we move
	
	
	this->lastPosition = this->currentPosition;

	//Add the velocity to the current position
	currentPosition.x += this->currentSpeed * this->targetPosition.x;
	currentPosition.y += this->currentSpeed * this->targetPosition.y;

	this->targetPosition = { 0, 0 };
	
}

bool GenericObject::collideBox(GenericObject* objectB)
{
	bool hit = true;
	
	//TODO: Implement and use textureWidth and Size instead of cellSize
	textureWidth = texture->getCellSize();
	textureHeight = texture->getCellSize();

	int otherTextureWidth = objectB->texture->getCellSize();
	int otherTextureHeight = objectB->texture->getCellSize();

	int left = currentPosition.x;
	int right = currentPosition.x + textureWidth;
	int bottom = currentPosition.y;
	int top = currentPosition.y + textureHeight;

	int otherLeft = objectB->currentPosition.x;
	int otherRight = objectB->currentPosition.x + otherTextureWidth;
	int otherBottom = objectB->currentPosition.y;
	int otherTop = objectB->currentPosition.y + otherTextureHeight;

	//Checks if there is a distance between the current object sides and the other object sides.
	if (right < otherLeft){
		hit =  false;
	} 
	if (left > otherRight){
		hit = false;
	}
	if (top < otherBottom){
		hit =  false;
	} 
	if (bottom > otherTop){
		hit = false;
	} 
	if (hit){
		SDL_Log("Hit is true");
	}
	else{
		SDL_Log("Hit is false");
	}
	
		return hit;
	
}

bool GenericObject::collidePixel(GenericObject* objectB)
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
	{
		this->texture->render(x, y, this->texture->getSourceRect(this->textureName));
		this->lastRender = this->timer.getTicks();
}
}

int		GenericObject::getCurrentSpeed()
{
	return this->currentSpeed;
}

void   GenericObject::jump()
{
	SDL_Log("Jumping");
}
void   GenericObject::damage()
{
	SDL_Log("doing some damage");
}
void  GenericObject::takeDamage()
{
	SDL_Log("Taking some damage");
}

void	GenericObject::setTexture(TextureAsset* texture)
{
	this->texture = texture;
}

void	GenericObject::setTextureName(std::string name)
{
	this->textureName = name;
}