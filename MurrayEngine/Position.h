#ifndef _POSITION_H
#define	_POSITION_H

#include	<tuple>

struct Position
{
	int x;
	int y;

	//	Needed to be key in map
	bool operator<(const Position& pos) const
	{
		return (std::tie(x, y) < std::tie(pos.x, pos.y));
	}

	bool operator>(const Position& pos) const
	{
		return (std::tie(x, y) > std::tie(pos.x, pos.y));
	}

	bool operator<=(const Position& pos) const
	{
		return (std::tie(x, y) < std::tie(pos.x, pos.y) || (std::tie(x, y) == std::tie(pos.x, pos.y)));
	}

	bool operator>=(const Position& pos) const
	{
		return (std::tie(x, y) > std::tie(pos.x, pos.y) || (std::tie(x, y) == std::tie(pos.x, pos.y)));
	}

	bool operator==(const Position& pos) const
	{
		return (std::tie(x, y) == std::tie(pos.x, pos.y));
	}

	bool operator!=(const Position& pos) const
	{
		return (std::tie(x, y) != std::tie(pos.x, pos.y));
	}
};

#endif // !_POSITION_H
