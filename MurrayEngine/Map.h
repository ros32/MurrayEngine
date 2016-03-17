#ifndef _MAP_H
#define _MAP_H

#define	DEFAULT_GRID_SIZE	256

#include <vector>
#include <map>
#include "Configuration.h"
#include "Tile.h"
#include "Camera.h"
#include "AnimatedObject.h"

class Map
{
public:
	Map(SDL_Window* window, SDL_Renderer* renderer);
	~Map();

	///	<summary>
	///	Return all objects on a given position
	///	</summary>
	std::vector<Object*>	getObject(Position pos);
	std::vector<Object*>	getObject(Position posa, Position posB);

	Object*					getObjectById(std::string id);

	///	<summary>
	///	Return the Tile on a given position
	///	</summary>
	Tile*						getTile(Position pos);

	std::vector<Tile*>			getTiles(Position posA, Position posB);

	///	<summary>
	///	Render all visible components in the Map
	///	</summary>
	void						render();

	///	<summary>
	///	Set matrix of tiles in Map
	///	</summary>
	void						setTiles(std::vector<Tile*> tiles);

	///	<summary>
	///	Set array of objects in Map
	///	</summary>
	void						setObjects(std::vector<Object*> objects);

	///	<summary>
	///	Add an object to the Map
	///	</summary>
	void						addObject(Object* object);

	///	<summary>
	///	Remove specified object from Map
	///	</summary>
	void						removeObject(Object* object);

	void						move();

	Camera*						getCamera();

	void						setCamera(Camera* camera);

	Object*						getPlayerCharacter();
	void						setPlayerCharacter(Object* playerCharacter);

	Position					getMapMaxSize();

	int							getTileSize();
	void						setTileSize(int tileSize);

	void						doActionQueue();

	bool						getCollision(Position posA, Position posB);
	void						getPassable(Position posA, Position posB);

	Position					tryMove(Object* object, Position targetPosition, bool onlyCheckCollision);
	void						calculateMapMaxSize(std::vector<Tile*> tiles);

	//	Return the closest position the targetPosition that the object can travel to without collision
	Position					tryMove(Object* object, Position targetPosition, bool relativePosition, int movement, int padding, bool multiAxis);
	bool						canMove(Object* object, Orientation direction);



private:

	int tileSize;

	Camera*						camera;

	std::vector<Tile*>			tiles;
	std::vector<Object*>		objects;
	std::vector <Object>		tempVector;

	Object*						playerCharacter;

	std::vector<std::vector<bool>>		collisionMap;
	std::vector<std::vector<bool>>		passableMap;

	void								generateMaps();
	Position							mapMaxSize;
	std::map<Position, std::map<Position, Tile*> >	tileGrid;
	int									gridSize;

	void								createGrid(std::vector<Tile*>);
	
};

#endif // !_MAP_H
