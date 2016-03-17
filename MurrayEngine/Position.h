#ifndef _POSITION_H
#define	_POSITION_H

#include	<tuple>

///-------------------------------------------------------------------------------------------------
/// <summary>	The Position struct is a representation of a point in a 2D plane. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
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
