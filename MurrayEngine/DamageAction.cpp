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
	Position targetPosition;
	switch (orientation){
	case NORTH:
		startPosition = { source->getCurrentPosition().x, source->getCurrentPosition().y - source->getTexture()->asset->getWidth() };
		targetPosition = { 0, -2 };
		break;
	case SOUTH:
		startPosition = { source->getCurrentPosition().x, source->getCurrentPosition().y + source->getTexture()->asset->getWidth() };
		targetPosition = {0, 2 };
		break;
	case WEST:
		startPosition = { source->getCurrentPosition().x - source->getTexture()->asset->getHeight(), source->getCurrentPosition().y };
		targetPosition = { -2, 0};
		break;
	case EAST:
		startPosition = { source->getCurrentPosition().x + source->getTexture()->asset->getHeight(), source->getCurrentPosition().y };
		targetPosition = { 2, 0 };
		break;
	}

		animation = source->getAnimation("Projectile");

		NonPlayerCharacter* pr  = new NonPlayerCharacter("Projectile", startPosition, animation, 1.0, 1.0, 15, orientation, true);
		pr->setTargetPosition(targetPosition);
		this->map->addObject(pr);
	
		pr->addAction(new MoveAction(pr, map, orientation, 50));

	
}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source, this->map);
}




