#ifndef _TILE_H
#define _TILE_H

#include	"Object.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The Tile class is the basic component of Maps.
/// 			
/// 			Each Tile represent a geographical location on the map. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class Tile: public Object
{
public:
	Tile(Position currentPosition, std::shared_ptr<Texture> texture, Orientation orientation, bool collidable, bool passable);
	~Tile();

	Position	getCurrentPosition();
	void		setCurrentPosition(Position pos);
	bool		getIsCollidable();
	void render(int x, int y);

private:

	static int counter;
	static std::string getNextId();


};

#endif // !_TILE_H
