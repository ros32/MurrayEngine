#ifndef _CHANGE_MAP_ACTION
#define	_CHANGE_MAP_ACTION

#include	<string>
#include	"Action.h"
#include	"GameInstance.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The ChangeMapAction is an Action used to change the current loaded Map.
/// 			
/// 			When executed, the ChangeMapAction will try to load the (in the constructor) defined
/// 			map. If the map is not found, nothing will happen. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class ChangeMapAction: public Action
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="gameInstance">	[in,out] If non-null, the game instance. </param>
	/// <param name="mapName">	   	Name of the map. </param>
	///-------------------------------------------------------------------------------------------------
	ChangeMapAction(GameInstance* gameInstance, std::string mapName);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~ChangeMapAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void execute() override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Copies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else an Action*. </returns>
	///-------------------------------------------------------------------------------------------------
	Action* copy() override;

private:

	/// <summary>	The game instance. </summary>
	GameInstance*	gameInstance;
	/// <summary>	Name of the map. </summary>
	std::string		mapName;

};

#endif // !_CHANGE_MAP_ACTION
