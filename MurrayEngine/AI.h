#ifndef _AI_H
#define	_AI_H

#include	"Map.h"
#include	"NonPlayerCharacter.h"

class NonPlayerCharacter;

///-------------------------------------------------------------------------------------------------
/// <summary> An AI (or Artificial Intelligence) is the decision-making interface for a 
/// 		  NonPlayerCharacter. A NonPlayerCharacter will query the AI for a new command 
/// 		  each time the action queue is processed, and the AI will, through AI::doNext() 
/// 		  (and implementation), provide the NonPlayerCharacter with actions 
/// 		  to perform. </summary>
///
/// <remarks> Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class AI
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	AI();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="npc">	[in,out] If non-null, the npc. </param>
	/// <param name="map">	[in,out] If non-null, the map. </param>
	///-------------------------------------------------------------------------------------------------
	AI(NonPlayerCharacter* npc, Map* map);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~AI() = 0;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the next operation. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual void		doNext() = 0;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets source npc. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="npc">	[in,out] If non-null, the npc. </param>
	///-------------------------------------------------------------------------------------------------
	void				setSourceNPC(NonPlayerCharacter* npc);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets source npc. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	null if it fails, else the source npc. </returns>
	///-------------------------------------------------------------------------------------------------
	NonPlayerCharacter*				getSourceNPC() const;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a map. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="map">	[in,out] If non-null, the map. </param>
	///-------------------------------------------------------------------------------------------------
	void				setMap(Map* map);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the map. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	null if it fails, else the map. </returns>
	///-------------------------------------------------------------------------------------------------
	Map*				getMap() const;

private:

	/// <summary>	The npc. </summary>
	NonPlayerCharacter*				npc;

	/// <summary>	The map. </summary>
	Map*				map;

};

#endif // !_AI_HJ
