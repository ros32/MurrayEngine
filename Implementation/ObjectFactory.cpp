#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(GameInstance* gameInstance){
	this->gameInstance = gameInstance;
}
ObjectFactory::~ObjectFactory(){

}



void ObjectFactory::init(){
	createPlayer();

	if (playerCreated){
		createWitch();

		if (witchCreated){
			createGhost("Normal", NORTH, { 0, 0 });

			if (ghostCreated){
				ghostCreated = false;

				createGhost("Normal", SOUTH, { 0, 0 });
				if (ghostCreated){
					ghostCreated = false;
					createGhost("Normal", EAST, { 0, 0 });

					if (ghostCreated){
						ghostCreated = false;
						createGhost("Normal", WEST, { 0, 0 });

						if (ghostCreated){
							ghostCreated = false;
						}
					}
				}
			}

		}
	}
}

void ObjectFactory::createGhostGroup(std::string type){
	createGhost(type, NORTH, { 0, 0 });

	if (ghostCreated){
		ghostCreated = false;
		createGhost(type, SOUTH, { 0, 0 });

		if (ghostCreated){
			ghostCreated = false;
			createGhost(type, WEST, { 0, 0 });

			if (ghostCreated){
				createGhost(type, EAST, { 0, 0 });
				ghostCreated = false;
			}
		}
	}
	
}

void ObjectFactory::createGhost(std::string type, Orientation orientation, Position pos){

	NonPlayerCharacter* npc = nullptr;
	//Position pos = { 0, 0 };
	int speed = 0;
	std::string id;

	this->counter += 1;

	if (type == "Normal"){
		speed = 2;
		id = "Normal" + std::to_string(counter);
	}
	else{
		speed = 5;
		id = "Evolved" + std::to_string(counter);
	}

	this->loadVectors(type);

	if (pos.x == 0){
		switch (orientation){
			//North
		case NORTH:
			pos = { 500, 256 };
			break;
			//East
		case EAST:
			pos = { 576, 352 };
			break;
			//South
		case SOUTH:
			pos = { 500, 448 };
			break;
			//West
		case WEST:
			pos = { 384, 352 };
			break;
		case NONE:
			break;
		default:
			break;
		}
	}



	npc = new NonPlayerCharacter(new AnimatedObject(id, pos, std::make_shared<Animation>(spawnV, 200), 1.0, 1.0, speed, orientation, true));

	npc->addAnimation("Spawn", std::make_shared<Animation>(spawnV, 200));
	npc->addAnimation("North", std::make_shared<Animation>(northV, 200));
	npc->addAnimation("South", std::make_shared<Animation>(southV, 200));
	npc->addAnimation("East", std::make_shared<Animation>(eastV, 200));
	npc->addAnimation("West", std::make_shared<Animation>(westV, 200));

	npc->setAI(new DefaultAI(npc, this->gameInstance->getMap()));
	this->gameInstance->getMap()->addObject(npc);

	this->clearVectors();
	this->ghostCreated = true;


}



void ObjectFactory::createWitch(){

	NonPlayerCharacter* npc = nullptr;

	std::string id = "Witch";

	this->loadVectors("Witch");

	npc = new NonPlayerCharacter(new AnimatedObject(id, { 490, 360 }, std::make_shared<Animation>(inactiveV, 200), 0.0, 0.0, 0, NONE, true));

	npc->addAnimation("Inactive", std::make_shared<Animation>(inactiveV, 200));
	npc->addAnimation("Spawn", std::make_shared<Animation>(spawnV, 200));
	npc->addAnimation("North", std::make_shared<Animation>(northV, 200));
	npc->addAnimation("South", std::make_shared<Animation>(southV, 200));
	npc->addAnimation("East", std::make_shared<Animation>(eastV, 200));
	npc->addAnimation("West", std::make_shared<Animation>(westV, 200));
	npc->addAnimation("Death", std::make_shared<Animation>(deathV, 200));

	//Will set witch specific ai when created
	//npc->setAI(new DefaultAI(npc, this->gameInstance->getMap()));
	this->gameInstance->getMap()->addObject(npc);

	this->clearVectors();
	this->witchCreated = true;
}

void ObjectFactory::createPlayer(){
	std::string id = "Player";

	this->loadVectors("Player");

	NonPlayerCharacter* HeroPlayer = new NonPlayerCharacter(new AnimatedObject("test006", { 33, 33 }, std::make_shared<Animation>(southV, 200), 1.0, 1.0, 3, SOUTH, true));

	HeroPlayer->addAnimation("North", std::make_shared<Animation>(northV, 200));
	HeroPlayer->addAnimation("South", std::make_shared<Animation>(southV, 200));
	HeroPlayer->addAnimation("East", std::make_shared<Animation>(eastV, 200));
	HeroPlayer->addAnimation("West", std::make_shared<Animation>(westV, 200));
	HeroPlayer->addAnimation("Projectile", std::make_shared<Animation>(projectileV, 200));

	this->gameInstance->getMap()->addObject(HeroPlayer);
	this->gameInstance->getMap()->setPlayerCharacter(HeroPlayer);

	this->clearVectors();
	this->playerCreated = true;
}


void ObjectFactory::clearVectors(){

	this->northV.clear();
	this->southV.clear();
	this->westV.clear();
	this->eastV.clear();
	this->spawnV.clear();
	this->inactiveV.clear();
	this->projectileV.clear();
	this->deathV.clear();
}

void ObjectFactory::loadVectors(std::string type){


	if (type == "Normal"){

		//Normal Ghost Animations
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof3"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof3"));

		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack1"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack3"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));

		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostFront1"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostFront2"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostFront3"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostFront2"));

		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostLeft1"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostLeft2"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostLeft3"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostLeft2"));

		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostRight1"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostRight2"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostRight3"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostRight2"));
	}
	else if (type == "Evolved"){

		//Evolved Ghost Animations
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof3"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "Poof3"));

		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack1"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack3"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));

		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront1"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront3"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront5"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront6"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront7"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront8"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));

		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft1"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft3"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft5"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft6"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft7"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft8"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));

		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight1"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight3"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight5"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight6"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight7"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight8"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));

	}
	else if (type == "Witch"){
		//Witch Animations
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft1"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft2"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft3"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft4"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft5"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft6"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft7"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft8"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft9"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft10"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft20"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
		this->inactiveV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));

		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		this->northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));

		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronNeutral"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack1"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack2"));
		this->southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack1"));

		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack1"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack2"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack3"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack4"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack3"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack2"));
		this->westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack1"));

		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronNeutral"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack1"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack2"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack3"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack4"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack3"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack2"));
		this->eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack1"));

		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof1"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof3"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof3"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchPoof1"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying0"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying1"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying2"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying3"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying4"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying5"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying6"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying7"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying8"));
		this->deathV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "Dying9"));

		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning3"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning4"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning1"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning2"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning3"));
		this->spawnV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("WitchSpritesheet"), "WitchLightning4"));

	}
	else{

		northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
		northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroBack2"));
		northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
		northV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroBack3"));

		southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
		southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroFront2"));
		southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
		southV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroFront3"));

		westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
		westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroLeft2"));
		westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
		westV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroLeft3"));

		eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
		eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroRight2"));
		eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
		eastV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("EpicSpriteSheet"), "HeroRight3"));

		projectileV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("ProjectileSheet"), "RedBall"));
		projectileV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("ProjectileSheet"), "BlueBall"));
		projectileV.push_back(std::make_shared<Texture>(this->gameInstance->getTextureAsset("ProjectileSheet"), "GreenBall"));


	}


}
