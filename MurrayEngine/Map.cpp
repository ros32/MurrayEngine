#include "Map.h"


Map::Map()
{
	this->tileSize;
	this->camera = new Camera();
	this->tiles;
	this->objects;
	this->collisionMap;
	this->passableMap;

}

Map::Map(SDL_Window* window, SDL_Renderer* renderer)
{
	this->tileSize;
	this->camera = new Camera(window);
	this->tiles;
	this->objects;
	this->collisionMap;
	this->passableMap;
	
}

Map::~Map()
{
	delete this->camera;
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

Tile* Map::getTile(Position pos)
{
	//	std::vector <std::vector<Tile>>::iterator row;
	//	std::vector<Tile>::iterator column;

	for (auto tile : this->tiles)
	{
		Position currentPosition = tile->getCurrentPosition();
		int height = tile->getTexture()->asset->getHeight();
		int width = tile->getTexture()->asset->getWidth();

		if (pos.x >= currentPosition.x && pos.x < currentPosition.x + height && //	X coordinate is within x of the tile
			pos.y >= currentPosition.y && pos.y < currentPosition.y + height)	//	Y coordinate is within y of the tile
			return tile;

	}

	return nullptr;
}
	
void Map::render()
{

	//	Render tiles
	for (auto object : this->tiles)
	{
		if ((object->getCurrentPosition().x >= (this->camera->getPosition().x - object->getTexture()->asset->getCellSize()) && object->getCurrentPosition().x <= (this->camera->getPosition().x + this->camera->getWidth() + object->getTexture()->asset->getCellSize())) &&
			(object->getCurrentPosition().y >= (this->camera->getPosition().y - object->getTexture()->asset->getCellSize()) && object->getCurrentPosition().y <= (this->camera->getPosition().y + this->camera->getHeight() + object->getTexture()->asset->getCellSize())))
		{
			//	Object is within camera view

			//	Render object with camera offset
			object->render(object->getCurrentPosition().x - this->camera->getPosition().x, object->getCurrentPosition().y - this->camera->getPosition().y);
		}
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
		this->tiles = tiles;
		//this->generateMaps();
		this->calculateMapMaxSize();
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

//	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
	/*
	for (int i = objects.size()-1; i >= 0; i--){
		if (objects[i] == object)
			objects.erase(objects.begin()+1);

	}*/

}

void Map::move()

{
	//	Loop for all objects in vector
	for (auto object : this->objects)
	{
		//	If object is to be moved
		if (object != nullptr && (object->getTargetPosition().x != 0 || object->getTargetPosition().y != 0))
		{
			//	Store objects current position (const)
			const Position currentPosition = object->getCurrentPosition();

			//	Store objects target position (const)
			const Position targetPosition = object->getTargetPosition();

			//	Store current position with target position applied
			Position finalPosition = { currentPosition.x + targetPosition.x, currentPosition.y + targetPosition.y };

			//	If final position is negative, return and do not move
			if (finalPosition.x < 0 || finalPosition.y < 0)
			{
				object->setTargetPosition({ 0, 0 });
				break;
			}
			
			object->setCurrentPosition(this->tryMove(object, targetPosition));
			object->setTargetPosition({ 0, 0 });
		}
	}
}
	
Camera*		Map::getCamera()
{
	return this->camera;
}

Object*	Map::getPlayerCharacter()
{
	return this->playerCharacter;
}

void			Map::setPlayerCharacter(Object* playerCharacter)
{
	this->playerCharacter = playerCharacter;
}

int				Map::getTileSize()
{
	return this->tileSize;
}

void			Map::setTileSize(int tileSize)
{
	this->tileSize = tileSize;
}

void		Map::calculateMapMaxSize()
{
	int maxX = 0;
	int maxY = 0;
	for (Tile* tile : this->tiles)
	{
		if (maxX < (tile->getTexture()->asset->getWidth() + tile->getCurrentPosition().x))
			maxX = (tile->getTexture()->asset->getWidth() + tile->getCurrentPosition().x);
		if (maxY < (tile->getTexture()->asset->getHeight() + tile->getCurrentPosition().y))
			maxY = (tile->getTexture()->asset->getHeight() + tile->getCurrentPosition().y);
	}
	this->mapMaxSize = { maxX, maxY };
}

void			Map::doActionQueue()
{

	for (auto object : this->objects)
	{
		if (object != nullptr)
			object->doAction();
	}


}

void			Map::generateMaps()
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

bool			Map::getCollision(Position posA, Position posB)
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

Position	Map::tryMove(Object* object, Position targetPosition)
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
					iterationPosition = { iterationPosition.x - 1, iterationPosition.y };
				else
					iterationPosition = { iterationPosition.x + 1, iterationPosition.y };
			}

			//	Adjust y axis depending on positive or negative value
			if (moveY && ((!negY && i < targetPosition.y) || (negY && i > targetPosition.y)))
			{

				if (negY)
					iterationPosition = { iterationPosition.x, iterationPosition.y - 1 };
				else
					iterationPosition = { iterationPosition.x, iterationPosition.y + 1 };
			}

			object->setCurrentPosition(iterationPosition);

			//	Declare vector for tiles to be checked
			std::vector<Tile*>	tiles;

			//	Create vector with tiles from all corners of object
			tiles.push_back(this->getTile(iterationPosition));	//	Top left
			tiles.push_back(this->getTile({ iterationPosition.x + width - 1, iterationPosition.y })); // Top right
			tiles.push_back(this->getTile({ iterationPosition.x, iterationPosition.y + height - 1 })); // Bottom left
			tiles.push_back(this->getTile({ iterationPosition.x + width - 1, iterationPosition.y + height - 1 })); // Bottom right

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