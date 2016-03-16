#include "Fysics.h"

Fysics::Fysics(Map* map){
	this->map = map;
}
Fysics::~Fysics(){

}

void Fysics::calculateImpact(Object* objA, Object* objB){

	bool oposite = false;

	aDirection = objA->getOrientation();
	bDirection = objB->getOrientation();

	int aMass = objA->texture->asset->getWidth();
	int bMass = objB->texture->asset->getWidth();
	int sumMass = aMass + bMass;
	int impulse = sumMass * std::max(objA->getCurrentSpeed(), objB->getCurrentSpeed());

	int ratio = 0;
	int aVel = 0;
	int bVel = 0;


	switch (aDirection){
	case NORTH:

		if (bDirection == SOUTH){
			oposite = true;

			//Velocity for Object A
			ratio = aMass / bMass;
			aVel = ratio * impulse;

			//Move object A accordingly: X:0 Y: + aVel

			//Something like this, but without the jump to position
			//	objA->setCurrentPosition(objA->getCurrentPosition().x + aVel, objA->getCurrentPosition().y);

		
			//Velocity for Object B
		    ratio = bMass / aMass;
			bVel = ratio * impulse;

			//Move object B accordingly: X:0 Y: - bVel

		}

		break;

	case SOUTH:
		if (bDirection == NORTH){
			oposite = true;

			//Velocity for Object A
			ratio = aMass / bMass;
			aVel = ratio * impulse;

			//Move object A accordingly: X:0 Y: - aVel

			//Velocity for Object B
			ratio = bMass / aMass;
			bVel = ratio * impulse;

			//Move object B accordingly: X:0 Y: + bVel
		}
			
		break;

	case EAST:
		if (bDirection == WEST){
			oposite = true;

			//Velocity for Object A
			ratio = aMass / bMass;
			aVel = ratio * impulse;

			//Move object A accordingly: X: -aVel Y: 0

			//Velocity for Object B
			ratio = bMass / aMass;
			bVel = ratio * impulse;

			//Move object A accordingly: X: + bVel Y: 0
		}

		break;

	case WEST:
		if (bDirection == EAST){
			oposite = true;

			//Velocity for Object A
			ratio = aMass / bMass;
			aVel = ratio * impulse;

			//Move object A accordingly: X: + aVel Y: 0

			//Velocity for Object B
			ratio = bMass / aMass;
			bVel = ratio * impulse;

			//Move object A accordingly: X: - bVel Y: 0

		}
			
		break;

	default:
		break;
	}

	if (oposite){

		/*
		int relativeVel;
		
		if (objA->getCurrentSpeed() > objB->getCurrentSpeed()){
			relativeVel = objA->getCurrentSpeed() - objB->getCurrentSpeed();
		}
		else if (objB->getCurrentSpeed() > objA->getCurrentSpeed()){
			relativeVel = objB->getCurrentSpeed() - objA->getCurrentSpeed();
		}
		else{
			relativeVel = objA->getCurrentSpeed() - objB->getCurrentSpeed();
		}
		
		*/

	}

}

void Fysics::calculatePull(Object* objA, Object* objB, int maxDistance){
	

	bool withinRange = true;

	int aWidth = objA->texture->asset->getWidth();
	int aHeight = objA->texture->asset->getHeight();

	int bWidth = objB->texture->asset->getWidth();
	int bHeight = objB->texture->asset->getHeight();

	int aMass = objA->texture->asset->getWidth();

	int xDistance = 0;
	int yDistance = 0;

	Position tempPoint = objB->getCurrentPosition();
	Position gravityPoint = { tempPoint.x + (bWidth / 2), tempPoint.y + (bHeight/2) };

	do{

	if ((objA->getCurrentPosition().x + aWidth) < gravityPoint.x){
		xDistance = gravityPoint.x - (objA->getCurrentPosition().x + aWidth);

		if ((objB->getCurrentPosition().y + aHeight) < gravityPoint.y){
			yDistance = gravityPoint.y - (objA->getCurrentPosition().y + aHeight);

		//	xGravity = objA->getCurrentSpeed() + (xDistance * xDistance * );
		//	yGravity = objA->getCurrentSpeed() + (yDistance);

			//objA->setCurrentPosition(objA->getCurrentPosition().x + (objA->getCurrentSpeed() * xGravity), objA->getCurrentPosition().y + (objA->getCurrentSpeed() * yGravity));
		}
		else if (objB->getCurrentPosition().y > gravityPoint.y){
			yDistance = objA->getCurrentPosition().y - gravityPoint.y;
		}
		else{
			yDistance = gravityPoint.y;
		}

	}
	else if (objA->getCurrentPosition().x > gravityPoint.x){
		xDistance = objA->getCurrentPosition().x - gravityPoint.x;

		if ((objB->getCurrentPosition().y + aHeight) < gravityPoint.y){
			yDistance = gravityPoint.y - (objA->getCurrentPosition().y + aHeight);
		}
		else if (objB->getCurrentPosition().y > gravityPoint.y){
			yDistance = objA->getCurrentPosition().y - gravityPoint.y;
		}
		else{
			yDistance = gravityPoint.y;
		}

	}
	else{
		xDistance = gravityPoint.x;

		if ((objB->getCurrentPosition().y + aHeight) < gravityPoint.y){
			yDistance = gravityPoint.y - (objA->getCurrentPosition().y + aHeight);
		}
		else if (objB->getCurrentPosition().y > gravityPoint.y){
			yDistance = objA->getCurrentPosition().y - gravityPoint.y;
		}
		else{
			yDistance = gravityPoint.y;
		}

	}
	int pullSpeed = 0;

	
		
	} while (objA->getCurrentPosition().x != gravityPoint.x && objA->getCurrentPosition().y != gravityPoint.y && withinRange);
	
	
	
	
	



}

