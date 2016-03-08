#include "WitchAI.h"

WitchAI::WitchAI() : AI() {

}

WitchAI::WitchAI(NonPlayerCharacter* npc, Map* map) : AI(npc, map){

}
WitchAI::~WitchAI(){

}

void WitchAI::doNext(){

	NonPlayerCharacter* npc =	AI::getSourceNPC();
	Map* map =					AI::getMap();

	if (npc != nullptr && map != nullptr && map->getPlayerCharacter() != nullptr &&
		(npc->getAction() == nullptr || (npc->getAction() != nullptr && npc->getAction()->isCompleted() == true)))
	{
		npc->changeAnimation("Inactive");
	}

	playerPosition = map->getPlayerCharacter()->getCurrentPosition();

	if (playerPosition.x > 370 && playerPosition.x < 640)
	{
		if (playerPosition.y > 210 && playerPosition.y < 554)
		{
			lookForPlayer();
		}
	}

}

void WitchAI::lookForPlayer(){

	NonPlayerCharacter* npc = AI::getSourceNPC();
	Map* map = AI::getMap();

	bossPosition = npc->getCurrentPosition();
	bossHeight = npc->getTexture()->asset->getHeight();
	bossWidth = npc->getTexture()->asset->getWidth();

	playerHeight = map->getPlayerCharacter()->getTexture()->asset->getHeight();
	playerWidth = map->getPlayerCharacter()->getTexture()->asset->getWidth();

	if ((playerPosition.x + playerWidth > bossPosition.x) && playerPosition.x < bossPosition.x + bossWidth){
		if (playerPosition.y > bossPosition.y){
			
			npc->setOrientation(SOUTH);
			npc->changeAnimation("South");
			if (!npc->actionExists())
				npc->addAction(new DamageAction(npc, map));
			
			
		}
		else{
			npc->setOrientation(NORTH);
			npc->changeAnimation("North");
			if (!npc->actionExists())
				npc->addAction(new DamageAction(npc, map));
			

		}

	}
	else if ((playerPosition.y + playerHeight > bossPosition.y && playerPosition.y < bossPosition.y + bossHeight)){
		if (playerPosition.x < bossPosition.x){
			npc->setOrientation(WEST);
			npc->changeAnimation("West");
			if (!npc->actionExists())
				npc->addAction(new DamageAction(npc, map));
			

		}
		else{
			npc->setOrientation(EAST);
			npc->changeAnimation("East");
			if (!npc->actionExists())
				npc->addAction(new DamageAction(npc, map));
			

		}
	}


}