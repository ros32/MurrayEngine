#include "Map.h"




Map::Map()
{
	this->tileSize;
	this->camera;
	this->tiles;
	this->objects;
}

Map::~Map()
{

}


std::vector<GenericObject*>	Map::getObject(Position pos)
{
	
	std::vector<GenericObject*> tempVector;

	for (auto object : objects){
	//	if (object->getCurrentPosition() == pos);
	//	tempVector.push_back(object);
	}

	return tempVector;
}



Tile Map::getTile(Position pos)
{
	std::vector <std::vector<Tile>>::iterator row;
	std::vector<Tile>::iterator column;

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


void render(SDL_Renderer* renderer)
{

}

void Map::setTiles(std::vector<std::vector<Tile>> tiles)
{
		this->tiles = tiles;
}

void Map::setObjects(std::vector<GenericObject*> objects)
{
		this->objects = objects;
}

void Map::addObject(GenericObject* object)
{	
		objects.push_back(object);
}

void Map::removeObject(GenericObject* object)
{

//	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());

	for (int i = objects.size()-1; i >= 0; i--){
		if (objects[i] == object)
			objects.erase(objects.begin()+1);

	}

}

