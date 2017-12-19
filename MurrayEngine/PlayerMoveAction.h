#ifndef _PLAYER_MOVE_ACTION_H
#define	_PLAYER_MOVE_ACTION_H

#include	<string>
#include	"GameInstance.h"
#include	"Action.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A PlayerMoveAction is an implementation of Action that allows the player to move
/// 			
/// 			When executed, it will identify the player character in the current map and move
/// 			it accordingly
/// 			
/// 			The PlayerMoveAction has to be used instead of MoveAction from KeyController to
/// 			avoid pointer issues (MoveAction uses pointers, but when maps are loaded and unloaded
/// 			these pointers disappear). </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class PlayerMoveAction: public Action
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="id">		   	The identifier. </param>
	/// <param name="gameInstance">	[in,out] If non-null, the game instance. </param>
	/// <param name="direction">   	The direction. </param>
	///-------------------------------------------------------------------------------------------------
	PlayerMoveAction(std::string id, GameInstance* gameInstance, Orientation direction);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="id">		   	The identifier. </param>
	/// <param name="gameInstance">	[in,out] If non-null, the game instance. </param>
	/// <param name="direction">   	The direction. </param>
	/// <param name="repeat">	   	The repeat. </param>
	///-------------------------------------------------------------------------------------------------
	PlayerMoveAction(std::string id, GameInstance* gameInstance, Orientation direction, int repeat);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~PlayerMoveAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	execute() override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Copies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else an Action*. </returns>
	///-------------------------------------------------------------------------------------------------
	Action*	copy() override;

private:

	std::string		source;
	GameInstance*	gameInstance;
	Orientation		direction;

	int repeat;
	int currentRepeat;


};

#endif // !_PLAYER_MOVE_ACTION_H
