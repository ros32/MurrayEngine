#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include <map>
#include "Configuration.h"
#include "GenericObject.h"
#include "Position.h"
#include "Tile.h"
#include "Viewport.h"

class Map
{
public:
	Map();
	~Map();

	///	<summary>
	///	Return all objects on a given position
	///	</summary>
	std::vector<GenericObject*>	getObject(Position pos);

	///	<summary>
	///	Return the Tile on a given position
	///	</summary>
	Tile						getTile(Position pos);

	void						render(SDL_Renderer* renderer);

	void						setTiles(std::vector<std::vector<Tile>> tiles);

	void						setObjects(std::vector<GenericObject> objects);

	void						addObject(GenericObject object);

	void						removeObject(GenericObject object);

private:
	Map();

	int tileSize;

	Viewport viewport;


	std::vector<std::vector<Tile>>					tiles;
	std::vector<GenericObject>						objects;


};

#endif // !_MAP_H
