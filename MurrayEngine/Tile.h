#ifndef _TILE_H
#define _TILE_H

#include	"Object.h"

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
