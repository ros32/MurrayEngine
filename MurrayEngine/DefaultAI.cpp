#include "DefaultAI.h"

DefaultAI::DefaultAI() : AI()
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
	this->playerRecentlySeen = false;
}

DefaultAI::DefaultAI(NonPlayerCharacter* npc, Map* map) : AI(npc, map)
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
	this->playerRecentlySeen = false;
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
	std::srand(std::time(NULL));

	if (npc != nullptr && map != nullptr)
	{

		const Position currentPosition = npc->getCurrentPosition();
		const Position maxSize = map->getMapMaxSize();
		const int width = npc->getTexture()->asset->getWidth();
		const int height = npc->getTexture()->asset->getHeight();
		Orientation currentDirection = npc->getOrientation();

		//int scopeWidth = 0;

		//	Check if last move was successful
		if (npc->getCurrentPosition().x == this->lastMovePosition.x && npc->getCurrentPosition().y == this->lastMovePosition.y)
			lastMoveSuccess = false;
		else
			lastMoveSuccess = true;


		//	Did we just see the player in this direction and did we manage to go this way, or does the player
		//	exist in this direction?
		//	(bool && bool) is faster than findPlayer()
		if ((this->playerRecentlySeen && this->lastMoveSuccess) || this->findPlayer(currentDirection))
		{
			//	Did we just see the player, or can we see the player now?
			if (this->playerRecentlySeen || this->canSeePlayer())
			{
				//	If we did not see the player before, we can do now.
				if (!this->playerRecentlySeen)
					this->playerRecentlySeen = true;

				//	Add move action for 2 turns
				npc->addAction(new MoveAction(npc, map, currentDirection, 2));

				//	Set current position as last move position
				this->lastMovePosition = npc->getCurrentPosition();
			}

		}
		//	If player was not seen but last move was successful, evaluate if there are different paths, but never go backwards
		else if (!this->playerRecentlySeen && this->lastMoveSuccess)
		{
			std::vector<Orientation> validDirections = this->getValidDirections();
			std::vector<Orientation> filteredDirections;
			for (Orientation direction : validDirections)
			{
				if (direction != currentDirection && direction != this->getOppositeDirection(currentDirection))
					filteredDirections.push_back(direction);
			}

			bool actionTaken = false;

			if (filteredDirections.size() > 0 && (std::rand() % 100 > 67))
			{
				bool playerSeen = false;
				
				for (Orientation direction : filteredDirections)
				{
					playerSeen = this->findPlayer(direction);
					if (playerSeen && this->canSeePlayer())
					{
						npc->addAction(new MoveAction(npc, map, direction, 2));
						this->playerRecentlySeen = true;
						this->lastMovePosition = currentPosition;
						actionTaken = true;
						break;
					}
					else if (playerSeen && std::rand() % 100 > 50)
					{
						npc->addAction(new MoveAction(npc, map, direction, 2));
						this->lastMovePosition = currentPosition;
						actionTaken = true;
						break;
					}
					else if (std::rand() % 100 > 67)
					{
						npc->addAction(new MoveAction(npc, map, direction, 2));
						this->lastMovePosition = currentPosition;
						actionTaken = true;
						break;
					}
				}

			}

			if (!actionTaken);
			{
				npc->addAction(new MoveAction(npc, map, currentDirection, 2));
				this->lastMovePosition = currentPosition;
			}
		}
		//	If last move was not successful, evaluate different paths, but avoid going backwards unless you have to
		else if (!this->lastMoveSuccess)
		{
			//	We failed to move last time, if we cannot see the player its gone.
			if (!this->canSeePlayer())
				this->playerRecentlySeen = false;

			std::vector<Orientation> validDirections = this->getValidDirections();
			std::vector<Orientation> filteredDirections;

			for (Orientation direction : validDirections)
			{
				if (direction != this->getOppositeDirection(currentDirection))
					filteredDirections.push_back(direction);
			}

			//	If backwards was the only valid option, then add it to the filtered list
			if (filteredDirections.size() == 0 && validDirections.size() > 0)
				filteredDirections.push_back(validDirections[0]);

			if (filteredDirections.size() > 0)
			{
				npc->addAction(new MoveAction(npc, map, filteredDirections[std::rand() % filteredDirections.size()], 2));
				this->lastMovePosition = currentPosition;
			}




		}
	}
}

bool	DefaultAI::findPlayer(Orientation orientation)
{
	NonPlayerCharacter*		npc = this->getSourceNPC();
	Map*					map = this->getMap();

	if (npc == nullptr || map == nullptr)
		return false;

	//	Store current position of npc
	const Position currentPosition = npc->getCurrentPosition();

	//	Store maximum size of map
	const Position maxSize = map->getMapMaxSize();

	//	Store width and height of npc
	const int width = npc->getTexture()->asset->getWidth();
	const int height = npc->getTexture()->asset->getHeight();

	//	SEARCH FOR PLAYER
	//	------------------
	//	Define a rectangle between two points, one at the edge of the NPC
	//	and the other at the edge of the map. See if the player is within
	//	that rectangle

	//	Define rectangle to search within
	Position	positionA = { 0, 0 };
	Position	positionB = { 0, 0 };

	//	Store move direction as string
	std::string currentDirection = "NONE";

	//	Depending on NPC orientation, the rectangle will vary
	switch (orientation)
	{
	case NORTH:
		positionA = { currentPosition.x, 0 };
		positionB = { currentPosition.x + width - 1, currentPosition.y };
		currentDirection = "NORTH";
		break;
	case SOUTH:
		positionA = { currentPosition.x, currentPosition.y };
		positionB = { currentPosition.x + width - 1, maxSize.y };
		currentDirection = "SOUTH";
		break;
	case WEST:
		positionA = { 0, currentPosition.y };
		positionB = { currentPosition.x, currentPosition.y + height - 1 };
		currentDirection = "WEST";
		break;
	case EAST:
		positionA = { currentPosition.x, currentPosition.y };
		positionB = { maxSize.x, currentPosition.y + height - 1 };
		currentDirection = "EAST";
		break;
	default:
		positionA = { 0, 0 };
		positionB = { 0, 0 };
		currentDirection = "NONE";
		break;
	}

	//	(debug) Player was found message
	std::string playerFoundMsg = "Player was found in area (" + std::to_string(positionA.x) + ", " + std::to_string(positionA.x) + "; " + 
		std::to_string(positionB.x) + ", " + std::to_string(positionB.y) + "), when facing " + currentDirection;

	//	Have we found the player?
	bool playerFound = false;

	//	Get all objects within search area
	std::vector<Object*> objectList = map->getObject(positionA, positionB);
	if (objectList.size() > 0)
	{
		for (auto object : objectList)
		{
			if (map->getPlayerCharacter() != nullptr && object->getId() == map->getPlayerCharacter()->getId())
			{
				//	If player is found, break loop and return true
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, playerFoundMsg.c_str());
				playerFound = true;
				break;
			}
		}
	}

	return playerFound;
}

bool		DefaultAI::canSeePlayer()
{
	NonPlayerCharacter*		npc = this->getSourceNPC();
	Map*					map = this->getMap();

	if (npc == nullptr || map == nullptr)
		return false;

	const Position		currentPosition = npc->getCurrentPosition();
	const Position		playerPosition = map->getPlayerCharacter()->getCurrentPosition();

	//	Store width and height of npc
	const int width =	npc->getTexture()->asset->getWidth();
	const int height =	npc->getTexture()->asset->getHeight();

	//If player is within a third of the map range
	if ((std::abs(playerPosition.x - currentPosition.x) < map->getMapMaxSize().x / 3) ||
		(std::abs(playerPosition.y - currentPosition.y) < map->getMapMaxSize().y / 3))
	{
		Position relativeMovePosition = { -(currentPosition.x - playerPosition.x), -(currentPosition.y - playerPosition.y) };

		Position maxTravelRange = map->tryMove(npc, relativeMovePosition);

		//	Move NPC to target
		npc->setCurrentPosition(maxTravelRange);

		//	Select an area 1 px larger than the npc and see if we are touching the player
		Position areaSearchA = { maxTravelRange.x - 1, maxTravelRange.y - 1 };
		Position areaSearchB = { maxTravelRange.x + width, maxTravelRange.y + height };

		//	See if player is within reach
		bool playerWithinSight = false;
		std::vector<Object*> nearbyObjects = map->getObject(areaSearchA, areaSearchB);
		for (auto object : nearbyObjects)
		{
			if (map->getPlayerCharacter() != nullptr && object->getId() == map->getPlayerCharacter()->getId())
			{
				playerWithinSight = true;
				break;
			}
		}

		//	Move back NPC to original position
		npc->setCurrentPosition(currentPosition);
	}
}

std::vector<Orientation>	DefaultAI::getValidDirections()
{
	NonPlayerCharacter*		npc = this->getSourceNPC();
	Map*					map = this->getMap();

	if (npc == nullptr || map == nullptr)
		return std::vector<Orientation>();

	const Position		currentPosition = npc->getCurrentPosition();
	const Position		playerPosition = map->getPlayerCharacter()->getCurrentPosition();
	const Orientation	currentDirection = npc->getOrientation();

	//	Store width and height of npc
	const int width = npc->getTexture()->asset->getWidth();
	const int height = npc->getTexture()->asset->getHeight();

	std::vector<Orientation> directions;
	std::vector<Position> moveTargets;

	if (currentDirection != NORTH)
	{
		directions.push_back(NORTH);
		moveTargets.push_back({ 0, 0 - height });
	}
	if (currentDirection != SOUTH)
	{
		directions.push_back(SOUTH);
		moveTargets.push_back({ 0, 0 + height });
	}
	if (currentDirection != EAST)
	{
		directions.push_back(EAST);
		moveTargets.push_back({ 0 + width, 0 });
	}
	if (currentDirection != WEST)
	{
		directions.push_back(WEST);
		moveTargets.push_back({ 0 - width, 0 });
	}

	std::vector<Orientation> validDirections;

	for (int i = 0; i < directions.size(); i++)
	{
		Position	testedPosition = map->tryMove(npc, moveTargets[i]);
		if (testedPosition.x == (moveTargets[i].x + currentPosition.x) && testedPosition.y == (moveTargets[i].y + currentPosition.y))
			validDirections.push_back(directions[i]);
	}

	return validDirections;

}

Orientation		DefaultAI::getOppositeDirection(Orientation direction)
{
	switch (direction)
	{
	case NORTH:
		return SOUTH;
	case SOUTH:
		return NORTH;
	case EAST:
		return WEST;
	case WEST:
		return EAST;
	case NONE:
	default:
		return NONE;
	}
}