#define _CRTDBG_MAP_ALLOC
#include "DamageAction.h"
/*
DamageAction::DamageAction(GameInstance* instance, Object* source, std::vector<Object*> targets) 
{	
	this->instance = instance;
	this->source = source;
	this->targets = targets;
}
*/

DamageAction::DamageAction(Object* source, Map* map)
{
	this->source = source;
	this->map = map;
}

DamageAction::~DamageAction()
{

}

void DamageAction::execute()
{
	Orientation orientation;
	orientation = source->getOrientation();

	std::shared_ptr<Animation> animation;

	Position startPosition;
	switch (orientation){
	case NORTH:
		startPosition = { source->getCurrentPosition().x, source->getCurrentPosition().y - source->getTexture()->asset->getWidth() };
		break;
	case SOUTH:
		startPosition = { source->getCurrentPosition().x, source->getCurrentPosition().y + source->getTexture()->asset->getWidth() };
		break;
	case WEST:
		startPosition = { source->getCurrentPosition().x - source->getTexture()->asset->getHeight(), source->getCurrentPosition().y };
		break;
	case EAST:
		startPosition = { source->getCurrentPosition().x + source->getTexture()->asset->getHeight(), source->getCurrentPosition().y };
		break;
	}

		animation = source->getAnimation("Projectile");

}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source, this->map);
}




