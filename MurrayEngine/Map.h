#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include <map>
#include "Configuration.h"
#include "GenericObject.h"
#include "Position.h"
#include "Tile.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include "Camera.h"
#include "AnimatedObject.h"

class Map
{
public:
	Map();
	Map(SDL_Window* window, SDL_Renderer* renderer);
	~Map();

	///	<summary>
	///	Return all objects on a given position
	///	</summary>
	std::vector<GenericObject*>	getObject(Position pos);

	///	<summary>
	///	Return the Tile on a given position
	///	</summary>
	Tile						getTile(Position pos);

	///	<summary>
	///	Render all visible components in the Map
	///	</summary>
	void						render();

	///	<summary>
	///	Set matrix of tiles in Map
	///	</summary>
	void						setTiles(std::vector<std::vector<Tile>> tiles);

	///	<summary>
	///	Set array of objects in Map
	///	</summary>
	void						setObjects(std::vector<GenericObject*> objects);

	///	<summary>
	///	Add an object to the Map
	///	</summary>
	void						addObject(GenericObject* object);

	///	<summary>
	///	Remove specified object from Map
	///	</summary>
	void						removeObject(GenericObject* object);

	void						move();

	Camera*						getCamera();

	void						setCamera(Camera* camera);

	GenericObject*				getPlayerCharacter();
	void						setPlayerCharacter(GenericObject* playerCharacter);

	Position					getMapMaxSize();

	int							getTileSize();
	void						setTileSize(int tileSize);


private:

	int tileSize;

	Camera*											camera;

	std::vector<std::vector<Tile>>					tiles;
	std::vector<GenericObject*>						objects;
	std::vector <GenericObject>						tempVector;

	GenericObject*									playerCharacter;


};

#endif // !_MAP_H
