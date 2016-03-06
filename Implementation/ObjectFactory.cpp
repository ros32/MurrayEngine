#include "ObjectFactory.h"

ObjectFactory::ObjectFactory()
{
	this->counter = 0;
}
ObjectFactory::~ObjectFactory()
{

}

Map*		ObjectFactory::createMap(Configuration configuration)
{
	//	Use base class default map factory
	Map*	map = Factory::createMap(configuration);

	//	Create objects in map
	//this->init(map);
	
	this->createPlayer(map, SOUTH, { 33, 33 });
	
	this->createGhost(map, EAST, { 576, 352 });
	this->createGhost(map, SOUTH, { 500, 448 });
	this->createGhost(map, WEST, { 384, 352 });
	this->createGhost(map, NORTH, { 500, 256 });

	this->createWitch(map, NONE, { 490, 360 });

	this->createEvolvedGhost(map, EAST, { 600, 360 });

	//	Return map
	return map;
}

NonPlayerCharacter*	ObjectFactory::createNonPlayerCharacter(std::string type, std::string id, Orientation direction, Position pos)
{

	std::vector < std::shared_ptr<Texture> >  northVector;
	std::vector < std::shared_ptr<Texture> >  southVector;
	std::vector < std::shared_ptr<Texture> >  eastVector;
	std::vector < std::shared_ptr<Texture> >  westVector;
	std::vector < std::shared_ptr<Texture> >  inactiveVector;
	std::vector < std::shared_ptr<Texture> >  spawnVector;
	std::vector < std::shared_ptr<Texture> >  deathVector;
	std::vector < std::shared_ptr<Texture> >  projectileVector;

	NonPlayerCharacter* npc = nullptr;

	if (type == "Ghost")
	{
		//Normal Ghost Animations
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof3"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof3"));

		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack1"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack3"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));

		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostFront1"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostFront2"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostFront3"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostFront2"));

		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostLeft1"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostLeft2"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostLeft3"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostLeft2"));

		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostRight1"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostRight2"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostRight3"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostRight2"));

		npc = new NonPlayerCharacter(id, pos, std::make_shared<Animation>(spawnVector, 200), 1.0, 1.0, 2, direction, true);
		npc->addAnimation("Spawn", std::make_shared<Animation>(spawnVector, 200));
		npc->addAnimation("North", std::make_shared<Animation>(northVector, 200));
		npc->addAnimation("South", std::make_shared<Animation>(southVector, 200));
		npc->addAnimation("East", std::make_shared<Animation>(eastVector, 200));
		npc->addAnimation("West", std::make_shared<Animation>(westVector, 200));

	}
	else if (type == "Evolved")
	{

		//Evolved Ghost Animations
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof3"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "Poof3"));

		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack1"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack3"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "GhostBack2"));

		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront1"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront3"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront5"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront6"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront7"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront4"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront8"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthFront2"));

		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft1"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft3"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft5"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft6"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft7"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft4"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft8"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthLeft2"));

		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight1"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight3"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight5"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight6"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight7"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight4"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight8"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "MouthRight2"));

		npc = new NonPlayerCharacter(id, pos, std::make_shared<Animation>(spawnVector, 200), 1.0, 1.0, 4, direction, true);
		npc->addAnimation("Spawn", std::make_shared<Animation>(spawnVector, 200));
		npc->addAnimation("North", std::make_shared<Animation>(northVector, 200));
		npc->addAnimation("South", std::make_shared<Animation>(southVector, 200));
		npc->addAnimation("East", std::make_shared<Animation>(eastVector, 200));
		npc->addAnimation("West", std::make_shared<Animation>(westVector, 200));

	}
	else if (type == "Witch")
	{
		//Witch Animations
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft1"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft2"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft3"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft4"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft5"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft6"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft7"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft8"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft9"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft10"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft11"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft12"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft13"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft20"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft19"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft18"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft17"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft16"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft15"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft14"));
		inactiveVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));

		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "BackWithCauldron"));

		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronNeutral"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack1"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack2"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "FrontWithCauldronAttack1"));

		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "CauldronLeft0"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack1"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack2"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack3"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack4"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack3"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack2"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "LeftWithCauldronAttack1"));

		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronNeutral"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack1"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack2"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack3"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack4"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack3"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack2"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "RightWithCauldronAttack1"));

		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof1"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof3"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof3"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof2"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchPoof1"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying0"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying1"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying2"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying3"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying4"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying5"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying6"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying7"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying8"));
		deathVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "Dying9"));

		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning3"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning4"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning1"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning2"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning3"));
		spawnVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("WitchSpritesheet"), "WitchLightning4"));

		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "RedBall"));
		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "BlueBall"));
		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "GreenBall"));

		npc = new NonPlayerCharacter(id, pos, std::make_shared<Animation>(spawnVector, 200), 1.0, 1.0, 0, direction, true);
		npc->addAnimation("Spawn", std::make_shared<Animation>(spawnVector, 200));
		npc->addAnimation("North", std::make_shared<Animation>(northVector, 200));
		npc->addAnimation("South", std::make_shared<Animation>(southVector, 200));
		npc->addAnimation("East", std::make_shared<Animation>(eastVector, 200));
		npc->addAnimation("West", std::make_shared<Animation>(westVector, 200));
		npc->addAnimation("Inactive", std::make_shared<Animation>(inactiveVector, 200));
		npc->addAnimation("Projectile", std::make_shared<Animation>(projectileVector, 200));


	}
	else if (type == "Hero")
	{

		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroBack2"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroBack1"));
		northVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroBack3"));

		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroFront2"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroFront1"));
		southVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroFront3"));

		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroLeft2"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroLeft1"));
		westVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroLeft3"));

		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroRight2"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroRight1"));
		eastVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("EpicSpriteSheet"), "HeroRight3"));

		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "RedBall"));
		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "BlueBall"));
		projectileVector.push_back(std::make_shared<Texture>(this->getGameInstance()->getTextureAsset("ProjectileSheet"), "GreenBall"));

		npc = new NonPlayerCharacter(id, pos, std::make_shared<Animation>(southVector, 200), 1.0, 1.0, 3, direction, true);
		npc->addAnimation("North", std::make_shared<Animation>(northVector, 200));
		npc->addAnimation("South", std::make_shared<Animation>(southVector, 200));
		npc->addAnimation("East", std::make_shared<Animation>(eastVector, 200));
		npc->addAnimation("West", std::make_shared<Animation>(westVector, 200));
		npc->addAnimation("Projectile", std::make_shared<Animation>(projectileVector, 200));
	}

	return npc;

}

void	ObjectFactory::createPlayer(Map* map, Orientation direction, Position pos)
{
	std::string playerName = "Hero" + std::to_string(this->counter++);
	NonPlayerCharacter*	player = this->createNonPlayerCharacter("Hero", playerName, direction, pos);
	if (player != nullptr)
	{
		map->addObject(player);
		map->setPlayerCharacter(player);

		std::string out = "A player character \"" + playerName + "\" was added to the map";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
	}
}

void	ObjectFactory::createGhost(Map* map, Orientation direction, Position pos)
{
	std::string ghostName = "Ghost" + std::to_string(this->counter++);
	NonPlayerCharacter*	npc = this->createNonPlayerCharacter("Ghost", ghostName, direction, pos);
	if (npc != nullptr)
	{
		npc->setAI(new DefaultAI(npc, map));
		map->addObject(npc);

		std::string out = "A ghost NPC \"" + ghostName + "\" was added to the map";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
	}
}

void	ObjectFactory::createEvolvedGhost(Map* map, Orientation direction, Position pos)
{
	std::string ghostName = "Evolved" + std::to_string(this->counter++);
	NonPlayerCharacter*	npc = this->createNonPlayerCharacter("Evolved", ghostName, direction, pos);
	if (npc != nullptr)
	{
		npc->setAI(new DefaultAI(npc, map));
		map->addObject(npc);

		std::string out = "An evolved ghost NPC \"" + ghostName + "\" was added to the map";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
	}
}

void	ObjectFactory::createWitch(Map* map, Orientation direction, Position pos)
{
	std::string wicthName = "Witch" + std::to_string(this->counter++);
	NonPlayerCharacter*	npc = this->createNonPlayerCharacter("Witch", wicthName, direction, pos);
	if (npc != nullptr)
	{
		npc->setAI(new WitchAI(npc, map));
		map->addObject(npc);

		std::string out = "A witch NPC \"" + wicthName + "\" was added to the map";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
	}
}