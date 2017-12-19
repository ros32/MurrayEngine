#include "DamageAction.h"

int		DamageAction::counter = 0;

DamageAction::DamageAction(const std::string source, GameInstance* gameInstance)
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
		auto sourceObject = gameInstance->getMap()->getObjectById(source);
		if (sourceObject != nullptr)
		{
			auto map = gameInstance->getMap();

			const auto orientation = sourceObject->getOrientation();

			Position startPosition = {};
			Position targetPosition = {};
			switch (orientation){
			case NORTH:
				startPosition = { sourceObject->getCurrentPosition().x, sourceObject->getCurrentPosition().y - sourceObject->getTexture()->asset->getHeight() };
				targetPosition = { 0, -2 };
				break;
			case SOUTH:
				startPosition = { sourceObject->getCurrentPosition().x, sourceObject->getCurrentPosition().y + sourceObject->getTexture()->asset->getHeight() };
				targetPosition = { 0, 2 };
				break;
			case WEST:
				startPosition = { sourceObject->getCurrentPosition().x - sourceObject->getTexture()->asset->getWidth(), sourceObject->getCurrentPosition().y };
				targetPosition = { -2, 0};
				break;
			case EAST:
				startPosition = { sourceObject->getCurrentPosition().x + sourceObject->getTexture()->asset->getWidth(), sourceObject->getCurrentPosition().y };
				targetPosition = { 2, 0 };
				break;
			default: ;
			}

			const auto animation = sourceObject->getAnimation("Projectile");
			const auto id = ("Projectile" + std::to_string(counter++));

			auto pr = new NonPlayerCharacter(id, startPosition, animation, 0.0, 0.0, 15, orientation, true );

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




