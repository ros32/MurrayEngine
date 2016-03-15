#include "DamageAction.h"

int		DamageAction::counter = 0;

DamageAction::DamageAction(Object* source, Map* map)
{
	this->source = source;
	this->map = map;
	this->counter;
	
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
		std::string id = ("Projectile" + std::to_string(counter++));

		NonPlayerCharacter* pr = new NonPlayerCharacter(id, startPosition, animation, 0.0, 0.0, 15, orientation, true );

		pr->setTargetPosition(targetPosition);
		pr->setCollisionAction(new ExtendedCollisionAction(map, pr));
		pr->addAction(new MoveAction(pr, map, orientation, 50));
		this->map->addObject(pr);
		

}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source, this->map);
}




