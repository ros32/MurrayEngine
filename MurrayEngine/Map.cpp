#include "Map.h"




Map::Map()
{
	this->tileSize;
	this->camera;
	this->tiles;
	this->objects;

}

Map::Map(SDL_Window* window, SDL_Renderer* renderer)
{
	this->tileSize;
	this->camera = Camera(window);
	this->tiles;
	this->objects;
	
}

Map::~Map()
{

}


std::vector<GenericObject>	Map::getObject(Position pos)
{
	
	std::vector<GenericObject> tempVector;

	for (auto object : objects){


	//	if (object->getCurrentPosition() == pos);
	//	tempVector.push_back(object);
	}

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

	//	Render objects
	for (auto vectorX : this->tiles)
	{
		for (auto object : vectorX)
		{

			if ((object.getCurrentPosition().x >= (this->camera.getPosition().x - object.getTexture()->getCellSize()) && object.getCurrentPosition().x <= (this->camera.getPosition().x + this->camera.getWidth() + object.getTexture()->getCellSize())) &&
				(object.getCurrentPosition().y >= (this->camera.getPosition().y - object.getTexture()->getCellSize()) && object.getCurrentPosition().y <= (this->camera.getPosition().y + this->camera.getHeight() + object.getTexture()->getCellSize())))
			{
				//	Object is within camera view

				//	Render object with camera offset
				object.render(object.getCurrentPosition().x - this->camera.getPosition().x, object.getCurrentPosition().y - this->camera.getPosition().y);
			}

		}
	}

	//	Render objects
	for (auto object : this->objects)
	{
		//	TODO: Optimize this
		if ((object.getCurrentPosition().x >= (this->camera.getPosition().x - object.getTexture()->getCellSize()) && object.getCurrentPosition().x <= (this->camera.getPosition().x + this->camera.getWidth() + object.getTexture()->getCellSize())) &&
			(object.getCurrentPosition().y >= (this->camera.getPosition().y - object.getTexture()->getCellSize()) && object.getCurrentPosition().y <= (this->camera.getPosition().y + this->camera.getHeight() + object.getTexture()->getCellSize())))
		{
			//	Object is within camera view

			//	Render object with camera offset
			object.render(object.getCurrentPosition().x - this->camera.getPosition().x, object.getCurrentPosition().y - this->camera.getPosition().x);
		}
	}

}

void Map::setTiles(std::vector<std::vector<Tile>> tiles)
{
		this->tiles = tiles;
}

void Map::setObjects(std::vector<GenericObject> objects)
{
		this->objects = objects;
}

void Map::addObject(GenericObject object)
{	
		objects.push_back(object);
}

void Map::removeObject(GenericObject object)
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
	
	for (auto genericObject : objects)
	{
		if ((genericObject.getTargetPosition().x != 0) || (genericObject.getTargetPosition().y != 0))
		{

			 genericObject.move();

			 if (genericObject.getHasCollision())
			 {

				for (auto otherObject : objects)
				{

					if (otherObject.getId() != genericObject.getId())
					{
						
						if (genericObject.collidePixel(otherObject))
						{

							genericObject.reverseMove();
							// genericObject.do (new CollisionAction (otherObject));
							//genericObject.bounce (otherObject);
						}
						
					}
				}
			}
		}

		genericObject.render(genericObject.getCurrentPosition().x, genericObject.getCurrentPosition().y);
	}
	

}
	

Camera*		Map::getCamera()
{
	return &this->camera;
}


