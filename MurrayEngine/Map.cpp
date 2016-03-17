#include "Map.h"

Map::Map(SDL_Window* window, SDL_Renderer* renderer)
{
	this->tileSize;
	this->camera = new Camera(window);
	this->tiles;
	this->objects;
	this->collisionMap;
	this->passableMap;
	this->tileGrid;
	this->gridSize = DEFAULT_GRID_SIZE;
	this->playerCharacter = nullptr;
	this->mapMaxSize = { 0, 0 };
	this->tileSize = 0;

}

Map::~Map()
{
	delete this->camera;

	std::map<Position, std::map<Position, Tile*> >::iterator it;
	for (it = this->tileGrid.begin(); it != this->tileGrid.end(); it++)
	{
		for (auto tile : it->second)
		{
			delete tile.second;
		}
	}

	this->tileGrid.clear();

	for (auto object : objects)
	{
		delete object;
	}

}


std::vector<Object*>	Map::getObject(Position pos)
{
	
	std::vector<Object*> tempVector;

	for (auto object : objects){

		int height = object->getTexture()->asset->getHeight();
		int width = object->getTexture()->asset->getWidth();

		int axLeft = object->getCurrentPosition().x;
		int ayTop = object->getCurrentPosition().y;
		int axRight = object->getCurrentPosition().x + width - 1;
		int ayBottom = object->getCurrentPosition().y + height - 1;

		if (pos.x >= axLeft && pos.x <= axRight)
		{
			if (pos.y >= ayTop && pos.y <= ayBottom)
			{
				tempVector.push_back(object);
			}
		}
	}

	return tempVector;
}

std::vector<Object*>	Map::getObject(Position posA, Position posB)
{
	std::vector < Object* >	tempVector;

	int posX = posA.x;
	int posY = posA.y;

	do
	{
		do
		{
			std::vector < Object* >	tempVector2 = this->getObject({ posX, posY });
			if (!tempVector2.empty())
			{
				for (auto object : tempVector2)
				{
					tempVector.push_back(object);
				}
			}
			posY++;
		} while (posY < posB.y);
		posX++;
	} while (posX < posB.x);

	return tempVector;
}

std::vector<Tile*>	Map::getTiles(Position posA, Position posB)
{
	std::map<Position, std::map<Position, Tile*> >::iterator it;

	std::vector<Tile*>					foundTiles;

	Position lower = { std::min(posA.x, posB.x), std::min(posA.y, posB.y) };
	Position upper = { std::max(posA.x, posB.x), std::max(posA.y, posB.y) };


	for (it = this->tileGrid.begin(); it != this->tileGrid.end(); it++)
	{
		Position lowerGrid = { it->first.x - this->gridSize, it->first.y - this->gridSize };
		if ((it->first.x >= lower.x && it->first.y >= lower.y && lowerGrid.x <= upper.x && lowerGrid.y <= upper.y))
		{
			std::map<Position, Tile*>::iterator itm;
			for (itm = it->second.begin(); itm != it->second.end(); itm++)
			{
				Position currentPosition = itm->first;
				int height = itm->second->getTexture()->asset->getHeight();
				int width = itm->second->getTexture()->asset->getWidth();
				if (upper.x >= currentPosition.x && lower.x < currentPosition.x + width && //	X coordinate is within x of the tile
					upper.y >= currentPosition.y && lower.y < currentPosition.y + height)	//	Y coordinate is within y of the tile
					foundTiles.push_back(itm->second);
			}
		}
	}

	return foundTiles;

}

Tile* Map::getTile(Position pos)
{
	std::map<Position, std::map<Position, Tile*> >::iterator it;

	for (it = this->tileGrid.begin(); it != this->tileGrid.end(); it++)
	{
		Position lowerPosition = { pos.x - this->gridSize, pos.y - this->gridSize };
		if (it->first < pos && it->first >= lowerPosition)
		{
			std::map<Position, Tile*>::iterator itm;
			for (itm = it->second.begin(); itm != it->second.end(); itm++)
			{
				Position currentPosition = itm->first;
				int height = itm->second->getTexture()->asset->getHeight();
				int width = itm->second->getTexture()->asset->getWidth();
				if (pos.x >= currentPosition.x && pos.x < currentPosition.x + height && //	X coordinate is within x of the tile
					pos.y >= currentPosition.y && pos.y < currentPosition.y + width)	//	Y coordinate is within y of the tile
					return itm->second;
			}
		}
	}

	return nullptr;
}
	
void Map::render()
{

	//	Render tiles

	Position	cameraPosition = this->camera->getPosition();
	Position	cameraMaxPosition = { this->camera->getPosition().x + this->camera->getWidth(), this->camera->getPosition().x + this->camera->getWidth() };
	for (auto object : this->getTiles(cameraPosition, cameraMaxPosition))
	{

		object->render(object->getCurrentPosition().x - this->camera->getPosition().x, object->getCurrentPosition().y - this->camera->getPosition().y);
	}

	//	Render objects
	for (auto object : this->objects)
	{
		//	TODO: Optimize this
		if ((object->getCurrentPosition().x >= (this->camera->getPosition().x - object->getTexture()->asset->getCellSize()) && object->getCurrentPosition().x <= (this->camera->getPosition().x + this->camera->getWidth() + object->getTexture()->asset->getCellSize())) &&
			(object->getCurrentPosition().y >= (this->camera->getPosition().y - object->getTexture()->asset->getCellSize()) && object->getCurrentPosition().y <= (this->camera->getPosition().y + this->camera->getHeight() + object->getTexture()->asset->getCellSize())))
		{
			//	Object is within camera view

			//	Render object with camera offset
			object->render(object->getCurrentPosition().x - this->camera->getPosition().x, object->getCurrentPosition().y - this->camera->getPosition().y);
		}
	}

}

void Map::setTiles(std::vector<Tile*> tiles)
{
		this->calculateMapMaxSize(tiles);
		this->createGrid(tiles);
}

void Map::setObjects(std::vector<Object*> objects)
{
		this->objects = objects;
}

void Map::addObject(Object* object)
{	
		objects.push_back(object);
}

void Map::removeObject(Object* object)
{
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void Map::move()

{
	//	Loop for all objects in vector
	for (int i = 0; i < objects.size() ; i++)
	{
		
		//	If object is to be moved
		if (objects[i] != nullptr && (objects[i]->getTargetPosition().x != 0 || objects[i]->getTargetPosition().y != 0))
		{

			//	Store objects current position (const)
			const Position currentPosition = objects[i]->getCurrentPosition();

			//	Store objects target position (const)
			const Position targetPosition = objects[i]->getTargetPosition();

			//	Store current position with target position applied
			Position finalPosition = { currentPosition.x + targetPosition.x, currentPosition.y + targetPosition.y };

			//	If final position is negative, return and do not move
			if (finalPosition.x < 0 || finalPosition.y < 0)
			{
				objects[i]->setTargetPosition({ 0, 0 });
				break;
			}
			
			if (i < objects.size()){
				objects[i]->setCurrentPosition(this->tryMove(objects[i], targetPosition, false));
			}
			if (i < objects.size()){
				objects[i]->setTargetPosition({ 0, 0 });
			}

		}
	}
}
	
Camera*	Map::getCamera()
{
	return this->camera;
}

Object*	Map::getPlayerCharacter()
{
	return this->playerCharacter;
}

void Map::setPlayerCharacter(Object* playerCharacter)
{
	this->playerCharacter = playerCharacter;
}

int	Map::getTileSize()
{
	return this->tileSize;
}

void Map::setTileSize(int tileSize)
{
	this->tileSize = tileSize;
}

void Map::calculateMapMaxSize(std::vector<Tile*> tiles)
{
	int maxX = 0;
	int maxY = 0;
	for (Tile* tile : tiles)
	{
		if (maxX < (tile->getTexture()->asset->getWidth() + tile->getCurrentPosition().x))
			maxX = (tile->getTexture()->asset->getWidth() + tile->getCurrentPosition().x);
		if (maxY < (tile->getTexture()->asset->getHeight() + tile->getCurrentPosition().y))
			maxY = (tile->getTexture()->asset->getHeight() + tile->getCurrentPosition().y);
	}
	this->mapMaxSize = { maxX, maxY };
}

void Map::doActionQueue()
{

	for (int i = 0; i < objects.size(); i++){
		if (objects[i] != nullptr){
			objects[i]->doAction();
		}
	}
}

void Map::generateMaps()
{
	Position maxSize = this->getMapMaxSize();
	int sizeX = this->getTileSize();
	int sizeY = this->getTileSize();
	this->collisionMap = std::vector<std::vector<bool>>(maxSize.x/sizeX);
	for (int i = 0; i < maxSize.x/sizeX; i++)
	{
		std::string out = "Processing line " + std::to_string(i);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
		this->collisionMap[i] = std::vector<bool>(maxSize.y/sizeY);
		for (int j = 0; j < maxSize.y/sizeY; j++)
		{
			this->collisionMap[i][j] = this->getTile({ i, j })->getIsCollidable();
		}
	}
}

bool Map::getCollision(Position posA, Position posB)
{
	Position maxSize = this->getMapMaxSize();
	int		tileSize = this->getTileSize();
	if (posA.x < 0 || posA.x > maxSize.x || posA.y < 0 || posA.y > maxSize.y || posB.x < 0 || posB.x > maxSize.x || posB.y < 0 || posB.y > maxSize.y)
		return true;
	if (posA.x == posB.x && posA.y == posB.y)
		return this->collisionMap[posA.x][posA.y];
	else
	{
		Position posX;
		Position posY;
		if (posB.x < posA.x)
		{
			posX = posB;
			posY = posA;
		}
		else
		{
			posX = posA;
			posY = posB;
}

		for (; posX.x < posY.x; posX.x++)
		{
			for (; posX.y < posY.y; posX.y++)
				if (this->collisionMap[posX.x / tileSize][posX.y / tileSize])
				{
					std::string out = "Found a collision in tile" + std::to_string(posX.x / tileSize) + ", " + std::to_string(posX.y / tileSize);
					SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
					return true;
				}
		}

		return false;
	}
}

Position	Map::tryMove(Object* object, Position targetPosition, bool onlyCheckCollision)
{


	//	Store current position from object
	const Position currentPosition = object->getCurrentPosition();

	//	If object has no collision, set current position to final position and return
	if (object->getIsCollidable())
	{

		//	Set collision bool to false
		bool collision = false;

		//	Check which axes to move
		const bool moveX = (targetPosition.x != 0);
		const bool moveY = (targetPosition.y != 0);

		//	Check if move is negative on axis
		const bool negX = (targetPosition.x < 0);
		const bool negY = (targetPosition.y < 0);

		

		//	Store object height and width
		const int height = object->getTexture()->asset->getHeight();
		const int width = object->getTexture()->asset->getWidth();

		int moveDistance = (onlyCheckCollision) ? 2 : 1;

		//	Store the iterators current position
		Position iterationPosition = currentPosition;

		//	Store numbers of iterations needed
		const int iterations = std::max(std::abs(targetPosition.x), std::abs(targetPosition.y));

		//	Process iterations
		for (int i = 0; i < iterations; i++)
		{
			//	Store last position where no collision was detected
			Position	lastGoodPosition = iterationPosition;

			//	Adjust x axis depending on positive or negative value
			if (moveX && ((!negX && i < targetPosition.x) || (negX && i > targetPosition.x)))
			{
				if (negX)
					iterationPosition = { iterationPosition.x - moveDistance, iterationPosition.y };
				else
					iterationPosition = { iterationPosition.x + moveDistance, iterationPosition.y };
			}

			//	Adjust y axis depending on positive or negative value
			if (moveY && ((!negY && i < targetPosition.y) || (negY && i > targetPosition.y)))
			{

				if (negY)
					iterationPosition = { iterationPosition.x, iterationPosition.y - moveDistance };
				else
					iterationPosition = { iterationPosition.x, iterationPosition.y + moveDistance };
			}

			object->setCurrentPosition(iterationPosition);

			//	Declare vector for tiles to be checked
			std::vector<Tile*>	tiles = this->getTiles(iterationPosition, { iterationPosition.x + width - 1, iterationPosition.y + height - 1 });

			//	Check tiles that touches objects corners for collision
			for (Object* tile : tiles)
			{
				if (tile == nullptr)
				{
					collision = true;
					break;
				}
				if (tile->getIsCollidable() && object->collidePixel(tile))
				{
					collision = true;
					break;
				}
			}

			//	If collision is found, set current position to last known good position and break
			if (collision)
			{
				object->setCurrentPosition(currentPosition);
				return lastGoodPosition;
			}
			else
			{
				//	Check all objects
				for (auto otherObject : this->objects)
				{
					//	If object is not null, not self and has collision and collides with pixel
					if (otherObject != nullptr && otherObject->getId() != object->getId() &&
						otherObject->getIsCollidable() && object->collidePixel(otherObject))
					{
						collision = true;
						break;
					}
				}

				//	If collision is found, set current position to last known good position and break
				if (collision)
				{
					object->setCurrentPosition(currentPosition);
					return lastGoodPosition;
				}
			}

		}

	}
	object->setCurrentPosition(currentPosition);
	return { currentPosition.x + targetPosition.x, currentPosition.y + targetPosition.y };

}

Position		Map::getMapMaxSize()
{
	return this->mapMaxSize;
}

Position				Map::tryMove(Object* object, Position targetPosition, bool relativePosition, int movement, int padding, bool multiAxis)
{
	//	Store current position
	const Position	currentPosition = object->getCurrentPosition();

	//	Store final position
	Position		finalPosition;

	//	If target position is a relative position, make it absolute
	if (relativePosition)
		finalPosition = { currentPosition.x + targetPosition.x, currentPosition.y + targetPosition.y };
	else
		finalPosition = targetPosition;

	//	Store width and height of object
	const int width = object->getTexture()->asset->getWidth();
	const int height = object->getTexture()->asset->getHeight();

	//	Determine if X and Y should be moved; if multiAxis is false, only move the largest of the two
	bool moveX = (((relativePosition && std::abs(targetPosition.x) > 0) || (!relativePosition && targetPosition.x != currentPosition.x) && multiAxis) || (std::abs(targetPosition.x) > std::abs(targetPosition.y) && !multiAxis));
	bool moveY = (((relativePosition && std::abs(targetPosition.y) > 0) || (!relativePosition && targetPosition.y != currentPosition.y) && multiAxis) || (std::abs(targetPosition.y) > std::abs(targetPosition.x) && !multiAxis));

	//	If both X and Y are to be moved but multiAxis is false, set Y to false
	moveY = (moveX && moveY && !multiAxis) ? false : moveY;


	//	If current posiiton is higher than final position, use negative values (we are going north/west)
	bool negX = (currentPosition.x > finalPosition.x);
	bool negY = (currentPosition.y > finalPosition.y);

	//	If movement is larger than width/height, set movement to width/height
	int movementX = (movement <= width) ? movement : width;
	int movementY = (movement <= height) ? movement : height;

	//	If movement should be negative, set movement to negative
	movementX = (negX) ? -movementX : movementX;
	movementY = (negY) ? -movementY : movementY;

	//	Store last position that worked
	Position lastGoodPosition = currentPosition;

	//	Store found collitions on each axis
	bool collisionFoundX = false;
	bool collisionFoundY = false;

	//	Set positionA to current position, and positionB to the lower right corner of the object
	Position positionA = currentPosition;
	Position positionB = { currentPosition.x + width -1, currentPosition.y + height -1 };

	int iteration = 1;
	//	Enter the loop
	while (true)
	{
		
		//	If the difference between finalPosition and positionA is smaller than the movement
		//	distance, set the movement distance to the difference between the two.
		if (finalPosition.x - positionA.x < movementX)
			movementX = finalPosition.x - positionA.x;

		if (finalPosition.y - positionA.y < movementY)
			movementY = finalPosition.y - positionA.y;

		//	If axis is to be moved and no collision has been detected, move axis the distance of movement
		positionA.x = (moveX && !collisionFoundX) ? positionA.x + movementX : positionA.x;
		positionA.y = (moveY && !collisionFoundY) ? positionA.y + movementY : positionA.y;

		positionB.x = (moveX && !collisionFoundX) ? positionB.x + movementX : positionB.x;
		positionB.y = (moveY && !collisionFoundY) ? positionB.y + movementY : positionB.y;

		std::vector<Tile*> tiles = this->getTiles(positionA, positionB);

		object->setCurrentPosition(positionA);

		for (Tile* tile : tiles)
		{
			if (tile->getIsCollidable() && object->collidePixel(tile))
			{
				collisionFoundX = true;
				collisionFoundY = true;
				break;
			}
		}

		if ((collisionFoundX || collisionFoundY) ||(moveX && positionA.x == finalPosition.x) || (moveY && positionA.y == finalPosition.y))
		{
			break;
		}
		else if ((moveX && positionA.x > finalPosition.x) || (moveY && positionA.y > finalPosition.y))
			break;

		lastGoodPosition = positionA;
		std::string out = "This is iteration " + std::to_string(iteration++);
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, out.c_str());
	}

	object->setCurrentPosition(currentPosition);

	return lastGoodPosition;
}

void			Map::createGrid(std::vector<Tile*> tiles)
{
	if (tiles.size() > 0)
	{
		int gridSizeX = this->gridSize;
		int gridSizeY = this->gridSize;

		do
		{
			do
			{
				Position currentPosition = { gridSizeX, gridSizeY };
				std::map<Position, Tile*>	currentMap;

				

				for (auto tile : tiles)
				{
					if (tile->getCurrentPosition().x >= gridSizeX - this->gridSize && tile->getCurrentPosition().x < gridSizeX &&
						tile->getCurrentPosition().y >= gridSizeY - this->gridSize && tile->getCurrentPosition().y < gridSizeY)
						currentMap.insert(std::make_pair(tile->getCurrentPosition(), tile));
				}

				this->tileGrid.insert(std::make_pair(currentPosition, currentMap));
				gridSizeX += this->gridSize;
			} while (gridSizeX < this->mapMaxSize.x + this->gridSize);

			gridSizeX = this->gridSize;
			gridSizeY += this->gridSize;

		} while (gridSizeY < this->mapMaxSize.y + this->gridSize);
	}
}

bool	Map::canMove(Object* object, Orientation direction)
{
	Position currentPosition = object->getCurrentPosition();

	const int height = object->getTexture()->asset->getHeight();
	const int width = object->getTexture()->asset->getWidth();

	Position targetPosition = currentPosition;

	switch (direction)
	{
	case NORTH:
		targetPosition = { currentPosition.x, currentPosition.y -height };
		break;
	case SOUTH:
		targetPosition = { currentPosition.x, currentPosition.y + height};
		break;
	case EAST:
		targetPosition = { currentPosition.x + width, currentPosition.y };
		break;
	case WEST:
		targetPosition = { currentPosition.x - width, currentPosition.y  };
		break;
	}

	std::vector<Tile*>	tiles = this->getTiles(targetPosition, { targetPosition.x + width - 1, targetPosition.y + height - 1 });

	if (tiles.size() == 0)
		return false;
	else
	{
		object->setCurrentPosition(targetPosition);
		for (auto tile : tiles)
		{
			if (tile->getIsCollidable() && object->collidePixel(tile))
			{
				object->setCurrentPosition(currentPosition);
				return false;
			}
		}
	}

	object->setCurrentPosition(currentPosition);
	return true;
}

Object*			Map::getObjectById(std::string id)
{
	for (auto object : this->objects)
	{
		if (object->getId() == id)
			return object;
	}

	return nullptr;
}