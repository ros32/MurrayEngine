#include "ExtendedCollisionAction.h"

ExtendedCollisionAction::ExtendedCollisionAction(Object* objA){
	this->objA = objA;
	this->objB = nullptr;
}

ExtendedCollisionAction::~ExtendedCollisionAction(){

}


void ExtendedCollisionAction::execute(Object* objB){

	SDL_Log("An extended collision has been detected");

	std::string typeA;
	std::string typeB;

	std::string aId;
	std::string bId;

	//aId = objA->getId();

	//Determin object type for objA
	if (objA->getId().find("Normal")){
		typeA = "Normal";
	}

	else if (objA->getId().find("Evolved")){
		typeA = "Evolved";
	}

	else if (objA->getId().find("Player")){
		typeA = "Player";

	} else if (objA->getId().find("Witch")){
		typeA = "Witch";
	}

	else{
		typeA = "Projectile";
	}

	//Determin object type for objB
	if (objB->getId().find("Normal")){
		typeB = "Normal";
	}

	else if (objB->getId().find("Evolved")){
		typeB = "Evolved";
	}

	else if (objB->getId().find("Player")){
		typeB = "Player";
	}
	
	else if (objB->getId().find("Witch")){
		typeB = "Witch";
	} 

	else{
		typeB = "Projectile";
	}



	//Determin event
	if (typeA == "Normal"){

		if (typeB == "Normal"){

			Position spawnPosition = objA->getCurrentPosition();
			//...Delete both ghosts
			//objectFactory->createEvolvedGhost(map, SOUTH, spawnPosition);
		}

		else if (typeB == "Evolved" || typeB == "Witch"){
			//do nothing..?
		}

		else if (typeB == "Player"){
			//Kill objectB / reduce life of objectB
		}
		else{
			//is a projectile
			//Kill objectA or reduce life of objectA
			//Delete objectB
		}

	}
	else if (typeA == "Evolved"){

		if (typeB == "Evolved" || typeB == "Normal" || typeB == "Witch"){
			//do nothing
		}
		else if (typeB == "Player"){
			//Kill objectB / reduce life of objectB
		}
		else{
			//is a projectile
			//Kill objectA or reduce life of objectA
			//Delete objectB
		}
	}
	else if (typeA == "Player"){
		if (typeB == "Evolved" || typeB == "Normal"){
			//Damage typeA, dont kill typeB
		}
		else if (typeB == "Projectile"){
			//Damage typeA and delete typeB

		}
		else if (typeB == "Witch"){
			//do nothing
		}
	}
	else if (typeA == "Projectile"){
		if (typeB == "Player" || typeB == "Normal" || typeB == "Evolved" || typeB == "Witch"){
			//Delete objA and damage/delete objB
		}
		else if (typeB == "Projectile"){
			//Delete both objA and objB
		}
	}
	else if (typeA == "Witch"){
		if (typeB == "projectile"){
			//delete projectile and damage/kill witch
		}
		else{
			//do nothing
		}
	}

}



