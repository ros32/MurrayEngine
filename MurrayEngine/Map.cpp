#include "Map.h"


Map::Map()
{
	this->tileSize;
	this->camera = new Camera();
	this->tiles;
	this->objects;

}

Map::Map(SDL_Window* window, SDL_Renderer* renderer)
{
	this->tileSize;
	this->camera = new Camera(window);
	this->tiles;
	this->objects;
	
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

Tile Map::getTile(Position pos)
{
//	std::vector <std::vector<Tile>>::iterator row;
//	std::vector<Tile>::iterator column;

	int posX = pos.x;
	int posY = pos.y;

	return tiles[posX][posY];

	/*
	for (int row = 0; row <= tiles.size() - 1; row++){
		if (row == posX){
			for (int column = 0; column <= tiles.size() - 1; column++){
				if (column == posY);
				return tiles[row][column];
			}
		}		
	}
	*/

	/*
	for (row = tiles.begin(); row != tiles.end(); row++){
		 for (column = row->begin(); column != row->end(); column++){
		}
	}
	*/
	
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
	for (auto Object : objects)
	{
		if ((Object->getTargetPosition().x != 0) || (Object->getTargetPosition().y != 0))
		{
			 Object->move();			 

			 if (Object->getIsCollidable())
			 {
				for (auto otherObject : objects)
				{
					if (otherObject->getId() != Object->getId() && otherObject->getIsCollidable())
					{
					
						collisionEvent = new CollisionEvent(Object, otherObject);

						while (collisionEvent->collidePixel()){
								Object->reverseMove();
						}
						
						delete(collisionEvent);

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
			maxX = (tile->getTexture().asset->getHeight() + tile->getCurrentPosition().y);
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


