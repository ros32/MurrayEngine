#include "DefaultAI.h"

DefaultAI::DefaultAI() : AI()
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
	this->playerRecentlySeen = false;
}

DefaultAI::DefaultAI(Object* npc, Map* map) : AI(npc, map)
{
	this->lastMovePosition = { 0, 0 };
	this->lastMoveSuccess = true;
	this->playerRecentlySeen = false;
}

DefaultAI::~DefaultAI()
{

}

void	DefaultAI::doNext()
{
	Object*				npc = AI::getSourceNPC();
	Map*				map = AI::getMap();

	//	Run if there is no active action or active action is completed
	if (npc != nullptr && map != nullptr && 
		(map->getPlayerCharacter() == nullptr || (map->getPlayerCharacter() != nullptr && map->getPlayerCharacter()->getId() != npc->getId())) &&
		(npc->getAction() == nullptr || (npc->getAction() != nullptr && npc->getAction()->isCompleted() == true)))
	{
		this->move();
	}


}

void	DefaultAI::move()
{
	Object*				npc = AI::getSourceNPC();
	Map*				map = AI::getMap();
	std::srand(std::time(NULL));

	if (npc != nullptr && map != nullptr)
	{

		const Position currentPosition = npc->getCurrentPosition();
		const Position maxSize = map->getMapMaxSize();
		const int width = npc->getTexture()->asset->getWidth();
		const int height = npc->getTexture()->asset->getHeight();
		Orientation currentDirection = npc->getOrientation();

		int moveTimes = 2;

		//int scopeWidth = 0;

		//	Check if last move was successful
		if (npc->getCurrentPosition().x == this->lastMovePosition.x && npc->getCurrentPosition().y == this->lastMovePosition.y)
			lastMoveSuccess = false;
		else
			lastMoveSuccess = true;

		//	This is a default implementation of a "dumb" ai that will wander aimlessly around the map in a seemingly random fashion.
		//	This AI follows these principles:
		//	1:	If last move was successful, repeat
		//	2:	If last move was unsuccessful, evaluate new direction except backwards
		//	3:	If last move was unsuccessful and only valid direction is backwards, go backwards

		if (lastMoveSuccess)
		{
			npc->addAction(new MoveAction(npc, map, currentDirection, moveTimes));
			this->lastMovePosition = currentPosition;
		}
		else
		{
			std::vector<Orientation> directions = this->getValidDirections();
			std::vector<Orientation> filteredDirections;
			for (auto direction : directions)
			{
				if (direction != currentDirection && direction != this->getOppositeDirection(currentDirection))
					filteredDirections.push_back(direction);
			}

			if (filteredDirections.size() == 0)
				filteredDirections.push_back(this->getOppositeDirection(currentDirection));

			int randomChance = std::rand() % filteredDirections.size();

			npc->addAction(new MoveAction(npc, map, filteredDirections[randomChance], moveTimes));
			this->lastMovePosition = currentPosition;
		}

	}
	
}

bool	DefaultAI::findPlayer(Orientation orientation)
{
	Object*		npc = this->getSourceNPC();
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
	Object*		npc = this->getSourceNPC();
	Map*					map = this->getMap();

	if (npc == nullptr || map == nullptr)
		return false;

	const Position		currentPosition = npc->getCurrentPosition();
	const Position		playerPosition = map->getPlayerCharacter()->getCurrentPosition();

	//	Store width and height of npc
	const int width =	npc->getTexture()->asset->getWidth();
	const int height =	npc->getTexture()->asset->getHeight();

	//If player is within three times the npcs size
	if ((std::abs(playerPosition.x - currentPosition.x) < width * 3) ||
		(std::abs(playerPosition.y - currentPosition.y) < height * 3))
	{
		Position relativeMovePosition = { -(currentPosition.x - playerPosition.x), -(currentPosition.y - playerPosition.y) };

		int moveAxis = (std::abs(relativeMovePosition.x) > std::abs(relativeMovePosition.y)) ? width : height;

		Position maxTravelRange = map->tryMove(npc, relativeMovePosition, true);

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
	Object*		npc = this->getSourceNPC();
	Map*					map = this->getMap();

	if (npc == nullptr || map == nullptr)
		return std::vector<Orientation>();

	std::vector<Orientation> directions;

	directions.push_back(NORTH);
	directions.push_back(SOUTH);
	directions.push_back(EAST);
	directions.push_back(WEST);

	std::vector<Orientation> validDirections;

	for (int i = 0; i < directions.size(); i++)
	{
		if (map->canMove(npc, directions[i]))
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