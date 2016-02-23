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

		int height = object->getTexture().asset->getHeight();
		int width = object->getTexture().asset->getWidth();

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

		if (tile != nullptr && tile->getTexture().asset != nullptr &&
			tile->getCurrentPosition().x >= pos.x && tile->getCurrentPosition().x <= pos.x + tile->getTexture().asset->getWidth() &&
			tile->getCurrentPosition().y >= pos.y && tile->getCurrentPosition().y <= pos.y + tile->getTexture().asset->getHeight())
			return tile;
			}

		}
	
void Map::render()
{

	//	Render tiles
	for (auto object : this->tiles)
	{
		if ((object->getCurrentPosition().x >= (this->camera->getPosition().x - object->getTexture().asset->getCellSize()) && object->getCurrentPosition().x <= (this->camera->getPosition().x + this->camera->getWidth() + object->getTexture().asset->getCellSize())) &&
			(object->getCurrentPosition().y >= (this->camera->getPosition().y - object->getTexture().asset->getCellSize()) && object->getCurrentPosition().y <= (this->camera->getPosition().y + this->camera->getHeight() + object->getTexture().asset->getCellSize())))
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
		if ((object->getCurrentPosition().x >= (this->camera->getPosition().x - object->getTexture().asset->getCellSize()) && object->getCurrentPosition().x <= (this->camera->getPosition().x + this->camera->getWidth() + object->getTexture().asset->getCellSize())) &&
			(object->getCurrentPosition().y >= (this->camera->getPosition().y - object->getTexture().asset->getCellSize()) && object->getCurrentPosition().y <= (this->camera->getPosition().y + this->camera->getHeight() + object->getTexture().asset->getCellSize())))
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
		this->generateMaps();
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
	for (auto object : objects)
	{
		if ((object->getTargetPosition().x != 0) || (object->getTargetPosition().y != 0))
		{
			object->move();

			if (object->getIsCollidable())
			{
				if (this->getCollision(object->getCurrentPosition(), { object->getCurrentPosition().x + object->getTexture().asset->getWidth(), object->getCurrentPosition().y + object->getTexture().asset->getHeight() }))
				{
					while (this->getCollision(object->getCurrentPosition(), { object->getCurrentPosition().x + object->getTexture().asset->getWidth(), object->getCurrentPosition().y + object->getTexture().asset->getHeight() }))
					{
						object->reverseMove();
					}
				}
				else
				{
					for (auto otherObject : objects)
					{
						if (otherObject->getId() != object->getId() && otherObject->getIsCollidable())
						{

							collisionEvent = new CollisionEvent(object, otherObject);

							while (collisionEvent->collidePixel()){
								object->reverseMove();
							}

							delete(collisionEvent);

						}
					}
				}
			}

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

Position		Map::getMapMaxSize()
{
	int maxX = 0;
	int maxY = 0;
	for (Tile* tile : this->tiles)
	{
		if (maxX < (tile->getTexture().asset->getWidth() + tile->getCurrentPosition().x))
			maxX = (tile->getTexture().asset->getWidth() + tile->getCurrentPosition().x);
		if (maxY < (tile->getTexture().asset->getHeight() + tile->getCurrentPosition().y))
			maxY = (tile->getTexture().asset->getHeight() + tile->getCurrentPosition().y);
	}
	return { maxX, maxY };
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