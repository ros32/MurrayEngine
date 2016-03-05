#ifndef _DEFAULT_AI_H
#define	_DEFAULT_AI_H

#include <stdlib.h>
#include <ctime>
#include "AI.h"
#include "MoveAction.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A default ai. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class DefaultAI: public AI
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	DefaultAI();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="npc">	[in,out] If non-null, the npc. </param>
	/// <param name="map">	[in,out] If non-null, the map. </param>
	///-------------------------------------------------------------------------------------------------
	DefaultAI(NonPlayerCharacter* npc, Map* map);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~DefaultAI();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the next operation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	doNext();

private:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets valid directions. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The valid directions. </returns>
	///-------------------------------------------------------------------------------------------------
	std::vector<Orientation>	getValidDirections();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets opposite direction. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="direction">	The direction. </param>
	///
	/// <returns>	The opposite direction. </returns>
	///-------------------------------------------------------------------------------------------------
	Orientation		getOppositeDirection(Orientation direction);

	/// <summary>	The current action. </summary>
	Action*		currentAction;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Moves this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	move();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Searches for the first player. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="orientation">	The orientation. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool	findPlayer(Orientation orientation);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Determine if we can see player. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	true if we can see player, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool	canSeePlayer();

	/// <summary>	The last move position. </summary>
	Position	lastMovePosition;

	/// <summary>	true if the last move operation was a success, false if it failed. </summary>
	bool		lastMoveSuccess;

	/// <summary>	The player last seen direction. </summary>
	Orientation	playerLastSeenDirection;

	/// <summary>	true to player recently seen. </summary>
	bool		playerRecentlySeen;

};

#endif // !_DEFAULT_AI_H
