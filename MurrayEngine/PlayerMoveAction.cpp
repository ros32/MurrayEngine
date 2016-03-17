#include "PlayerMoveAction.h"

PlayerMoveAction::PlayerMoveAction(std::string source, GameInstance* gameInstance, Orientation direction){
	this->source = source;
	this->gameInstance = gameInstance;
	this->direction = direction;
	this->repeat = -1;
	this->currentRepeat = 1;
}

PlayerMoveAction::PlayerMoveAction(std::string source, GameInstance* gameInstance, Orientation direction, int repeat)
{
	this->source = source;
	this->gameInstance = gameInstance;
	this->direction = direction;
	this->repeat = repeat;
	this->currentRepeat = repeat;

}
PlayerMoveAction::~PlayerMoveAction(){

}
void PlayerMoveAction::execute()
{
	if (gameInstance != nullptr && gameInstance->getMap() != nullptr)
	{
		Object*		sourceObject = gameInstance->getMap()->getObjectById(source);
		if (sourceObject != nullptr)
		{
			std::string prStr = "Projectile";

			if (source.find(prStr) != std::string::npos){
				SDL_Log("projectile is moving!");
			}

			if (this->currentRepeat > 0 || repeat == -1)
			{

				switch (direction)
				{
				case NORTH:
					sourceObject->setTargetPosition(sourceObject->getTargetPosition().x, sourceObject->getTargetPosition().y - sourceObject->getCurrentSpeed());

					if (sourceObject->getOrientation() != NORTH)
						sourceObject->changeAnimation("North");

					sourceObject->setOrientation(NORTH);
					break;
				case SOUTH:
					sourceObject->setTargetPosition(sourceObject->getTargetPosition().x, sourceObject->getTargetPosition().y + sourceObject->getCurrentSpeed());

					if (sourceObject->getOrientation() != SOUTH)
						sourceObject->changeAnimation("South");

					sourceObject->setOrientation(SOUTH);
					break;
				case EAST:
					sourceObject->setTargetPosition(sourceObject->getTargetPosition().x + sourceObject->getCurrentSpeed(), sourceObject->getTargetPosition().y);

					if (sourceObject->getOrientation() != EAST)
						sourceObject->changeAnimation("East");

					sourceObject->setOrientation(EAST);
					break;
				case WEST:
					sourceObject->setTargetPosition(sourceObject->getTargetPosition().x - sourceObject->getCurrentSpeed(), sourceObject->getTargetPosition().y);
					if (sourceObject->getOrientation() != WEST)
						sourceObject->changeAnimation("West");

					sourceObject->setOrientation(WEST);
					break;
				case NONE:
				default:
					break;
				}

				if (this->repeat != -1)
					this->updateProgress((float)1 / (float)this->currentRepeat);
				currentRepeat--;
			}

			if (currentRepeat == 0)
				this->setProgress(1);

		}
	}

}

Action*	PlayerMoveAction::copy()
{
	return new PlayerMoveAction(this->source, this->gameInstance, this->direction);
}