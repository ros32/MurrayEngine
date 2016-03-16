#include "DamageAction.h"

int		DamageAction::counter = 0;

DamageAction::DamageAction(std::string source, GameInstance* gameInstance)
{
	this->source = source;
	this->gameInstance = gameInstance;
	this->counter;
	
}

DamageAction::~DamageAction()
{

}

void DamageAction::execute()
{
	if (gameInstance != nullptr && gameInstance->getMap() != nullptr)
	{
		Object* sourceObject = gameInstance->getMap()->getObjectById(source);
		if (sourceObject != nullptr)
		{
			Map* map = gameInstance->getMap();

			Orientation orientation;
			orientation = sourceObject->getOrientation();

			std::shared_ptr<Animation> animation;

			Position startPosition;
			Position targetPosition;
			switch (orientation){
			case NORTH:
				startPosition = { sourceObject->getCurrentPosition().x, sourceObject->getCurrentPosition().y - sourceObject->getTexture()->asset->getWidth() };
				targetPosition = { 0, -2 };
				break;
			case SOUTH:
				startPosition = { sourceObject->getCurrentPosition().x, sourceObject->getCurrentPosition().y + sourceObject->getTexture()->asset->getWidth() };
				targetPosition = {0, 2 };
				break;
			case WEST:
				startPosition = { sourceObject->getCurrentPosition().x - sourceObject->getTexture()->asset->getHeight(), sourceObject->getCurrentPosition().y };
				targetPosition = { -2, 0};
				break;
			case EAST:
				startPosition = { sourceObject->getCurrentPosition().x + sourceObject->getTexture()->asset->getHeight(), sourceObject->getCurrentPosition().y };
				targetPosition = { 2, 0 };
				break;
			}

				animation = sourceObject->getAnimation("Projectile");
				std::string id = ("Projectile" + std::to_string(counter++));

				NonPlayerCharacter* pr = new NonPlayerCharacter(id, startPosition, animation, 0.0, 0.0, 15, orientation, true );

				pr->setTargetPosition(targetPosition);
				pr->setCollisionAction(new ExtendedCollisionAction(map, pr));
				pr->addAction(new MoveAction(pr, map, orientation, 50));
				map->addObject(pr);
		}
	}
}

Action*	DamageAction::copy()
{
	return new DamageAction(this->source, this->gameInstance);
}




