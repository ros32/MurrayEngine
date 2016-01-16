#ifndef _POSITION_H
#define	_POSITION_H

struct Position
{
	int x;
	int y;

	//	Needed to be key in map
	bool operator<(const Position& pos) const
	{
		return (this->x < pos.x && this->y < pos.y);
	}
};

#endif // !_POSITION_H
