#include "DefaultAI.h"

DefaultAI::DefaultAI() : AI()
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
}

DefaultAI::DefaultAI(NonPlayerCharacter* npc, Map* map) : AI(npc, map)
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
}

void	DefaultAI::doNext()
{
	NonPlayerCharacter* npc = AI::getSourceNPC();
	Map*				map = AI::getMap();

	//	Run if there is no active action or active action is completed
	if (npc != nullptr && map != nullptr && 
		(map->getPlayerCharacter() == nullptr || (map->getPlayerCharacter() != nullptr && map->getPlayerCharacter()->getId() != npc->getId())) &&
		(npc->getAction() == nullptr || (npc->getAction() != nullptr && npc->getAction()->isCompleted() == true)))
	{
		std::string out = "Object " + npc->getId() + " has launched a Move AI command";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
		this->move();
	}
	else
	{
		std::string out2 = "The queue already contains actions, doing nothing...";
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out2.c_str());
	}

}

void	DefaultAI::move()
{
	NonPlayerCharacter* npc = AI::getSourceNPC();
	Map*				map = AI::getMap();

	if (npc != nullptr && map != nullptr)
	{

		const Position currentPosition = npc->getCurrentPosition();
		const Position maxSize = map->getMapMaxSize();
		const int width = npc->getTexture()->asset->getWidth();
		const int height = npc->getTexture()->asset->getHeight();

		std::string moveDirection = "NONE";

		//int scopeWidth = 0;

		//	Check if last move was successful
		if (npc->getCurrentPosition().x == this->lastMovePosition.x && npc->getCurrentPosition().y == this->lastMovePosition.y)
			lastMoveSuccess = false;
		else
			lastMoveSuccess = true;



		//	Define rectangle to search within
		Position	positionA = { 0, 0 };
		Position	positionB = { 0, 0 };

		switch (npc->getOrientation())
		{
		case NORTH:
			positionA = { currentPosition.x, 0 };
			positionB = { currentPosition.x + width - 1, currentPosition.y };
			moveDirection = "NORTH";
			break;
		case SOUTH:
			positionA = { currentPosition.x, currentPosition.y };
			positionB = { currentPosition.x + width - 1, maxSize.y };
			moveDirection = "SOUTH";
			break;
		case WEST:
			positionA = { 0, currentPosition.y };
			positionB = { currentPosition.x, currentPosition.y + height - 1 };
			moveDirection = "WEST";
			break;
		case EAST:
			positionA = { currentPosition.x, currentPosition.y };
			positionB = { maxSize.x, currentPosition.y + height - 1 };
			moveDirection = "EAST";
			break;
		default:
			break;
		}

		bool playerFound = false;
		std::vector<Object*> objectList = map->getObject(positionA, positionB);
		if (objectList.size() > 0)
		{
			for (auto object : objectList)
			{
				if (object != nullptr && object->getId() != npc->getId())
				{
					std::string out2 = "Object " + object->getId() + " is within search area";
					SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out2.c_str());
				}
				if (map->getPlayerCharacter() != nullptr && object->getId() == map->getPlayerCharacter()->getId())
				{
					playerFound = true;
					break;
				}
			}
		}

		if (playerFound)
		{
			std::string out = "Player was found!";
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
			Position playerPosition = map->getPlayerCharacter()->getCurrentPosition();

			//If player is within a third of the map range
			if ((std::abs(playerPosition.x - currentPosition.x) < map->getMapMaxSize().x / 3) ||
				(std::abs(playerPosition.y - currentPosition.y) < map->getMapMaxSize().y / 3))
			{
				//	Can we see the player?
				//	(This one is slow as hell)

				Position relativeMovePosition = { -(currentPosition.x - playerPosition.x), -(currentPosition.y - playerPosition.y) };

				std::string out3 = "Game will crash now";
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out3.c_str());
				Position maxTravelRange = map->tryMove(npc, relativeMovePosition);
				
				std::string out4 = "Calculated Travel Range is " + std::to_string(maxTravelRange.x) + ", " + std::to_string(maxTravelRange.y) + ".";
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out4.c_str());

				//	Select an area 1 px larger than the npc and see if we are touching the player
				Position areaSearchA = { maxTravelRange.x - 1, maxTravelRange.y - 1 };
				Position areaSearchB = { maxTravelRange.x + width, maxTravelRange.y + height };

				std::string outa = "Searching area: " + std::to_string(areaSearchA.x) + ", " + std::to_string(areaSearchA.y) + " to " + std::to_string(areaSearchB.x) + ", " + std::to_string(areaSearchB.y) + "for Player ( " + std::to_string(playerPosition.x) + ", " + std::to_string(playerPosition.y) + ").";
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, outa.c_str());

				//	See if player is within reach
				bool playerWithinSight = false;
				std::vector<Object*> nearbyObjects = map->getObject(areaSearchA, areaSearchB);
				for (auto object : nearbyObjects)
				{
					if (map->getPlayerCharacter() != nullptr && object->getId() == map->getPlayerCharacter()->getId())
					{
						std::string outb = "Player found within search area!";
						SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, outb.c_str());
						playerWithinSight = true;
						break;
					}
				}

				if (playerWithinSight)
				{
					//	We have a clear sight of the player from within a third of the map
					std::string out5 = "Adding move action";
					SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, out5.c_str());
					npc->addAction(new MoveAction(npc, map, moveDirection, 2));
				}

			}
		}
	}
}