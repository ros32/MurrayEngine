/*
The concrete action MoveAction
Triggers the movements of all movable objects
*/

#ifndef _MOVEACTION_H
#define _MOVEACTION_H

#include "Action.h"
#include "Object.h"
#include "Map.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include "Camera.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A move action. </summary>
///
/// <remarks>	Rosen, 2016-02-29. </remarks>
///-------------------------------------------------------------------------------------------------
class MoveAction : public Action{

public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///
	/// <param name="source">   	[in,out] If non-null, source for the. </param>
	/// <param name="map">			[in,out] If non-null, the map. </param>
	/// <param name="direction">	The direction. </param>
	///-------------------------------------------------------------------------------------------------
	MoveAction(Object* source, Map* map, Orientation direction);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///
	/// <param name="source">   	[in,out] If non-null, source for the. </param>
	/// <param name="map">			[in,out] If non-null, the map. </param>
	/// <param name="direction">	The direction. </param>
	/// <param name="repeat">   	The repeat. </param>
	///-------------------------------------------------------------------------------------------------
	MoveAction(Object* source, Map* map, Orientation direction, int repeat);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///-------------------------------------------------------------------------------------------------
	~MoveAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///-------------------------------------------------------------------------------------------------
	void execute();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Copies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///
	/// <returns>	null if it fails, else an Action*. </returns>
	///-------------------------------------------------------------------------------------------------
	Action*	copy();

private:

	/// <summary>	The repeat. </summary>
	int repeat;

	/// <summary>	The current repeat. </summary>
	int currentRepeat;

	/// <summary>	Source for the. </summary>
	Object* source;

	/// <summary>	The map. </summary>
	Map* map;

	/// <summary>	The direction. </summary>
	Orientation direction = NONE;
};




#endif //!_MOVEACTION_H