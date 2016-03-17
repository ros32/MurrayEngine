#ifndef _MAP_H
#define _MAP_H

#define	DEFAULT_GRID_SIZE	256

#include <vector>
#include <map>
#include "Configuration.h"
#include "Tile.h"
#include "Camera.h"
#include "AnimatedObject.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The Map class contains all tiles and objects displayed on the screen.
/// 			
/// 			The Map class also contains the Camera class that control's what is rendered.  </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class Map
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="window">  	[in,out] If non-null, the window. </param>
	/// <param name="renderer">	[in,out] If non-null, the renderer. </param>
	///-------------------------------------------------------------------------------------------------
	Map(SDL_Window* window, SDL_Renderer* renderer);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~Map();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Return all objects on a given position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///
	/// <returns>	null if it fails, else the object. </returns>
	///-------------------------------------------------------------------------------------------------
	std::vector<Object*>	getObject(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets an object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="posa">	The posa. </param>
	/// <param name="posB">	The position b. </param>
	///
	/// <returns>	null if it fails, else the object. </returns>
	///-------------------------------------------------------------------------------------------------
	std::vector<Object*>	getObject(Position posa, Position posB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets object by identifier. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="id">	The identifier. </param>
	///
	/// <returns>	null if it fails, else the object by identifier. </returns>
	///-------------------------------------------------------------------------------------------------
	Object*					getObjectById(std::string id);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Return the Tile on a given position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///
	/// <returns>	null if it fails, else the tile. </returns>
	///-------------------------------------------------------------------------------------------------
	Tile*						getTile(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the tiles. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="posA">	The position a. </param>
	/// <param name="posB">	The position b. </param>
	///
	/// <returns>	null if it fails, else the tiles. </returns>
	///-------------------------------------------------------------------------------------------------
	std::vector<Tile*>			getTiles(Position posA, Position posB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Render all visible components in the Map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void						render();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Set matrix of tiles in Map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="tiles">	[in,out] If non-null, the tiles. </param>
	///-------------------------------------------------------------------------------------------------
	void						setTiles(std::vector<Tile*> tiles);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Set array of objects in Map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="objects">	[in,out] If non-null, the objects. </param>
	///-------------------------------------------------------------------------------------------------
	void						setObjects(std::vector<Object*> objects);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Add an object to the Map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="object">	[in,out] If non-null, the object. </param>
	///-------------------------------------------------------------------------------------------------
	void						addObject(Object* object);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Remove specified object from Map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="object">	[in,out] If non-null, the object. </param>
	///-------------------------------------------------------------------------------------------------
	void						removeObject(Object* object);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Moves this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void						move();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the camera. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the camera. </returns>
	///-------------------------------------------------------------------------------------------------
	Camera*						getCamera();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a camera. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="camera">	[in,out] If non-null, the camera. </param>
	///-------------------------------------------------------------------------------------------------
	void						setCamera(Camera* camera);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets player character. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the player character. </returns>
	///-------------------------------------------------------------------------------------------------
	Object*						getPlayerCharacter();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets player character. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="playerCharacter">	[in,out] If non-null, the player character. </param>
	///-------------------------------------------------------------------------------------------------
	void						setPlayerCharacter(Object* playerCharacter);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets map maximum size. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The map maximum size. </returns>
	///-------------------------------------------------------------------------------------------------
	Position					getMapMaxSize();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets tile size. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The tile size. </returns>
	///-------------------------------------------------------------------------------------------------
	int							getTileSize();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets tile size. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="tileSize">	Size of the tile. </param>
	///-------------------------------------------------------------------------------------------------
	void						setTileSize(int tileSize);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the action queue operation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void						doActionQueue();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets a collision. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="posA">	The position a. </param>
	/// <param name="posB">	The position b. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool						getCollision(Position posA, Position posB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets a passable. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="posA">	The position a. </param>
	/// <param name="posB">	The position b. </param>
	///-------------------------------------------------------------------------------------------------
	void						getPassable(Position posA, Position posB);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Try move. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="object">			 	[in,out] If non-null, the object. </param>
	/// <param name="targetPosition">	 	Target position. </param>
	/// <param name="onlyCheckCollision">	true to only check collision. </param>
	///
	/// <returns>	A Position. </returns>
	///-------------------------------------------------------------------------------------------------
	Position					tryMove(Object* object, Position targetPosition, bool onlyCheckCollision);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Calculates the map maximum size. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="tiles">	[in,out] If non-null, the tiles. </param>
	///-------------------------------------------------------------------------------------------------
	void						calculateMapMaxSize(std::vector<Tile*> tiles);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Return the closest position the targetPosition that the object can travel to
	/// 			without collision. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="object">		   	[in,out] If non-null, the object. </param>
	/// <param name="targetPosition">  	Target position. </param>
	/// <param name="relativePosition">	true to relative position. </param>
	/// <param name="movement">		   	The movement. </param>
	/// <param name="padding">		   	The padding. </param>
	/// <param name="multiAxis">	   	true to multi axis. </param>
	///
	/// <returns>	A Position. </returns>
	///-------------------------------------------------------------------------------------------------
	Position					tryMove(Object* object, Position targetPosition, bool relativePosition, int movement, int padding, bool multiAxis);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Determine if we can move. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="object">   	[in,out] If non-null, the object. </param>
	/// <param name="direction">	The direction. </param>
	///
	/// <returns>	true if we can move, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
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
