#include "ExtendedCollisionAction.h"


ExtendedCollisionAction::ExtendedCollisionAction(Map* map, Object* objA){
	this->map = map;
	this->objA = objA;
	this->objB = nullptr;
	this->objectFactory = nullptr;

}

ExtendedCollisionAction::ExtendedCollisionAction(ObjectFactory* objectFactory, Map* map, Object* objA){
	this->map = map;
	this->objectFactory = objectFactory;
	this->objA = objA;
	this->objB = nullptr;
}

ExtendedCollisionAction::~ExtendedCollisionAction(){

}


void ExtendedCollisionAction::execute(Object* objB){

	objA->reverseMove();

//	SDL_Log("An extended collision has been detected");

	std::string typeA;
	std::string typeB;

	std::string aId;
	std::string bId;

	aId = objA->getId();
	bId = objB->getId();

	std::string ghostString = "Ghost";
	std::string heroString = "Hero";
	std::string evolvedString = "Evolved";
	std::string witchString = "Witch";
	std::string projectileString = "Projectile";

	

	//Determin object type for objA
	if (aId.find(ghostString) != std::string::npos){
		typeA = "Ghost";
	} 
	
	else if (aId.find(evolvedString) != std::string::npos){
		typeA = "Evolved";
	}

	else if (aId.find(heroString) != std::string::npos){
		typeA = "Hero";

	}
	else if (aId.find(witchString) != std::string::npos){
		typeA = "Witch";
	}

	else if (aId.find(projectileString) != std::string::npos){
		typeA = "Projectile";
	}
	else{
		typeA = "Wall";
	}

	//Determin object type for objB
	if (bId.find(ghostString) != std::string::npos){
		typeB = "Ghost";
	}

	else if (bId.find(evolvedString) != std::string::npos){
		typeB = "Evolved";
	}

	else if (bId.find(heroString) != std::string::npos){
		typeB = "Hero";
	}
	
	else if (bId.find(witchString) != std::string::npos){
		typeB = "Witch";
	} 

	else if (bId.find(projectileString) != std::string::npos){
		typeB = "Projectile";
	}

	else{
		//Is a wall
		typeB = "Wall";
	}

//	std::string outString;
	//outString = "Collision detected between: " + typeA + " and " + typeB + ".";
//	SDL_Log(outString.c_str());

	//Determin event
	if (typeA == "Ghost"){

		if (typeB == "Ghost"){

			Position spawnPosition = objA->getCurrentPosition();
			objB->reverseMove();
			map->removeObject(objA);
			
			if (objectFactory != nullptr)
				objectFactory->createEvolvedGhost(map, SOUTH, spawnPosition);
		}

		else if (typeB == "Evolved" || typeB == "Witch"){
			//do nothing.. Should never happen.
		}

		else if (typeB == "Hero"){
			//Kill objectB / reduce life of objectB

		}
		else if (typeB == "Projectile"){
			//Kill objectA or reduce life of objectA
			map->removeObject(objB);
		}
		else {
			//is a wall, do nothing
		}

	}
	else if (typeA == "Evolved"){

		if (typeB == "Evolved" || typeB == "Ghost" || typeB == "Witch"){
			//do nothing
		}
		else if (typeB == "Hero"){
			//Kill objectB / reduce life of objectB
		}
		else if (typeB == "Projectile"){
			map->removeObject(objB);
			//is a projectile
			//Kill objectA or reduce life of objectA
			//Delete objectB
			map->removeObject(objB);
		}
		else{
			//is a wall
		}

	}
	else if (typeA == "Hero"){
		if (typeB == "Evolved" || typeB == "Ghost"){
			//Damage typeA, dont kill typeB
		}
		else if (typeB == "Projectile"){
			//Damage typeA and delete typeB
			map->removeObject(objB);

		}
		else if (typeB == "Witch"){
			//do nothing
		}
		else{
			//is a wall
		}
	}

	else if (typeA == "Projectile"){
		if (typeB == "Hero" || typeB == "Ghost" || typeB == "Evolved" || typeB == "Witch"){
			
		//	map->removeObject(objA);
		//	map->removeObject(objB);
				
			//Delete objA and damage/delete objB
		}
		else if (typeB == "Projectile"){
			//Delete both objA and objB
		//	map->removeObject(objA);
		//	map->removeObject(objB);
			
		}
		else{
			//Is a wall
		//	map->removeObject(objA);
		}
	}

	else if (typeA == "Witch"){
		if (typeB == "Projectile"){
			//delete projectile and damage/kill witch
			map->removeObject(objA);
			map->removeObject(objB);
			
		}
		else{
			//do nothing
		}
	}
	else if (typeA == "Wall"){

		if (typeB == "Projectile"){

			map->removeObject(objB);
		}

	}

}



